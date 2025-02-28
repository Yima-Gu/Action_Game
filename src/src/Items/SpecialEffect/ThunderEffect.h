//
// @brief: 本文件实现电击特效
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef THUNDEREFFECT_H
#define THUNDEREFFECT_H

#include "../Item.h"
#include "../Mountable.h"

class ThunderEffect:public QObject, public Item, public Mountable
{
public:
    explicit ThunderEffect(QGraphicsItem *parent = nullptr, const QString &imagePath = "");

    //重载挂载更新
    void mountToParent() override;
    void update() override;
};

#endif // THUNDEREFFECT_H
