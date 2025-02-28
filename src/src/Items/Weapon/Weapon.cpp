//
// @brief: 实现游戏中的所有近战武器的基类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Weapon.h"
#include "../Characters/Character.h"

#include <QGraphicsScene>

Weapon::Weapon(QGraphicsItem *parent, const QString &pixmapPath) : GravityMountableItem(parent, pixmapPath)
{

}

//重载更新方法，实现武器的投掷
void Weapon::update()
{
    GravityMountableItem::update();

    QPointF velocity = gravityHandler.getVelocity();
    if (isThrown)
    {
        // 计算速度的方向
        qreal angle = std::atan2(velocity.y(), velocity.x()) * (180.0 / M_PI);
        // 更新 Weapon 的旋转角度
        setRotation(angle+90);
        this->InjuryDetector();

        QList<QGraphicsItem*> collidingItems = this->collidingItems();
        for (QGraphicsItem* item : collidingItems)
        {
            auto charcter = dynamic_cast<Character*>(item);
            if (charcter!=nullptr && charcter!= lastOwner)
            {
                gravityHandler.setVelocity(QPointF(0.0, 0.0)); // 重置速度
                gravityHandler.setOnGround(true); // 设置为在地面上
                setRotation(0);
                return;
            }
        }
    }
}


//普通武器的攻击和恢复方法
void Weapon::Attack()
{
    // 获取缩放后的边界矩形
    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, (bounds.height()));

    // 设置旋转原点为底边中点
    setTransformOriginPoint(bottomMiddle);
    setRotation(-135);

    this->InjuryDetector();
}

void Weapon::Reversion()
{
    QRectF bounds = boundingRect();

    // 计算缩放后的底边中点
    QPointF bottomMiddle((bounds.width()) / 2, (bounds.height()));

    // 设置旋转原点为底边中点
    setTransformOriginPoint(bottomMiddle);
    setRotation(-45);
}

//普通的进展武器的伤害监测方法
void Weapon::InjuryDetector()
{
    if (!isThrown)
    {
        QRectF weaponRect = mapRectToScene(boundingRect());
        for (QGraphicsItem *item : scene()->items())
        {
            if (auto character = dynamic_cast<Character*>(item))
            {
                QRectF characterRect = character->mapRectToScene(character->boundingRect());
                if (weaponRect.intersects(characterRect)
                    &&character!=this->parentItem())
                {
                    character->setHealth(character->getHealth()-this->getDamageValue());
                }
            }
        }
    }
    else
    {
        QRectF weaponRect = mapRectToScene(boundingRect());
        for (QGraphicsItem *item : scene()->items())
        {
            if (auto character = dynamic_cast<Character*>(item))
            {
                QRectF characterRect = character->mapRectToScene(character->boundingRect());
                if (weaponRect.intersects(characterRect)
                    &&character!=this ->getLstOwner())
                {
                    character->setHealth(character->getHealth()-this->getDamageValue());
                    this->gravityHandler.setOnGround(true);
                }
            }
        }
    }
}

//近战武器的投掷方法
void Weapon::Throw()
{
    if (auto *character = dynamic_cast<Character*>(parentItem()))
    {
        isThrown=true;
        // 获取角色的旋转角度
        qreal rotationAngle = character->getRotationAngle();
        // 解除武器与角色的绑定
        this->unmount();
        setLastOwner(character);

        this->setParentItem(character->parentItem());
        QPointF tempPos=character->pos();
        tempPos.setY(tempPos.y()-100);
        this->setPos(tempPos);

        gravityHandler.setOnGround(false);

        // 判断朝向并设置速度
        if (rotationAngle >= -90 && rotationAngle <= 90)
        {
            gravityHandler.setVelocity(QPointF(-5, -3));  // 向右抛
        }
        else
        {
            gravityHandler.setVelocity(QPointF(5, -3)); // 向左抛
        }
    }

}

bool Weapon::whetherThrown() const
{
    return isThrown;
}


const Character* Weapon::getLstOwner() const
{
    return lastOwner;
}

void Weapon::setLastOwner(Character* ownerBeforeThrow)
{
    lastOwner=ownerBeforeThrow;
}

/*
void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // 设置画笔颜色和风格
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::NoBrush);

    // 绘制边界矩形
    painter->drawRect(boundingRect());

    QPointF center = pos();

    // 设置圆的半径
    qreal radius = 10.0;  // 可以根据需要调整半径的大小

    // 绘制圆形，以中心为圆心，半径为radius
    painter->drawEllipse(center, radius, radius);
}
*/
