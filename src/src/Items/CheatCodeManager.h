//
// @brief: 设计处理作弊码的算法类，获取输入的字符算，生成相应的物品
// @author: Gu Yima
// @copyright: Copyright 2024 Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef CHEATCODEMANAGER_H
#define CHEATCODEMANAGER_H

#include "../Scenes/BattleScene.h"
#include "ItemType.h"

#include <QString>

class CheatCodeManager
{
public:
    CheatCodeManager(BattleScene *scene);
    void applyCheatCode(const QString &cheatCode);

private:
    void createItemFromCheatCode(ItemType itemType);
    BattleScene* battleScene;
};

#endif // CHEATCODEMANAGER_H
