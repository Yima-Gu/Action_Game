//
// @brief:实现游戏中的腿部防具
// @author: Gu Yima
// @copyright: Copyright 2024 Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_LEGEQUIPMENT_H
#define QT_PROGRAMMING_2024_LEGEQUIPMENT_H

#include "../GravityMountableItem.h"

class LegEquipment: public GravityMountableItem
{
public:
    explicit LegEquipment(QGraphicsItem *parent=nullptr, const QString &pixmapPath ="");

    void mountToParent() override;

    void unmount() override;
};


#endif //QT_PROGRAMMING_2024_LEGEQUIPMENT_H
