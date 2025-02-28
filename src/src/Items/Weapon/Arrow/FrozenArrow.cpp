//
// @brief: 实现游戏中的冰箭
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "FrozenArrow.h"
#include "../../Characters/Character.h"

FrozenArrow::FrozenArrow(QGraphicsItem *parent, const QString &pixmapPath)
    :Arrow(parent,"://Items/Arrow/freeze_arrow.png" )
{

}

int FrozenArrow::getDamageValue() const
{
    return 10;
}

bool FrozenArrow::InjuryDetector()
{
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    for (QGraphicsItem* item : collidingItems)
    {
        auto character = dynamic_cast<Character*>(item);

        if (character!=nullptr
            && character!= this->getOwner())
        {
            character->setHealth(character->getHealth()-this->getDamageValue());
            character->setFrozen(true);
            return true;
        }
    }
    return false;
}
