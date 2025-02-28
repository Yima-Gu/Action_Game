//
// @brief: 近战武器的基本功能
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef WEAPON_H
#define WEAPON_H

#include "../GravityMountableItem.h"

// 前向声明 Character 类
class Character;

class Weapon:public GravityMountableItem
{

public:
    explicit Weapon (QGraphicsItem *parent, const QString &pixmapPath);

    void update() override;

    //普通的近战武器的攻击、还原动作和伤害检测，可重载
    virtual void Attack();
    virtual void Reversion();
    virtual void InjuryDetector();

    //普通武器的投掷，owner的getter和setter方法
    void Throw();
    bool whetherThrown () const ;
    const Character* getLstOwner() const;
    void setLastOwner(Character* ownerBeforeThrow);

    //对不同的武器伤害值和材质进行重载
    virtual int getDamageValue() const =0;
    virtual bool isMetal() const=0;

    //绘制武器边框，用于debug
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    bool isThrown =false;
    Character* lastOwner = nullptr;
};

#endif // WEAPON_H
