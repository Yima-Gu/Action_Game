//
// @brief: 实现游戏中的普通箭
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "NormalArrow.h"

NormalArrow::NormalArrow(QGraphicsItem *parent, const QString &pixmapPath)
    :Arrow(parent,"://Items/Arrow/basic_arrow.png")
{

}


int NormalArrow::getDamageValue() const
{
    return 10;
}
