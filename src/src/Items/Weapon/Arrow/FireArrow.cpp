//
// @brief: 实现游戏中的火箭
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "FireArrow.h"
#include "../../Characters/Character.h"
#include "../../Platfrom/WoodPlatform.h"

#include <QGraphicsScene>

FireArrow::FireArrow(QGraphicsItem *parent, const QString &pixmapPath):Arrow(parent,"://Items/Arrow/fire_arrow.png")
{

}

int FireArrow::getDamageValue() const
{
    return 10;
}

//在击中人物时，给人物设置为着火状态
bool FireArrow::InjuryDetector()
{
    Arrow::InjuryDetector();

    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    for (QGraphicsItem* item : collidingItems)
    {
        auto character = dynamic_cast<Character*>(item);

        if (character!=nullptr
            && character!= this->getOwner())
        {
            character->setOnfire(true);
            return true;
        }
    }
    return false;
}

//在击中木质平台时，获取击中的坐标，发出信号给平台来创建着火特效
void FireArrow::update()
{
    Arrow::update();
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    for (QGraphicsItem* item : collidingItems)
    {
        WoodPlatform* woodPlatform = dynamic_cast<WoodPlatform*>(item);

        if (woodPlatform != nullptr)
        {
            QRectF weaponRect = mapRectToScene(boundingRect());
            QRectF platformRect = woodPlatform->mapRectToScene(woodPlatform->boundingRect());

            if (weaponRect.bottom() >= platformRect.top() && weaponRect.bottom() <= platformRect.bottom())
            {
                // 确认碰撞，获取碰撞区域
                QPainterPath arrowPath = mapToScene(shape());
                QPainterPath platformPath = woodPlatform->mapToScene(woodPlatform->shape());

                // 获取交集区域
                QPainterPath intersection = arrowPath.intersected(platformPath);
                QRectF collisionRect = intersection.boundingRect();

                if (!intersection.isEmpty())
                {
                    this->connectSignalSlot();

                    QPointF collisionPoint = collisionRect.center(); // 碰撞点，可以选择中心点
                    emit hitWood(collisionPoint);

                    return; // 已经找到平台并处理，退出循环
                }
            }
        }
    }
}

//链接信号和槽
void FireArrow::connectSignalSlot()
{
    if (scene()!=nullptr)
    {
        foreach (QGraphicsItem* item, scene()->items())
        {
            // 使用 dynamic_cast 检查项是否为 WoodPlatform 类的实例
            WoodPlatform* woodPlatform = dynamic_cast<WoodPlatform*>(item);
            if (woodPlatform != nullptr)
            {
                connect(this, &FireArrow::hitWood, woodPlatform, &WoodPlatform::getBurnt);
            }
        }
    }
}
