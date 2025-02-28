//
// @brief: 实现游戏中的木质平台，实现燃烧、传递和消失
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "WoodPlatform.h"
#include "../SpecialEffect/FireEffect.h"

#include <QGraphicsScene>

WoodPlatform::WoodPlatform(QGraphicsItem *parent , const QString &imagePath)
{
    fireTimer = new QTimer (this);
    pixmap.load("://Items/Platform/WoodPlatform.png");
    connect(fireTimer, &QTimer::timeout, this, &WoodPlatform::burnOut);
}

void WoodPlatform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(0, 0, width, height, pixmap);
}

//木质平台的燃烧和燃尽方法
void WoodPlatform::setOnFire()
{
    onFire = true;
    fireTimer->start(3000);
}

void WoodPlatform::burnOut()
{
    emit woodPlatformBurnOut();
    this->deleteLater();
}

void WoodPlatform::getBurnt(QPointF burnPoint)
{
    QPointF tempPos=burnPoint;
    tempPos.setY(burnPoint.y()-60);
    auto fire =new FireEffect(this);
    QPointF localPos = this->mapFromScene(tempPos);
    fire ->setPos(localPos);
    scene()->addItem(fire);
    this->setOnFire();
}

