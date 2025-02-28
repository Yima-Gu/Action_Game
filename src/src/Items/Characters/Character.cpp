//
// @brief: 游戏中人物行为的实现，主要包括运动、捡拾、攻击
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "Character.h"
#include "../Weapon/Arrow/NormalArrow.h"
#include "../Weapon/Arrow/FireArrow.h"
#include "../Weapon/Arrow/FrozenArrow.h"
#include "../Weapon/Arrow/ThunderArrow.h"

#include <QTransform>
#include <QGraphicsScene>
#include <QDebug>

//构造函数，链接信号和槽，创建血量条
Character::Character(QGraphicsItem *parent,const QString &pixmapPath) : Item(parent, pixmapPath),velocity(0,0),healthBar(new QGraphicsRectItem(this))
{

    fireTimer=new QTimer(this);
    connect (fireTimer, &QTimer::timeout, this, &Character::processFire);
    frozenTimer =new QTimer(this);
    connect (frozenTimer, &QTimer::timeout, this, &Character::unfreeze);
    struckTimer =new QTimer(this);
    connect (struckTimer, &QTimer::timeout, this, &Character::processStruck);
    connect (this, &Character::beAttacked, this, &Character::unfreeze);


    healthBar->setRect(0, 0, width, 5);
    healthBar->setBrush(Qt::red);
    statusBar =new StatusBar();
    statusBar->setScale(0.5);
    statusBar->setParentItem(this->parentItem());
    statusBar->setOwner(this);
}

//人物按键状态的setter和getter方法
bool Character::isLeftDown() const
{
    return leftDown;
}

void Character::setLeftDown(bool leftDown)
{
    Character::leftDown = leftDown;
}

bool Character::isRightDown() const
{
    return rightDown;
}

void Character::setRightDown(bool rightDown)
{
    Character::rightDown = rightDown;
}

bool Character::isUpDown() const
{

    return upDown;
}

void Character::setUpDown(bool upDown)
{
    Character::upDown=upDown;
}

bool Character::isPickDown() const
{
    return pickDown;
}

bool Character::isPicking() const
{
    return picking;
}

void Character::setPickDown(bool pickDown)
{
    Character::pickDown = pickDown;
}

const QPointF &Character::getVelocity() const
{
    return velocity;
}

void Character::setVelocity(const QPointF &velocity)
{
    Character::velocity = velocity;
}


//处理人物的输入逻辑的函数，包括人物移动受击和状态更新
void Character::processInput()
{
    const auto jumpSpeed = -2;
    const auto moveSpeed = 0.3;
    if (isLeftDown())
    {
        velocity.setX(-moveSpeed); // 向左移动
        setTransform(QTransform().scale(1, 1));
    }
    else if (isRightDown())
    {
        velocity.setX(moveSpeed);
        setTransform(QTransform().scale(-1, 1));
    }
    else
    {
        velocity.setX(0);
    }

    if (frozen)
    {
        velocity.setX(0);
    }

    if (isUpDown() && isOnGround() &&!frozen)
    { // 如果按下跳跃键且在地面上
        velocity.setY(jumpSpeed); // 设定向上的初始速度
        onGround = false; // 设定角色不在地面上
    }

    //更新人物状态的方法
    updateHealthBar();
    updateGroundStatus();
    applyGravity();
    handleCollision();
    update();
    checkOnFire();
    if (statusBar!=nullptr)
    {
        statusBar->update();
    }

    if (!lastPickDown && pickDown &&!frozen)
    { // 如果拾取键第一次按下
        picking = true;              // 设定拾取状态为 true
    } else
    {
        picking = false;             // 否则，拾取状态为 false
    }
    lastPickDown = pickDown;        // 更新上一次拾取键状态

    //输出人物的位置，用于debug
    //ensureInBounds();
}

//人物捡起不同物品的实现函数
IceProofArmor* Character::pickupArmor(IceProofArmor* newArmor)
{
    auto oldArmor = iceProofArmor;   // 存储当前的护甲
    if (oldArmor != nullptr)
    {
        oldArmor->unmount(); // 卸载当前护甲
        oldArmor->setPos(newArmor->pos()); // 将当前护甲移动到新护甲的位置
        oldArmor->setParentItem(parentItem()); // 设置当前护甲的父项
    }
    newArmor->setParentItem(this); // 设置新护甲的父项为角色
    newArmor->mountToParent();     // 将新护甲安装到角色上
    iceProofArmor = newArmor;              // 更新角色的当前护甲
    return oldArmor;
}

