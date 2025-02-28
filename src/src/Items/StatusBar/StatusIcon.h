//
// @brief: 状态栏中的图标实现
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef STATUSICON_H
#define STATUSICON_H

#include "../Item.h"

class StatusIcon: public Item
{
public:
    explicit StatusIcon (QGraphicsItem *parent=nullptr,const QString &pixmapPath="");
};

#endif // STATUSICON_H
