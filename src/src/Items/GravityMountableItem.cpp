//
// @brief: 实现重力和可挂载的物体的基类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "GravityMountableItem.h"

#include <QGraphicsScene>
#include "Platfrom/Platform.h"

GravityMountableItem::GravityMountableItem(QGraphicsItem *parent, const QString &pixmapPath)
    :Item(parent, pixmapPath)
{

}

void GravityMountableItem::update()
{
    bool isTouchingAirPlatform = false;
    if (gravityHandler.isOnGround())
    {
        QRectF characterRect = mapRectToScene(boundingRect());

        for (QGraphicsItem *item : scene()->items())
        {
            if (auto platform = dynamic_cast<Platform*>(item))
            {
                // 获取平台的边界矩形，并转换为全局坐标
                QRectF platformRect = platform->mapRectToScene(platform->boundingRect());

                // 检测角色与平台是否发生碰撞
                if (characterRect.intersects(platformRect)&&
                    characterRect.bottom()<platformRect.bottom())
                {
                    // 处理碰撞
                    isTouchingAirPlatform=true;
                    break;
                }
            }
        }

        if (!isTouchingAirPlatform)
        {
            gravityHandler.setOnGround((false));
        }
    }

    gravityHandler.applyGravity();

    QPointF velocity = gravityHandler.getVelocity();
    setPos(pos() + velocity);



    QList<QGraphicsItem*> collidingItems = this->collidingItems();

    // 遍历每个碰撞项，检查是否是 Platform 类型
    for (QGraphicsItem* item : collidingItems)
    {
        Platform* platform = dynamic_cast<Platform*>(item);

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