HeadEquipment* Character::pickupHelmet(HeadEquipment* newHelmet)
{
    auto oldHelmet = headEquipment;
    if (oldHelmet!=nullptr)
    {
        oldHelmet->unmount();
        oldHelmet->setPos(newHelmet->pos());
        oldHelmet->setParentItem(parentItem());
    }
    newHelmet->setParentItem(this);
    newHelmet->mountToParent();
    headEquipment=newHelmet;
    return oldHelmet;
}

LegEquipment* Character::pickupShoes(LegEquipment* newShoes)
{
    auto oldShoes = legEquipment;
    if (oldShoes!=nullptr)
    {
        oldShoes->unmount();
        oldShoes->setPos(newShoes->pos());
        oldShoes->setParentItem(parentItem());
    }
    newShoes->setParentItem(this);
    newShoes->mountToParent();
    legEquipment=newShoes;
    return oldShoes;
}

Weapon *Character::pickupWeapon(Weapon *newWeapon)
{
    auto oldWeapon=weapon;
    if (oldWeapon!=nullptr)
    {
        oldWeapon->setOpacity(1);
        oldWeapon->unmount();
        oldWeapon->setParentItem(parentItem());
        QPointF tempPos=this->pos();
        tempPos.setY(tempPos.y()-70);
        oldWeapon->setPos(tempPos);
    }
    newWeapon->setParentItem(this);
    newWeapon->mountToParent();
    weapon=newWeapon;
    this->setMode(1);
    return oldWeapon;
}

Bow* Character::pickupBow(Bow* newBow)
{
    auto oldBow=bow;
    if (oldBow!=nullptr)
    {
        oldBow->setOpacity(1);
        oldBow->unmount();
        oldBow->setParentItem(parentItem());
        QPointF tempPos=this->pos();
        tempPos.setY(tempPos.y()-70);
        oldBow->setPos(tempPos);
    }
    newBow->setParentItem(this);
    newBow->mountToParent();
    bow=newBow;
    this->setMode(2);
    return oldBow;
}

SpareArrow* Character::pickupArrow(SpareArrow* newSpareArrow)
{
    numArrows[newSpareArrow->getType()]+=5;
    haveArrow=true;
    this->arrowType= newSpareArrow->getType();

    if (newSpareArrow!=nullptr)
    {
        delete newSpareArrow;
    }
    return nullptr;
}

//与人物重力相关的方法，包括根据重力更新位置，检查是否和平台碰撞，更新“在地上”的状态
void Character::applyGravity()
{
    if (!isOnGround())
    {
        velocity.setY(velocity.y() + gravity * 0.1); // 模拟重力影响，0.1 是时间步长，可以调整
    }
    else
    {
        velocity.setY(0); // 在地面上时，垂直速度为 0
    }
}

void Character::handleCollision()
{
    // 获取角色的边界矩形，并转换为全局坐标
    QRectF characterRect = mapRectToScene(boundingRect());

    for (QGraphicsItem *item : scene()->items())
    {
        if (auto platform = dynamic_cast<Platform*>(item))
        {
            // 获取平台的边界矩形，并转换为全局坐标
            QRectF platformRect = platform->mapRectToScene(platform->boundingRect());

            // 检测角色与平台是否发生碰撞
            if (characterRect.intersects(platformRect))
            {
                // 处理碰撞
                onCollisionWithPlatform(platform);
            }
        }
    }
}

void Character::onCollisionWithPlatform(Platform *platform)
{
    // 仅在角色正在向下移动时处理
    if (velocity.y() > 0)
    {

        // 获取角色的边界矩形，并转换为全局坐标
        QRectF characterRect = mapRectToScene(boundingRect());

        // 获取平台的边界矩形，并转换为全局坐标
        QRectF platformRect = platform->mapRectToScene(platform->boundingRect());


        // 检查角色的底部是否与平台的顶部重叠
        if (characterRect.bottom() >= platformRect.top()
            &&characterRect.bottom()<=platformRect.bottom())
        {
            // 设置角色的垂直速度为0
            velocity.setY(0);
            // 更新角色的“在地面上”状态
            setOnGround(true);
        }
    }
}

