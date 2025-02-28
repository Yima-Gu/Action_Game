//
// @brief: 实现游戏中可以被捡起的雷属性箭
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "SpareThunderArrow.h"

SpareThunderArrow::SpareThunderArrow (QGraphicsItem *parent, const QString &pixmapPath)
    : SpareArrow(parent,"://Items/Arrow/spare_thunder_arrow.png")
{

}

int SpareThunderArrow::getType() const
{
    return 4;
}
