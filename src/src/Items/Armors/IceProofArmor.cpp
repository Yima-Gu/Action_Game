//
// @brief: 实现冰属性护甲贴图
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#include "IceProofArmor.h"

IceProofArmor::IceProofArmor(QGraphicsItem *parent, const QString &pixmapPath)
    :GravityMountableItem(parent, "://Items/Armors/FlamebreakerArmor/BotW_Flamebreaker_Armor_Icon.png")
{
    setScale(0.4);
}


void IceProofArmor::mountToParent()
{
    Mountable::mountToParent();

    setScale(0.2);
    setPos(-5, 5);
}


void IceProofArmor::unmount()
{
    setScale(0.4);
    Mountable::unmount();
    setPos(0,0);
}
