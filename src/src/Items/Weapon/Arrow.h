//
// @brief: 实现箭的基本功能
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef ARROW_H
#define ARROW_H

#include "../GravityMountableItem.h"

//Character类的前向声明
class Character;

class Arrow: public GravityMountableItem
{
public:
    explicit Arrow (QGraphicsItem *parent, const QString &pixmapPath);

    //重载更新方法
    void update() override;

    //箭的伤害检测和伤害数接口，按照不同种类的箭重载
    virtual bool InjuryDetector();
    virtual int getDamageValue() const =0;

    //射击者的getter和setter方法
    const Character* getOwner() const;
    void setOwner(Character* newOnwer);

private:
    Character* owner;
};

#endif // ARROW_H
