//
// @brief: 实现作战场景的类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "BattleScene.h"
#include "../Items/Characters/Link.h"
#include "../Items/Maps/Battlefield.h"
#include "../Items/Weapon/Sword/WoodSword.h"
#include "../Items/Weapon/Bow/WoodBow.h"
#include "../Items/Characters/Enemy.h"
#include "../Items/Armors/IceProofArmor.h"
#include "../Items/LegEquipments/LegEquipment.h"
#include "../Items/HeadEquipments/HeadEquipment.h"
#include "../Items/ItemFactory.h"


#include <QDebug>
#include <QRandomGenerator>

BattleScene::BattleScene(QObject *parent) : Scene(parent)
{
    setSceneRect(0, 0, 1280, 720);
    this->initialization();

    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &BattleScene::spawnRandomItem);
    spawnTimer->start(8000); // 每隔8aa秒生成一个物品
}

//处理输入、处理移动和捡拾的函数
void BattleScene::processInput()
{
    Scene::processInput();
    if (character != nullptr)
    {
        character->processInput();
    }
    if (enemy !=nullptr)
    {
        enemy ->processInput();
    }
}

void BattleScene::processMovement()
{
    Scene::processMovement();
    if (character != nullptr)
    {
        QPointF newPos = character->pos() + character->getVelocity() * static_cast<double>(deltaTime);
        newPos.setX(qBound(40.0, newPos.x(), 1240.0));
        character->setPos(newPos);
    }
    if (enemy != nullptr)
    {
        QPointF newPos = enemy->pos() + enemy->getVelocity() * static_cast<double>(deltaTime);
        newPos.setX(qBound(40.0, newPos.x(), 1240.0));
        enemy->setPos(newPos);
    }

}

void BattleScene::processPicking()
{
    Scene::processPicking();
    if (character->isPicking())
    {
        auto mountable = findNearestUnmountedMountable(character->pos(), 100.);
        if (mountable != nullptr)
        {

            (pickupMountable(character, mountable));
        }
    }
    if (enemy->isPicking())
    {
        auto mountable = findNearestUnmountedMountable(enemy->pos(), 100.);
        if (mountable != nullptr)
        {
            (pickupMountable(enemy, mountable));
        }
    }
}

//键盘按下和释放处理函数
void BattleScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_A:
            if (character != nullptr)
            {
                character->setLeftDown(true);
            }
            break;
        case Qt::Key_Left:
            if (enemy != nullptr)
            {
                enemy->setLeftDown(true);
            }
            break;
        case Qt::Key_D:
            if (character != nullptr)
            {
                character->setRightDown(true);
            }
            break;
        case Qt::Key_Right:
            if (enemy != nullptr)
            {
                enemy->setRightDown(true);
            }
            break;
        case Qt::Key_E:
            if (character != nullptr)
            {
                character->setPickDown(true);
            }
            break;
        case Qt::Key_J:
            if (enemy!=nullptr)
            {
                enemy->setPickDown(true);
            }
            break;
        case Qt::Key_W:
            if (character!=nullptr)
            {
                character->setUpDown(true);
            }
            break;
        case Qt::Key_Up:
            if (enemy != nullptr)
            {
                enemy->setUpDown(true);
            }
            break;
        case Qt::Key_Q:
            if (character!=nullptr&&character->getWeapon()!=nullptr&&character->getMode()==1)
            {
                character->getWeapon()->Attack();
            }
            else if (character!=nullptr)
            {
                character->changeArrowType();
            }
            break;
        case Qt::Key_K:
            if (enemy!=nullptr&&enemy->getWeapon()!=nullptr&&enemy->getMode()==1)
            {
                enemy->getWeapon()->Attack();
            }
            else if (enemy!=nullptr)
            {
                enemy->changeArrowType();
            }
            break;
        case Qt::Key_R:
            if (character!=nullptr&&character->getMode()==2)
            {
                this->addArrow(character->fireArrow(0));
            }
            else if (character!=nullptr&&character->getMode()==1&&character->getBow()!=nullptr)
            {
                character->getWeapon()->Throw();
                character->throwWeapon();
            }
            else if (character!=nullptr&&character->isHaveArrow())
            {
                this->addArrow(character->fireArrow(1));
            }
            else if (character!=nullptr&&character->getWeapon()!=nullptr&&character->getMode()==1)
            {
                character->getWeapon()->Throw();
                character->throwWeapon();
            }
            break;
        case Qt::Key_L:
            if (enemy!=nullptr&&enemy->getMode()==2)
            {
                this->addArrow(enemy->fireArrow(0));
            }
            else if (enemy!=nullptr&&enemy->getMode()==1&&enemy->getBow()!=nullptr)
            {
                enemy->getWeapon()->Throw();
                enemy->throwWeapon();
            }
            else if (enemy!=nullptr&&enemy->isHaveArrow())
            {
                this->addArrow(enemy->fireArrow(1));
            }
            else if (enemy!=nullptr&&enemy->getWeapon()!=nullptr&&enemy->getMode()==1)
            {
                enemy->getWeapon()->Throw();
                enemy->throwWeapon();
            }
            break;
        case Qt::Key_Z:
            if (character!=nullptr)
            {
                character->changeMode();
            }
            break;
        case Qt::Key_M:
            if (enemy !=nullptr)
            {
                enemy->changeMode();
            }
            break;
        default:
            Scene::keyPressEvent(event);
    }
}

void BattleScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_A: //向左移动
            if (character != nullptr)
            {
                character->setLeftDown(false);
            }
            break;
        case Qt::Key_Left:
            if (enemy != nullptr)
            {
                enemy->setLeftDown(false);
            }
            break;
        case Qt::Key_D: //向右移动
            if (character != nullptr)
            {
                character->setRightDown(false);
            }
            break;
        case Qt::Key_Right:
            if (enemy != nullptr)
            {
                enemy->setRightDown(false);
            }
            break;
        case Qt::Key_E: //拾取
            if (character != nullptr)
            {
                character->setPickDown(false);
            }
            break;
        case Qt::Key_J:
            if (enemy != nullptr)
            {
                enemy->setPickDown(false);
            }
            break;
        case Qt::Key_W:
            if (character!=nullptr)
            {
                character->setUpDown(false);
            }
            break;
        case Qt::Key_Up:
            if (enemy !=nullptr)
            {
                enemy->setUpDown(false);
            }
            break;
        case Qt::Key_Q:
            if (character!=nullptr&&character->getWeapon()!=nullptr&&character->getMode()==1)
            {
                character->getWeapon()->Reversion();
            }
            break;
        case Qt::Key_K:
            if (enemy!=nullptr&&enemy->getWeapon()!=nullptr&&enemy->getMode()==1)
            {
                enemy->getWeapon()->Reversion();
            }
            break;
        default:
            Scene::keyReleaseEvent(event);
    }
}

void BattleScene::update()
{
    this->checkGameOver();

    Scene::update();

    for (QGraphicsItem *item: items())
    {
        if (auto mountable = dynamic_cast<Mountable *>(item))
        {
            if (mountable!=nullptr&&
                !(mountable->isMounted()))
            {
                mountable->update();
            }
        }
    }


    for (QGraphicsItem *item: items())
    {
        if (auto metalPlatform = dynamic_cast<MetalPlatform *>(item))
        {
            metalPlatform->ThunderDetector();
        }
    }

    //统一释放内存，防止使用野指针
    this->deleteThrownWeapon();
    this->deleteArrow();
    this->deleteExtinguishedFire();

    for (QGraphicsItem *item: items())
    {
        if (auto woodItem = dynamic_cast<WoodSword *>(item))
        {
            woodItem->checkOnFire();
        }
        if (auto woodItem = dynamic_cast<WoodBow *>(item))
        {
            woodItem->checkOnFire();
        }
        if (auto fire = dynamic_cast<FireEffect* >(item))
        {
            fire->update();
        }
    }
}


//这个方法有效地遍历场景中的所有对象，找到最近的、未被挂载的 Mountable 对象
Mountable *BattleScene::findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold)
{
    Mountable *nearest = nullptr;
    qreal minDistance = distance_threshold;

    for (QGraphicsItem *item: items())
    {
        if (auto mountable = dynamic_cast<Mountable *>(item))
        {
            if (!mountable->isMounted())
            {
                qreal distance = QLineF(pos, item->pos()).length();
                if (distance < minDistance)
                {
                    minDistance = distance;
                    nearest = mountable;
                }
            }
        }
    }
    return nearest;
}

