//
// @brief: 实现按照枚举变量制造相应的物品的工厂类供静态方法来创建不同类型的 Item 对象和获取 ItemType 列表
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "ItemType.h"
#include "GravityMountableItem.h"

class ItemFactory
{
public:
    //按照枚举变量生成相关的物品
    static GravityMountableItem* createItem (ItemType type);

    //获取枚举类型的全部列表信息
    static QVector<ItemType> getItemTypes();
};

#endif // ITEMFACTORY_H
