//
// @brief: 游戏中的作弊码的算法类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "CheatCodeManager.h"
#include "ItemFactory.h"

CheatCodeManager::CheatCodeManager(BattleScene *scene)
    :battleScene(scene)
{

}

void CheatCodeManager::applyCheatCode(const QString &cheatCode)
{
    ItemType itemType;

    // 使用 QMap 或类似的数据结构映射作弊码到 ItemType
    QMap<QString, ItemType> cheatCodeMap =
        {
        {"FireSword", ItemType::FireSword},
        {"FreezeTHS", ItemType::FreezeTHS},
        {"IronStaff", ItemType::IronStaff},
        {"Sword", ItemType::Sword},
        {"ThunderSword", ItemType::ThunderSword},
        {"WoodSword", ItemType::WoodSword},
        {"IronBow", ItemType::IronBow},
        {"IronHandBow", ItemType::IronHandBow},
        {"WoodBow", ItemType::WoodBow},
        {"SpareFireArrow", ItemType::SpareFireArrow},
        {"SpareFrozenArrow", ItemType::SpareFrozenArrow},
        {"SpareThunderArrow", ItemType::SpareThunderArrow},
        {"SpareNormalArrow", ItemType::SpareNormalArrow},
        {"IceProofArmor", ItemType::IceProofArmor},
        {"HeadEquipment", ItemType::HeadEquipment},
        {"LegEquipment", ItemType::LegEquipment}
    };

    if (cheatCodeMap.contains(cheatCode))
    {
        itemType = cheatCodeMap[cheatCode];
        createItemFromCheatCode(itemType);
    } else
    {
        // 处理未知作弊码的逻辑
        qDebug() << "Unknown cheat code:" << cheatCode;
    }
}


void CheatCodeManager::createItemFromCheatCode(ItemType itemType)
{
    GravityMountableItem *item = ItemFactory::createItem(itemType);
    if (item&&battleScene)
    {
        battleScene->addFromCheatCode(item);
    }
}
