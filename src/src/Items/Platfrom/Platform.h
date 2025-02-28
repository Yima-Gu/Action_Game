//
// @brief: 所有平台的基类实现
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "../Item.h"

class Platform : public Item
{
public:
    explicit Platform(QGraphicsItem *parent, const QString &pixmapPath)
        : Item(parent, pixmapPath)
    {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    }
    QRectF boundingRect() const override;

protected:
    qreal width;
    qreal height;

};
#endif // PLATFORM_H
