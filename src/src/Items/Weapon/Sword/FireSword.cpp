//
// @brief: 实现游戏中火属性的近战武器
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "FireSword.h"
#include "../../Characters/Character.h"

#include <QGraphicsScene>

FireSword::FireSword(QGraphicsItem *parent, const QString &pixmapPath) :Weapon(parent,"://Items/Weapon/fire_sword.png")
{

}

void FireSword::mountToParent()
{
    Mountable::mountToParent();
    setPos(-25,-35);
    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(-45);
}

void FireSword::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

int FireSword::getDamageValue() const
{
    return 10;
}

//在人物被攻击时给角色设置着火状态
void FireSword::InjuryDetector()
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
                     character->setOnfire(true);
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
                     character->setOnfire(true);
                }
            }
        }
    }

}

bool FireSword::isMetal() const
{
    return 0;
}
