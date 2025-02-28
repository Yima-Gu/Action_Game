//
// @brief: 作为所有属性的箭的基类，实现运动和箭的攻击
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Arrow.h"
#include "../Platfrom/Platform.h"
#include "../Characters/Character.h"

#include <QGraphicsScene>

Arrow::Arrow(QGraphicsItem *parent, const QString &pixmapPath) : GravityMountableItem(parent, pixmapPath)
{

}

//更新箭的运动
void Arrow::update()
{
    gravityHandler.applyGravity();

    QPointF velocity = gravityHandler.getVelocity();
    setPos(pos() + velocity);
    qreal angle = std::atan2(velocity.y(), velocity.x()) * (180.0 / M_PI);
    setRotation(angle+180);

    QList<QGraphicsItem*> collidingItems = this->collidingItems();

    if (this->InjuryDetector())
    {
        gravityHandler.setVelocity(QPointF(0.0, 0.0)); // 重置速度
        gravityHandler.setOnGround(true); // 设置为在地面上
        qDebug()<<9;
        return;
    }
    else
    {
        //遍历每个碰撞项，检查是否是 Platform 类型
        for (QGraphicsItem* item : collidingItems)
        {
            Platform* platform = dynamic_cast<Platform*>(item);
            // 获取平台的边界矩形，并转换为全局坐标
            if (platform)
            {
                QRectF weaponRect = mapRectToScene(boundingRect());
                QRectF platformRect = platform->mapRectToScene(platform->boundingRect());

                if (weaponRect.bottom() >= platformRect.top()
                    &&weaponRect.bottom()<=platformRect.bottom())
                {
                    gravityHandler.setVelocity(QPointF(0.0, 0.0)); // 重置速度
                    gravityHandler.setOnGround(true); // 设置为在地面上
                    setRotation(0);
                    return; // 已经找到平台并处理，退出循环
                }
            }
        }
    }
}


bool Arrow::InjuryDetector()
{

    QRectF weaponRect = mapRectToScene(boundingRect());
    for (QGraphicsItem *item : scene()->items())
    {
        if (auto character = dynamic_cast<Character*>(item))
        {
            QRectF characterRect = character->mapRectToScene(character->boundingRect());
            if (weaponRect.intersects(characterRect)
                &&character!=this->getOwner())
            {
                character->setHealth(character->getHealth()-this->getDamageValue());
                gravityHandler.setVelocity(QPointF(0.0, 0.0)); // 重置速度
                gravityHandler.setOnGround(true);
                return true;
            }
        }
    }
    return false;
}

const Character* Arrow::getOwner() const
{
    return owner;
}


void Arrow::setOwner(Character* newOwner)
{
    owner=newOwner;
}
