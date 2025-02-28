//
// @brief: 可以捡起的火属性的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef SPAREFIREARROW_H
#define SPAREFIREARROW_H

#include "SpareArrow.h"

class SpareFireArrow: public SpareArrow
{
public:
    explicit SpareFireArrow(QGraphicsItem *parent =nullptr, const QString &pixmapPath ="");

    int getType() const override;
};


#endif // SPAREFIREARROW_H