Mountable *BattleScene::pickupMountable(Character *currentCharacter, Mountable *mountable)
{
    if (auto armor = dynamic_cast<IceProofArmor *>(mountable))
    {
        return currentCharacter->pickupArmor(armor);
    }
    if (auto weapon=dynamic_cast<Weapon *>(mountable))
    {
        return currentCharacter->pickupWeapon(weapon);
    }
    if (auto bow=dynamic_cast<Bow *>(mountable))
    {
        return currentCharacter->pickupBow(bow);
    }
    if (auto spareArrow=dynamic_cast<SpareArrow*>(mountable))
    {
        return currentCharacter->pickupArrow(spareArrow);
    }
    if (auto helmet=dynamic_cast<HeadEquipment*> (mountable))
    {
        return currentCharacter->pickupHelmet(helmet);
    }
    if (auto shoes= dynamic_cast<LegEquipment*> (mountable))
    {
        return currentCharacter->pickupShoes(shoes);
    }

    return nullptr;
}

//添加箭和删除箭和特效的方法，统一销毁能避免使用野指针
void BattleScene::deleteThrownWeapon()
{
    for (QGraphicsItem *item: items())
    {
        if (auto weapon = dynamic_cast<Weapon*>(item))
        {
            if (weapon->whetherThrown()&&weapon->gravityHandler.isOnGround())
            {
                weapon->deleteLater();
            }
        }
    }
}

void BattleScene::addArrow(Arrow* newArrow)
{
    this->addItem(newArrow);
}

void BattleScene::deleteArrow()
{
    for (QGraphicsItem *item: items())
    {
        if (auto arrow = dynamic_cast<Arrow*>(item))
        {
            if (arrow->gravityHandler.isOnGround()
                ||arrow->pos().x()<-20
                ||arrow->pos().x()>1600)
            {
                arrow->deleteLater();
            }
        }
    }
}

void BattleScene::woodPlatformDeleted()
{
    WoodPlatformHigh=nullptr;
}

void BattleScene::deleteExtinguishedFire()
{
    for (QGraphicsItem *item: items())
    {
        if (auto fire = dynamic_cast<FireEffect*>(item))
        {
            if (fire->isExtingished())
            {
                fire->deleteLater();
            }
        }
    }
}

//检查游戏结束，发出结束的信号
void BattleScene::checkGameOver()
{
    if (character->getHealth()<=0)
    {
        emit gameoverSignal(0);
    }
    else if (enemy->getHealth()<=0)
    {
        emit gameoverSignal(1);
    }
}

//随机生成物品的函数
void BattleScene::spawnRandomItem()
{
    QVector<ItemType> itemTypes = ItemFactory::getItemTypes();
    int randomIndex = QRandomGenerator::global()->bounded(itemTypes.size());
    ItemType randomType = itemTypes[randomIndex];

    GravityMountableItem* item=ItemFactory::createItem(randomType);

    if (item)
    {
        int randomX = QRandomGenerator::global()->bounded(20, 1260);// 场景宽度为1280
        item->setPos(randomX, 0); // 在空中随机位置生成
        addItem(item);
        item->unmount();
    }
}

//初始化函数
void BattleScene::initialization()
{
    map = new Battlefield();
    map->scaleToFitScene(this);
    addItem(map);

    character = new Link();
    enemy = new Enemy();
    addItem(character);
    addItem(enemy);
    character->setPos(map->getSpawnPos());
    enemy->setPos(map->getSpawnPos());

    airPlatformGround = new AirPlatform();
    airPlatformGround->setPos(0, 525);
    airPlatformGround->setSize(1280,50);

    MetalPlatformLeft=new MetalPlatform();
    MetalPlatformLeft->setPos(160,330);
    MetalPlatformLeft->setSize(350,50);

    RockPlatformRight=new RockPlatform();
    RockPlatformRight->setPos(770,330);
    RockPlatformRight->setSize(350,50);

    WoodPlatformHigh=new WoodPlatform();
    WoodPlatformHigh->setPos(465,145);
    WoodPlatformHigh->setSize(350,50);
    connect(WoodPlatformHigh, &WoodPlatform::woodPlatformBurnOut,
            this, &BattleScene::woodPlatformDeleted);

    addItem(airPlatformGround);
    addItem(MetalPlatformLeft);
    addItem(RockPlatformRight);
    addItem(WoodPlatformHigh);


    addItem(character->getStatusBar());
    character->getStatusBar()->setPos(0,30);
    addItem(enemy->getStatusBar());
    enemy->getStatusBar()->setPos(1050,30);
}

//根据作弊码添加物品
void BattleScene::addFromCheatCode(GravityMountableItem* item)
{
    item->unmount();
    addItem(item);
    int randomX = QRandomGenerator::global()->bounded(20, 1260);
    item->setPos(randomX, 0);
}

