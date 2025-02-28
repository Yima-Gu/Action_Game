//
// @brief: 本文件用来实现可以进行碰撞检测的空气墙，并作为不同材质平台的基类
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef AIRPLATFORM_H
#define AIRPLATFORM_H

#include "Platform.h"

class AirPlatform:public Platform
{
public:
    explicit AirPlatform(QGraphicsItem *parent = nullptr);

    void setSize(qreal width, qreal height);

    //用于绘制边界，仅为debug
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // AIRPLATFORM_H
