//
// @brief: 岩石材质的平台，类似于空气平台
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef ROCKPLATFORM_H
#define ROCKPLATFORM_H

#include "AirPlatform.h"

class RockPlatform : public AirPlatform
{
public:
    explicit RockPlatform(QGraphicsItem *parent = nullptr, const QString &imagePath = "");

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPixmap pixmap;
};

#endif // ROCKPLATFORM_H
