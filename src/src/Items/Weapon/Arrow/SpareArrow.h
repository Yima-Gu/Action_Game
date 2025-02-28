//
// @brief: 可捡起的箭基本功能
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef SPAREARROW_H
#define SPAREARROW_H

#include "../../GravityMountableItem.h"

class SpareArrow: public GravityMountableItem
{
public:
    explicit SpareArrow (QGraphicsItem *parent, const QString &pixmapPath);
    void update();

    //表示空白箭种类，在后面重载
    virtual int getType() const =0 ;
};

#endif // SPAREARROW_H
