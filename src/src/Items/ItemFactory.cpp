//
// @brief: 实现生产物品的工厂类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "ItemFactory.h"

#include "../Items/Weapon/Sword/Sword.h"
#include "../Items/Weapon/Sword/WoodSword.h"
#include "../Items/Weapon/Bow/WoodBow.h"
#include "../Items/Weapon/Arrow/SpareNormalArrow.h"
#include "../Items/Weapon/Bow/IronBow.h"
#include "../Items/Weapon/Sword/IronStaff.h"
#include "../Items/Weapon/Sword/FrezzeTHS.h"
#include "../Items/Weapon/Bow/IronHandBow.h"
#include "../Items/Weapon/Sword/FireSword.h"
#include "../Items/Weapon/Arrow/SpareFireArrow.h"
#include "../Items/Weapon/Arrow/SpareFrozenArrow.h"
#include "../Items/Weapon/Sword/ThunderSword.h"
#include "../Items/Weapon/Arrow/SpareThunderArrow.h"
#include "../Items/Armors/IceProofArmor.h"
#include "../Items/LegEquipments/LegEquipment.h"
#include "../Items/HeadEquipments/HeadEquipment.h"


GravityMountableItem* ItemFactory::createItem(ItemType type)
{
    switch (type)
    {
    case ItemType::FireSword:
        return new FireSword();
    case ItemType::FreezeTHS:
        return new FreezeTHS();
    case ItemType::IronStaff:
        return new IronStaff();
    case ItemType::Sword:
        return new Sword();
    case ItemType::ThunderSword:
        return new ThunderSword();
    case ItemType::WoodSword:
        return new WoodSword();
    case ItemType::IronBow:
        return new IronBow();
    case ItemType::IronHandBow:
        return new IronHandBow();
    case ItemType::WoodBow:
        return new WoodBow();
    case ItemType::SpareFireArrow:
        return new SpareFireArrow();
    case ItemType::SpareFrozenArrow:
        return new SpareFrozenArrow();
    case ItemType::SpareThunderArrow:
        return new SpareThunderArrow();
    case ItemType::SpareNormalArrow:
        return new SpareNormalArrow();
    case ItemType::IceProofArmor:
        return new IceProofArmor();
    case ItemType::HeadEquipment:
        return new HeadEquipment();
    case ItemType::LegEquipment:
        return new LegEquipment();
    default:
        // 处理未知物品类型
        return nullptr;
    }
}

QVector<ItemType> ItemFactory::getItemTypes()
{
    return
        {
        ItemType::FireSword,
        ItemType::FreezeTHS,
        ItemType::IronStaff,
        ItemType::Sword,
        ItemType::ThunderSword,
        ItemType::WoodSword,
        ItemType::IronBow,
        ItemType::IronHandBow,
        ItemType::WoodBow,
        ItemType::SpareFireArrow,
        ItemType::SpareFrozenArrow,
        ItemType::SpareThunderArrow,
        ItemType::SpareNormalArrow,
        ItemType::IceProofArmor,
        ItemType::HeadEquipment,
        ItemType::LegEquipment
    };
}
