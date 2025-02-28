//
// @brief: 本文件是敌人的图像
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef ENEMYSHIRT_H
#define ENEMYSHIRT_H

#include "Armor.h"

class EnemyShirt: public Armor
{

public:
    explicit EnemyShirt(QGraphicsItem* parent);
};

#endif // ENEMYSHIRT_H
