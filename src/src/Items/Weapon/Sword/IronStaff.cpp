//
// @brief: 实现游戏中的长矛，攻击范围增大
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "IronStaff.h"

IronStaff::IronStaff(QGraphicsItem *parent, const QString &pixmapPath) :Weapon(parent,"://Items/Weapon/iron_staff.png")
{

}

void IronStaff::mountToParent()
{
    Mountable::mountToParent();
    setPos(30,20);
    setRotation(90);
}

void IronStaff::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

int IronStaff::getDamageValue() const
{
    return 15;
}

void IronStaff::Attack()
{
    setPos(-10,20);
    this->InjuryDetector();
}

void IronStaff::Reversion()
{
    setPos(30,20);
}

bool IronStaff::isMetal() const
{
    return 1;
}

