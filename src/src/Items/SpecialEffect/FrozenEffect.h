//
// @brief: 本文件实现冰冻特效
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef FROZENEFFECT_H
#define FROZENEFFECT_H

#include "../Item.h"
#include "../Mountable.h"

class FrozenEffect:public QObject, public Item, public Mountable
{
public:
    explicit FrozenEffect(QGraphicsItem *parent = nullptr, const QString &imagePath = "");

    //挂载和更新的重载
    void mountToParent() override;
    void update() override;

    //bool 量用于统一销毁对象
    bool isMelt {false};

};

#endif // FROZENEFFECT_H