void Character::setOnGround(bool onGround)
{
    Character::onGround=onGround;
}

void Character::updateGroundStatus()
{
    bool isTouchingAirPlatform = false;
    if (isOnGround())
    {
        QRectF characterRect = mapRectToScene(boundingRect());

        for (QGraphicsItem *item : scene()->items())
        {
            if (auto platform = dynamic_cast<Platform*>(item))
            {
                // 获取平台的边界矩形，并转换为全局坐标
                QRectF platformRect = platform->mapRectToScene(platform->boundingRect());

                // 检测角色与平台是否发生碰撞
                if (characterRect.intersects(platformRect)&&
                    characterRect.bottom()<platformRect.bottom())
                {
                    // 处理碰撞
                    isTouchingAirPlatform=true;
                    break;
                }
            }
        }

        if (!isTouchingAirPlatform)
        {
            setOnGround((false));
        }
    }
}

//设置人物边界大小，检测的相关方法
void Character::setSize(qreal w, qreal h)
{
    width = w;
    height = h;
    prepareGeometryChange();
}

qreal Character::getWidth() const
{
    return width;
}

qreal Character::getHeight() const
{
    return height;
}

QRectF Character::boundingRect() const
{
    return QRectF(-35,-50, width, height); // 确保返回正确的矩形
}

//生命值相关的setter, getter方法和更新方法
qreal Character::getHealth() const
{
    return health;
}

void Character::setHealth(qreal newHealth)
{
    int loss=health-newHealth;
    if (frozen)
    {
        unfreeze();
    }
    if (frozen)
    {
        this->health-=2*loss;
    }
    else
    {
        this->health-=loss;
    }
    updateHealthBar();
}

void Character::updateHealthBar()
{
    qreal healthBarWidth = (width * health) / 100; // Assume health is from 0 to 100
    healthBar->setRect(-35, -50, healthBarWidth, 5); // Update the health bar's size and position
}

//武器的使用接口
Weapon* Character::getWeapon() const
{
    return weapon;
}

const Bow* Character::getBow() const
{
    return bow;
}

//投掷武器的方法
void Character::throwWeapon()
{
    if (bow==nullptr)
    {
        setMode(0);
    }
    else
    {
        setMode(2);
    }
    weapon=nullptr;
}

//获取人物朝向
qreal Character::getRotationAngle() const
{
    QTransform transform = this->transform();
    return qAtan2(transform.m12(), transform.m11()) * (180.0 / M_PI);
}

//与人物目前近战、远程状态和手中持有箭种类的更新和设置接口
int Character::getMode() const
{
    return mode;
}

void Character::setMode (int newMode)
{
    if (weapon!=nullptr&&newMode==1)
    {
        mode=1;
        updateMode();
        return;
    }
    if (bow!=nullptr&&newMode==2)
    {
        mode=2;
        updateMode();
        return;
    }
    if (bow==nullptr&&weapon==nullptr&&newMode==0)
    {
        mode=0;
        updateMode();
        return;
    }
}

void Character::changeMode()
{
    if (weapon!=nullptr && bow!=nullptr)
    {
        mode=(mode==1?2:1);
    }
    updateMode();
}

void Character::updateMode()
{
    if (weapon!=nullptr && bow!=nullptr)
    {
        switch (this->getMode())
        {
        case 1:
            bow->setOpacity(0.2);
            weapon->setOpacity(1);
            break;
        case 2:
            bow->setOpacity(1);
            weapon->setOpacity(0.2);
            break;
        }
    }
    if (weapon!=nullptr)
    {
        if(weapon->whetherThrown())
        {
            weapon->setOpacity(1);
        }
    }

    if (weapon==nullptr&&bow!=nullptr)
    {
        bow->setOpacity(1);
    }
    else if (weapon!=nullptr&&bow==nullptr)
    {
        weapon->setOpacity(1);
    }

}

int Character::getArrowType() const
{
    return arrowType;
}

void Character::changeArrowType()
{
    if (this->isHaveArrow())
    {
        arrowType++;
        while (arrowType>4)
        {
            arrowType-=4;
        }
        while (numArrows[arrowType]==0)
        {
            arrowType++;
            while (arrowType>4)
            {
                arrowType-=4;
            }
        }
    }
}

bool Character::isHaveArrow() const
{
    return haveArrow;
}

