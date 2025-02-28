//
// @brief: 实现游戏中的铁属性的普通近战武器
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Sword.h"

Sword::Sword(QGraphicsItem *parent, const QString &pixmapPath) :Weapon(parent,"://Items/Weapon/iron_long_sword.png")
{
}

void Sword::mountToParent()
{
    Mountable::mountToParent();
    setPos(-30,-55);

    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(-45);
}

void Sword::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

int Sword::getDamageValue() const
{
    return 15;
}

bool Sword::isMetal() const
{
    return 1;
}
