//
// @brief: 可以捡起的雷属性的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef SPARETHUNDERARROW_H
#define SPARETHUNDERARROW_H

#include "SpareArrow.h"

class SpareThunderArrow :public SpareArrow
{
public:
    explicit SpareThunderArrow(QGraphicsItem *parent =nullptr, const QString &pixmapPath ="");

    int getType() const override;
};

#endif // SPARETHUNDERARROW_H
