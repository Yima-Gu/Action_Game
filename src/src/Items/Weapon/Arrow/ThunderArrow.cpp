//
// @brief: 实现游戏中雷属性的箭
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "ThunderArrow.h"
#include "../../Characters/Character.h"

#include <QGraphicsScene>

ThunderArrow::ThunderArrow(QGraphicsItem *parent, const QString &pixmapPath)
    :Arrow(parent,"://Items/Arrow/thunder_arrow.png")
{

}

int ThunderArrow::getDamageValue() const
{
    return 10;
}


bool ThunderArrow::InjuryDetector()
{
    Arrow::InjuryDetector();

    QList<QGraphicsItem*> collidingItems = this->collidingItems();

    for (QGraphicsItem* item : collidingItems)
    {
        auto character = dynamic_cast<Character*>(item);

        if (character!=nullptr
            && character!= this->getOwner())
        {
            character->setStruck(true);
            return true;
        }
    }
    return false;
}
