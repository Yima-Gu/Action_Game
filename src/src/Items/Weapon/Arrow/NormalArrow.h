//
// @brief: 普通的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef NORMALARROW_H
#define NORMALARROW_H

#include "../Arrow.h"

class NormalArrow :public Arrow
{
public:
    explicit NormalArrow(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    int getDamageValue() const override;
};

#endif // NORMALARROW_H
