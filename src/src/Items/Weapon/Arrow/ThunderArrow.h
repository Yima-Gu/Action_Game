//
// @brief: 雷属性的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef THUNDERARROW_H
#define THUNDERARROW_H

#include "../Arrow.h"

class ThunderArrow: public Arrow
{
public:
    explicit ThunderArrow(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    //重载属性和伤害检测
    int getDamageValue() const override;
    bool InjuryDetector() override;
};

#endif // THUNDERARROW_H
