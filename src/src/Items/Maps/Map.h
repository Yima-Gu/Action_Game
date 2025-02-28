//
// @brief:实现游戏中的地图
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//


#ifndef QT_PROGRAMMING_2024_MAP_H
#define QT_PROGRAMMING_2024_MAP_H

#include <QGraphicsScene>
#include <QPointF>
#include "../Item.h"

class Map : public Item
{
public:
    explicit Map(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

    void scaleToFitScene(QGraphicsScene *scene);

    virtual qreal getFloorHeight();

    virtual QPointF getSpawnPos();
};


#endif //QT_PROGRAMMING_2024_MAP_H
