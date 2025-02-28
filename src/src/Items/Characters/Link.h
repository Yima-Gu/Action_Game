//
// @brief: 具体的人物：Link
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Created by Ling Jingwang on 2024-08-21
//

#ifndef QT_PROGRAMMING_2024_LINK_H
#define QT_PROGRAMMING_2024_LINK_H


#include "Character.h"

//主角 Link,这个类的实现为角色 Link 定义了初始的装备状态。
class Link : public Character
{
public:
    explicit Link(QGraphicsItem *parent = nullptr, const QString &pixmapPath="");
};

#endif //QT_PROGRAMMING_2024_LINK_H
