//
// @brief: 冰属性的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef FROZENARROW_H
#define FROZENARROW_H

#include "../Arrow.h"

class FrozenArrow: public Arrow
{
public:
    explicit FrozenArrow(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    //重载伤害值和伤害检测
    int getDamageValue() const override;
    bool InjuryDetector() override;
};

#endif // FROZENARROW_H
