//
// @brief: 将挂载、显示和重力封装在一起，作为所有可捡起物品的基类
// @author: Gu Yima
// @copyright: Copyright 2024 Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef GRAVITYMOUNTABLEITEM_H
#define GRAVITYMOUNTABLEITEM_H

#include "Gravitational.h"
#include "Item.h"
#include "Mountable.h"

class GravityMountableItem: public QObject, public Item, public Mountable
{
    Q_OBJECT
public:
    explicit GravityMountableItem(QGraphicsItem *parent, const QString &pixmapPath);

    //物品的下落和碰撞实现
    void update() override;
    Gravitational gravityHandler;
};

#endif // GRAVITYMOUNTABLEITEM_H
