//
// @brief: 实现游戏中的可碰撞的空气平台
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "AirPlatform.h"

AirPlatform::AirPlatform(QGraphicsItem *parent)
    : Platform(parent,"")
{

}

// 设置平台大小的函数
void AirPlatform::setSize(qreal newWidth, qreal newHeight)
{
    width = newWidth;
    height = newHeight;
    update(); // 更新图形项，使得新的大小生效
}

//debug用，绘制对象的边框
/*
void AirPlatform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black); // 使用黑色边框
    pen.setWidth(2); // 设置边框宽度
    painter->setPen(pen);

    // 绘制矩形边框
    painter->drawRect(0, 0, width, height);
}
*/
