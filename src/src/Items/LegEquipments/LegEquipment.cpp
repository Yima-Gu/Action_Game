//
// @brief: 实现主角腿部护具的贴图
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "LegEquipment.h"

LegEquipment::LegEquipment(QGraphicsItem *parent, const QString &pixmapPath)
    : GravityMountableItem(parent, "://Items/Armor/ThunderProofShoes.png")
{
}

void LegEquipment::mountToParent()
{
    Mountable::mountToParent();
    setPos(-7, 20);
}

void LegEquipment::unmount()
{
    Mountable::unmount();
    setPos(0,0);
}
