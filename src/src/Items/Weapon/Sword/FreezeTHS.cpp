//
// @brief: 实现游戏中的双手剑，实现延时攻击
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "FrezzeTHS.h"
#include "../../Characters/Character.h"

#include <QGraphicsScene>

FreezeTHS::FreezeTHS(QGraphicsItem *parent, const QString &pixmapPath) :Weapon(parent,"://Items/Weapon/freeze_sword.png")
{
    timer =new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FreezeTHS::performAttack);

}

void FreezeTHS::mountToParent()
{
    Mountable::mountToParent();
    setPos(-20,-60);

    QRectF bounds = boundingRect();
    QPointF Middle((bounds.width()) / 2, bounds.height() /2);
    setTransformOriginPoint(Middle);
    setRotation(-45);
}

void FreezeTHS::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

int FreezeTHS::getDamageValue() const
{
    return 10;
}

void FreezeTHS::Attack()
{
    if (isCoolingDown)
    {
        return; // 如果正在冷却中，直接返回，不执行攻击
    }
    // 设置冷却状态
    isCoolingDown = true;
    timer->start(1500);
}

void FreezeTHS::Reversion()
{

}


void FreezeTHS::performAttack()
{
    QRectF bounds = boundingRect();
    QPointF Middle((bounds.width()) / 2, bounds.height() /2);
    setTransformOriginPoint(Middle);
    switch(AttackStage)
    {
    case 0:
        this->setRotation(-90);
        this->setPos(-40,-30);
        this->InjuryDetector();
        timer->start(500);
        break;
    case 1:
        this->setRotation(90);
        this->setPos(20,-30);
        this->InjuryDetector();
        timer->start(500);
        break;
    case 2:
        this->setRotation(-45);
        this->setPos(-20,-60);
        isCoolingDown = false;
        timer->stop();
        break;
    }
    AttackStage++;
    if (AttackStage>2)
    {
        AttackStage-=3;
    }
}

//攻击时给人物加上冰冻效果
void FreezeTHS::InjuryDetector()
{
    Weapon::InjuryDetector();

    if (!whetherThrown())
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
                    character->setFrozen(true);
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
                    character->setFrozen(true);
                }
            }
        }
    }
}


bool FreezeTHS::isMetal() const
{
    return 1;
}
