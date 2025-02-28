//
// @brief: 实现游戏中的燃烧特效，以及燃烧效果的传递
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "FireEffect.h"
#include "../Platfrom/WoodPlatform.h"

#include <QGraphicsScene>

// 初始化静态成员
QTimer* FireEffect::timer = nullptr;
bool FireEffect::isCooling = false;

FireEffect::FireEffect(QGraphicsItem *parent, const QString &imagePath)
    :Item(parent, "://Items/SpecialEffects/be_fire.png")
{
    if (timer == nullptr)
    {
        timer = new QTimer(this);
        timer->setSingleShot(true);
        connect(timer, &QTimer::timeout, this, &FireEffect::resetCooling);
    }

}

void FireEffect::mountToParent()
{
    Mountable::mountToParent();
    this->setOpacity(0.7);
    setPos(-15,-20);
}

//实现火焰与木质平台，火焰与木质武器以及人物之间的传递
void FireEffect::update()
{
    if (!isConnected)
    {
        this->connectSignalSlot();
        isConnected=true;
    }
    if (!isCooling&&this->isMounted())
    {
        qDebug()<<"find wood";
        QList<QGraphicsItem*> collidingItems = this->collidingItems();
        for (QGraphicsItem* item : collidingItems)
        {
            WoodPlatform* woodPlatform = dynamic_cast<WoodPlatform*>(item);

            if (woodPlatform != nullptr)
            {
                QRectF weaponRect = mapRectToScene(boundingRect());
                QRectF platformRect = woodPlatform->mapRectToScene(woodPlatform->boundingRect());
                qDebug()<<"find wood";

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
                        QPointF collisionPoint = collisionRect.center(); // 碰撞点，可以选择中心点
                        emit setFire(collisionPoint);
                        //woodPlatform->getBurnt(collisionPoint);
                        isCooling=true;
                        timer->start(1000);
                        return; // 已经找到平台并处理，退出循环
                    }
                }
            }
        }
    }

}

void FireEffect::connectSignalSlot()
{
    if (scene()!=nullptr)
    {
        foreach (QGraphicsItem* item, scene()->items())
        {
            // 使用 dynamic_cast 检查项是否为 WoodPlatform 类的实例
            WoodPlatform* woodPlatform = dynamic_cast<WoodPlatform*>(item);
            if (woodPlatform != nullptr)
            {
                qDebug() <<"connected";
                connect(this, &FireEffect::setFire, woodPlatform, &WoodPlatform::getBurnt);
            }
        }
    }
}

void FireEffect::resetCooling()
{
    isCooling=false;
}

bool FireEffect::isExtingished() const
{
    return extinguished;
}

void FireEffect::setExtingished(bool newCondition)
{
    extinguished=newCondition;
}

//only for debugging
/*
void FireEffect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This function will paint the FireEffect's bounding rectangle
    // Modify this function to actually draw the effect if needed
    painter->setPen(Qt::red); // Set the pen color to red
    painter->drawRect(boundingRect()); // Draw the bounding rectangle

    // You can also add custom drawing code here for the fire effect
    // e.g., using the m_imagePath to load and draw an image
}
*/
