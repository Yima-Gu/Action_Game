//
// @brief: 设计重力加速度类来来模拟物品的运动
// @author: Gu Yima
// @copyright: Copyright 2024 Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef GRAVITATIONAL_H
#define GRAVITATIONAL_H

#include <QPointF>

class Gravitational
{
public:
    explicit Gravitational(qreal gravity = 0.098);

    //重力加速度的应用接口
    void applyGravity();

    void setGravity(qreal newGravity);
    qreal getGravity() const;
    bool isOnGround() const;
    void setOnGround(bool onGround);
    QPointF getVelocity() const;
    void setVelocity(const QPointF newVelocity);

protected:
    qreal gravity;
    bool onGround=false;
    QPointF velocity={0.0,0.0};
};

#endif // GRAVITATIONAL_H
