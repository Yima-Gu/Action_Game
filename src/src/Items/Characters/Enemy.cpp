//
// @brief: 实现敌人的创建
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Enemy.h"
#include "../Armors/EnemyShirt.h"

Enemy::Enemy(QGraphicsItem *parent,const QString &pixmapPath)
    : Character(parent, "")
{
    armor = new EnemyShirt(this);
    armor->mountToParent();
}
