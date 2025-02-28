//
// @brief: 游戏中得到岩石平台
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "RockPlatform.h"

RockPlatform::RockPlatform(QGraphicsItem *parent, const QString &imagePath)
    : AirPlatform(parent)
{
    pixmap.load("://Items/Platform/RockPlatform.png");
}

void RockPlatform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(0, 0, width, height, pixmap);
}
