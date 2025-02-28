//
// @brief: 实现游戏中可以被捡起的箭
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "SpareArrow.h"
#include <QGraphicsScene>

SpareArrow::SpareArrow(QGraphicsItem *parent, const QString &pixmapPath): GravityMountableItem(parent, pixmapPath)
{

}

void SpareArrow::update()
{
    GravityMountableItem::update();
}
