//
// @brief: 实现游戏中木材质的弓
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "WoodBow.h"
#include "../../Characters/Character.h"

#include <QGraphicsScene>

WoodBow::WoodBow(QGraphicsItem *parent, const QString &pixmapPath) :Bow(parent,"://Items/Bow/wooden_bow.png")
{
    fireTimer = new QTimer(this);
    connect(fireTimer, &QTimer::timeout, this, &WoodBow::burnOut);
}

void WoodBow::mountToParent()
{
    Mountable::mountToParent();
    setPos(-30,-30);
    setRotation(15);
}

void WoodBow::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

int WoodBow::getBowType() const
{
    return 1;
}

int WoodBow::getBowRange() const
{
    return 10;
}

int WoodBow::getArrowNum() const
{
    return 1;
}

//实现木质弓的着火检测
void WoodBow::checkOnFire()
{
    if (!onFire)
    {
        QRectF woodRect = mapRectToScene(boundingRect());
        for (QGraphicsItem *item : scene()->items())
        {
            if (auto fire = dynamic_cast<FireEffect*>(item))
            {
                QRectF fireRect = fire->mapRectToScene(fire->boundingRect());
                if (woodRect.intersects(fireRect))
                {
                    fireTimer->start(3000);
                    showFire();
                    onFire=true;
                }
            }
        }
    }
}

//木材质弓的燃尽槽函数
void WoodBow::burnOut()
{
    if (this->isMounted())
    {
        if (auto owner=dynamic_cast<Character*>(parentItem()))
        {
            owner->deleteBow();
            return;
        }
    }
    this->deleteLater();
}

void WoodBow::showFire()
{
    auto fire=new FireEffect(this);
    scene()->addItem(fire);
    fire->setParentItem(this);
    fire->mountToParent();
    fire->setPos(-7,-20);
}

bool WoodBow::isMetal() const
{
    return 0;
}
