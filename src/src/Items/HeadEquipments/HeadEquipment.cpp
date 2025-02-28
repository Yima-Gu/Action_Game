//
// @brief: 实现头部护甲的贴图
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//
#include "HeadEquipment.h"

HeadEquipment::HeadEquipment(QGraphicsItem *parent, const QString &pixmapPath)
    : GravityMountableItem(parent, "://Items/Armor/FireProofHelmet.png")
{
}

void HeadEquipment::mountToParent()
{
    Mountable::mountToParent();
    setPos(-10, -40);
}

void HeadEquipment::unmount()
{
    Mountable::unmount();
    setPos(0,0);
}
