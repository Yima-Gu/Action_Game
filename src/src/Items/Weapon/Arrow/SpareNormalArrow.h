//
// @brief:普通的可以捡起的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef SPARENORMALARROW_H
#define SPARENORMALARROW_H

#include "SpareArrow.h"

class SpareNormalArrow :public SpareArrow
{
public:
    explicit SpareNormalArrow(QGraphicsItem *parent =nullptr, const QString &pixmapPath ="");

    int getType() const override;
};

#endif // SPARENORMALARROW_H
