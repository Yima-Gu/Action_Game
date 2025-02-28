//
// @brief: 铁材质的弓
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef IRONBOW_H
#define IRONBOW_H

#include "../Bow.h"

class IronBow: public Bow
{
public:
    IronBow(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    //重载挂载和解挂、获取弓的射程和是否是金属质地的方法
    void mountToParent() override;
    void unmount() override;
    int getBowType() const override;
    int getBowRange() const override;
    int getArrowNum() const override;
    bool isMetal() const override;
};

#endif // IRONBOW_H
