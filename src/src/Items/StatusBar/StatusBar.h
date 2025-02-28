//
// @brief: 本文件实现状态栏
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "../Item.h"
#include "StatusIcon.h"

#include <QGraphicsTextItem>

class Character;
//前向声明

class StatusBar: public Item
{
public:
    StatusBar(QGraphicsItem* parent=nullptr, const QString &pixmapPath="");

    //owner的setter和getter方法
    void  update();
    void setOwner(Character* newOwner);

private:
    //状态栏中的元素的指针
    StatusIcon* spareNormalArrow;
    StatusIcon* spareFireArrow;
    StatusIcon* spareFrozenArrow;
    StatusIcon* spareThunderArrow;
    QGraphicsTextItem* normalNum;
    QGraphicsTextItem* fireNum;
    QGraphicsTextItem* frozenNum;
    QGraphicsTextItem* thunderNum;
    StatusIcon* fireDefense;
    StatusIcon* thunderDefense;
    StatusIcon* frozenDefense;

    Character* owner {nullptr};
};

#endif // STATUSBAR_H
