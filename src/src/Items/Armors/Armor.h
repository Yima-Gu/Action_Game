//
// @brief: 本文件实现护甲的基类
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//


#ifndef QT_PROGRAMMING_2024_ARMOR_H
#define QT_PROGRAMMING_2024_ARMOR_H

#include "../GravityMountableItem.h"

//护甲
class Armor :public GravityMountableItem
{
public:
    explicit Armor(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount() override;
};


#endif //QT_PROGRAMMING_2024_ARMOR_H
