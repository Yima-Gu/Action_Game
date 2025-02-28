//
// @brief:实现游戏中的作战场景
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_BATTLEFIELD_H
#define QT_PROGRAMMING_2024_BATTLEFIELD_H


#include "Map.h"

class Battlefield: public Map
{
public:
    explicit Battlefield(QGraphicsItem *parent= nullptr);

    qreal getFloorHeight() override;
};


#endif //QT_PROGRAMMING_2024_BATTLEFIELD_H
