//
// @brief: 可以捡起的冰属性的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef SPAREFROZENARROW_H
#define SPAREFROZENARROW_H

#include "SpareArrow.h"

class SpareFrozenArrow: public SpareArrow
{
public:
    explicit SpareFrozenArrow(QGraphicsItem *parent =nullptr, const QString &pixmapPath ="");

    int getType() const override;
};

#endif // SPAREFROZENARROW_H
