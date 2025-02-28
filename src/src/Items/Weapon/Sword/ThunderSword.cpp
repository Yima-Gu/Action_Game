//
// @brief: 实现游戏中的雷属性的近战武器
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-29
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "ThunderSword.h"
#include "../../Characters/Character.h"

#include <QGraphicsScene>


ThunderSword::ThunderSword(QGraphicsItem *parent, const QString &pixmapPath)
    :Weapon(parent,"://Items/Weapon/thunder_sword.png" )
{

}

void ThunderSword::mountToParent()
{
    Mountable::mountToParent();
    setPos(-30,-65);

    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(-45);
}

void ThunderSword::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

int ThunderSword::getDamageValue() const
{
    return 15;
}

//攻击时给角色带上雷属性
void ThunderSword::InjuryDetector()
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
                    character->setStruck(true);
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
                    character->setStruck(true);
                }
            }
        }
    }
}

bool ThunderSword::isMetal() const
{
    return 1;

}