void Character::updateArrowNum()
{
    int tot=0;
    for (int i=1;i<5;i++)
    {
        tot+=numArrows[i];
    }
    if (tot>0)
    {
        haveArrow=true;
    }
    else
    {
        haveArrow=false;
    }
}

const int* Character::getArrowNum() const
{
    return numArrows;
}

//人物射箭的方法
Arrow* Character::fireArrow(int type)
{
    int tempArrowNum =0;
    Arrow* arrow=nullptr;
    switch (type)
    {
    case 0:
        if (numArrows[arrowType]>0)
        {
            tempArrowNum=std::min(numArrows[arrowType],bow->getArrowNum());
            numArrows[arrowType]-=tempArrowNum;
            this->bow->bowFireArrow(tempArrowNum,arrowType);
        }
        this->updateArrowNum();
        if (numArrows[arrowType]==0)
        {
            this->changeArrowType();
        }
        return nullptr;
        break;
    case 1:
        switch(arrowType)
        {
        case 1:
            if (numArrows[1]>0)
            {
                arrow = new NormalArrow();
                numArrows[1]--;
            }
            break;
        case 2:
            if (numArrows[2]>0)
            {
                arrow = new FireArrow();
                numArrows[2]--;
            }
            break;
        case 3:
            if (numArrows[3]>0)
            {
                arrow =new FrozenArrow();
                numArrows[3]--;
            }
            break;
        case 4:
            if (numArrows[4]>0)
            {
                arrow =new ThunderArrow();
                numArrows[4]--;
            }
            break;
        }
        if (arrow!=nullptr)
        {
            QPointF tempPos=this->pos();
            tempPos.setY(tempPos.y()-10);
            arrow->setPos(tempPos);
            arrow->unmount();
            arrow->gravityHandler.setOnGround(false);
            arrow->setOwner(this);
            qreal rotationAngle = this->getRotationAngle();
            if (rotationAngle >= -90 && rotationAngle <= 90)
            {
                arrow->gravityHandler.setVelocity(QPointF(-5,-2));
            }
            else
            {
                arrow->gravityHandler.setVelocity(QPointF(5,-2));
            }
            this->updateArrowNum();
            if (numArrows[arrowType]==0)
            {
                this->changeArrowType();
            }
            return arrow;
        }
        break;
    }
    updateArrowNum();
    return arrow;

}

//处理人物着火的方法，包括删除木质武器的方法
void Character::setOnfire(bool newOnFire)
{
    if (!onFire&&newOnFire&&headEquipment==nullptr)
    {
        fireTimer->start(0);
        fireEffect = new FireEffect();
        fireEffect->setParentItem(this);
        fireEffect->mountToParent();
        scene()->addItem(fireEffect);
        onFire=newOnFire;
    }
}

void Character::processFire()
{
    if (fireStage<4)
    {
        this->health-=5;
        fireTimer->start(1000);
        fireStage++;
        return;
    }
    else
    {
        fireTimer->stop();
        fireStage=0;
        this->onFire=false;
        fireEffect->setExtingished(true);
        fireEffect =nullptr;
    }
}

void Character::checkOnFire()
{
    QRectF characterRect = mapRectToScene(boundingRect());

    for (QGraphicsItem *item : scene()->items())
    {
        if (auto fire = dynamic_cast<FireEffect*>(item))
        {
            QRectF fireRect = fire->mapRectToScene(fire->boundingRect());

            if (characterRect.intersects(fireRect)
                &&!fire->isMounted())
            {
                this->setOnfire(true);
            }
        }
    }
}

void Character::deleteWeapon()
{
    weapon->deleteLater();
    weapon=nullptr;

    if (bow==nullptr&&weapon==nullptr)
    {
        this->setMode(0);
    }
    else if (bow!=nullptr&&weapon==nullptr)
    {
        this->setMode(2);
    }
    updateMode();
}

void Character::deleteBow()
{
    bow->deleteLater();
    bow=nullptr;

    if (bow==nullptr&&weapon==nullptr)
    {
        this->setMode(0);
    }
    else if (bow==nullptr&&weapon!=nullptr)
    {
        this->setMode(1);
    }
    updateMode();
}

bool Character::isOnfire() const
{
    return onFire;
}

