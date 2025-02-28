//
// @brief: 实现游戏中可以被捡起的火箭
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "SpareFireArrow.h"

SpareFireArrow::SpareFireArrow(QGraphicsItem *parent, const QString &pixmapPath)
    : SpareArrow(parent, "://Items/Arrow/spare_fire_arrow.png")
{

}

int SpareFireArrow::getType() const
{
    return 2;
}
