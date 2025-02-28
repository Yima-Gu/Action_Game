//
// @brief: 实现游戏中铁材质的弓
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "IronBow.h"

IronBow::IronBow(QGraphicsItem *parent, const QString &pixmapPath) :Bow(parent,"://Items/Bow/iron_bow.png")
{

}

void IronBow::mountToParent()
{
    Mountable::mountToParent();
    setPos(-30,-30);
    setRotation(15);
}

void IronBow::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

int IronBow::getBowType() const
{
    return 1;
}

int IronBow::getBowRange() const
{
    return 20;
}

int IronBow::getArrowNum() const
{
    return 1;
}

bool IronBow::isMetal() const
{
    return 1;
}
