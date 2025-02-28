//
// @brief: 实现游戏中的重力系统
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Gravitational.h"

Gravitational::Gravitational(qreal gravity)
    : gravity(gravity)
{
}

void Gravitational::setGravity(qreal newGravity)
{
    gravity = newGravity;
}

qreal Gravitational::getGravity() const
{
    return gravity;
}

void Gravitational::applyGravity()
{
    if (!onGround)
    {
        velocity.setY(velocity.y() + gravity);
    }
}


void Gravitational::setOnGround(bool onGround)
{
    Gravitational::onGround=onGround;
}

QPointF Gravitational::getVelocity() const
{
    return velocity;
}

void Gravitational::setVelocity(const QPointF newVelocity)
{
    velocity=newVelocity;
}

bool Gravitational::isOnGround() const
{
    return onGround;
}
