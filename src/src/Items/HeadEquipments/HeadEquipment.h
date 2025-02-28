//
// @brief:实现游戏中的头部护甲
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_HEADEQUIPMENT_H
#define QT_PROGRAMMING_2024_HEADEQUIPMENT_H

#include "../GravityMountableItem.h"

class HeadEquipment: public GravityMountableItem
{
public:
    explicit HeadEquipment(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;
};

#endif //QT_PROGRAMMING_2024_HEADEQUIPMENT_H
