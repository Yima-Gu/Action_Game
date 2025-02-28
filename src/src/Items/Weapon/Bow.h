//
// @brief: 实现弓的基本功能
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef BOW_H
#define BOW_H

#include "../GravityMountableItem.h"

class Bow : public GravityMountableItem
{
public:
    explicit Bow (QGraphicsItem *parent, const QString &pixmapPath);

    //弓的射箭方法，可按照不同的种类重载
    virtual void bowFireArrow(int bowArrowNum, int bowArrowType);

    //弓的参数，可以按照不同的弓的种类重载
    virtual bool isMetal() const=0;
    virtual int getBowType() const =0;
    virtual int getBowRange() const =0;
    virtual int getArrowNum() const =0;
};

#endif // BOW_H
