//
// @brief: 实现游戏中铁材质的连发弩
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "IronHandBow.h"

#include <QGraphicsScene>

IronHandBow::IronHandBow(QGraphicsItem *parent, const QString &pixmapPath) :Bow(parent,"://Items/Bow/iron_hand_bow.png")
{

}

void IronHandBow::mountToParent()
{
    Mountable::mountToParent();
    setPos(-40,-10);
}

void IronHandBow::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
}

int IronHandBow::getBowType() const
{
    return 1;
}

int IronHandBow::getBowRange() const
{
    return 20;
}

int IronHandBow::getArrowNum() const
{
    return 3;
}

bool IronHandBow::isMetal() const
{
    return 1;
}
