//
// @brief: 实现游戏地图的初始化
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent)
    : Map(parent, "://Items/Maps/Battlefield/BackGround.png") {}

//地面高度为场景上下边界中点的 63% 位置
qreal Battlefield::getFloorHeight()
{
    auto sceneRect = sceneBoundingRect();
    return (sceneRect.top() + sceneRect.bottom()) * 0.63;
}