//处理人物冰冻的方法，包括冰冻和解冻的方法
void Character::setFrozen(bool newFrozen)
{
    if (newFrozen&&(!frozen)&&iceProofArmor==nullptr)
    {
        if (frozenEffect==nullptr)
        {
            frozenTimer->start(2000);
            frozenEffect= new FrozenEffect();
            frozenEffect->mountToParent();
            frozenEffect->setParentItem(this);
            frozen=newFrozen;
        }
    }
}

void Character::unfreeze()
{
    if (frozen&&frozenEffect!=nullptr)
    {
        frozen=false;
        frozenEffect->unmount();
        frozenEffect->isMelt=true;
        frozenEffect->deleteLater();
        frozenEffect=nullptr;
        frozenTimer->stop();
    }
}

bool Character::isFrozen() const
{
    return frozen;
}

//处理人物被电击的相关方法，包括检查人物手上是否含有带电的武器
void Character::processStruck()
{
    if (struckStage<4)
    {
        this->health-=5;
        struckTimer->start(500);
        struckStage++;
        return;
    }
    else
    {
        struckTimer->stop();
        struckStage=0;
        this->struck=false;
        thunderEffect->deleteLater();
        thunderEffect =nullptr;
    }
}

void Character::setStruck(bool newStruck)
{
    if (newStruck&&!struck&&legEquipment==nullptr)
    {
        checkMetalWeapon();
        struck=true;
        struckTimer->start(500);
        thunderEffect =new ThunderEffect();
        thunderEffect->mountToParent();
        thunderEffect->setParentItem(this);
        struck =newStruck;
    }

}

bool Character::isStruck() const
{
    return struck;
}

void Character::checkMetalWeapon()
{
    QPointF tempPos=this->pos();
    tempPos.setY(tempPos.y()-50);
    if (weapon!=nullptr&&weapon->isMetal())
    {
        weapon->unmount();
        weapon->setParentItem(this->parentItem());
        weapon->setPos(tempPos);
        weapon->setOpacity(1);
        weapon=nullptr;
    }

    if (bow!=nullptr&&bow->isMetal())
    {
        bow->unmount();
        bow->setParentItem(this->parentItem());
        bow->setPos(tempPos);
        bow->setOpacity(1);
        bow=nullptr;
    }

    if (bow==nullptr&&weapon==nullptr)
    {
        this->setMode(0);
    }
    else if (bow==nullptr&&weapon!=nullptr)
    {
        this->setMode(1);
    }
    else if (bow!=nullptr&&weapon==nullptr)
    {
        this->setMode(2);
    }
}

//检查人物是否处于元素抗性的方法
bool Character::isFireDefense() const
{
    return (headEquipment!=nullptr);
}

bool Character::isFrozenDefense() const
{
    return (iceProofArmor!=nullptr);
}

bool Character::isThunderDefnese() const
{
    return (legEquipment!=nullptr);
}

//获取状态栏的接口
StatusBar* Character::getStatusBar() const
{
    return statusBar;
}

//绘制人物边界，用来debug
/*
void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // 设置画笔的颜色（例如黑色）和宽度（例如2像素）
    QPen pen(Qt::black, 2);
    painter->setPen(pen);

    // 不使用填充
    painter->setBrush(Qt::NoBrush);
    // 画矩形的边框
    painter->drawRect(this->boundingRect());
}
*/


//only used for debugging
/*
void Character::ensureInBounds()
{
    QRectF characterRect = mapRectToScene(boundingRect());
    qDebug() << "Character Rect:"
             << "x:" << characterRect.x()
             << "y:" << characterRect.y()
             << "width:" << characterRect.width()
             << "height:" << characterRect.height()
             << "bottom:" << characterRect.bottom()
             << "top:" << characterRect.top()
             << "left:" << characterRect.left()
             << "right:" << characterRect.right();

    QPointF position =pos();
    qDebug() << "Character Position: x =" << position.x() << ", y =" << position.y();

    qreal rotationAngle = this->getRotationAngle();
    qDebug() << "Character's rotation angle:" << rotationAngle;

    qreal Arrow =this->numArrows[1];
    qDebug() << "Character's Num of Spare Arrows" <<Arrow;

    qDebug() <<"ArrowType"<<arrowType;

    qDebug() <<"Whether On Fire" <<onFire;

    qDebug() <<"mode"<<mode;
}
*/
