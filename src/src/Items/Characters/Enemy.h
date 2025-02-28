//
// @brief: 具体的人物：enemy
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy: public Character
{
public:
    explicit Enemy(QGraphicsItem* parent=nullptr,const QString &pixmapPath="");
};

#endif // ENEMY_H
