//
// @brief: 护甲基类的方法
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Armor.h"

// 构造函数，初始化护甲对象
Armor::Armor(QGraphicsItem *parent, const QString &pixmapPath)
    : GravityMountableItem(parent, pixmapPath)
{

}

// 重写 mountToParent 方法，以自定义护甲的挂载行为
void Armor::mountToParent()
{
    Mountable::mountToParent();
    setScale(1.6);
    setPos(-50, -50);
    if (pixmapItem != nullptr)
    {
        pixmapItem->setPos(0, 0);
    }
}

// 重写 unmount 方法，以自定义护甲的卸载行为
void Armor::unmount()
{
    Mountable::unmount();
    setScale(1.6);
    if (pixmapItem != nullptr)
    {
        pixmapItem->setPos(0, 0);
    }
}


