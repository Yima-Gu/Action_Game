//
// @brief: 实现游戏中木属性的近战武器，实现燃烧相关的方法
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "WoodSword.h"
#include "../../Characters/Character.h"
#include "../../SpecialEffect/FireEffect.h"

#include <QGraphicsScene>

WoodSword::WoodSword(QGraphicsItem *parent, const QString &pixmapPath) :Weapon(parent,"://Items/Weapon/wooden_short_sword.png")
{
    fireTimer = new QTimer(this);
    connect(fireTimer, &QTimer::timeout, this, &WoodSword::burnOut);
}

void WoodSword::mountToParent()
{
    Mountable::mountToParent();
    setScale(1);
    setPos(-30,-50);

    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(-45);
}

void WoodSword::unmount()
{
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);

}

int WoodSword::getDamageValue() const
{
    return 10;
}

//检查是否着火
void WoodSword::checkOnFire()
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

//燃尽的方法
void WoodSword::burnOut()
{
    if (this->isMounted())
    {
        if (auto owner=dynamic_cast<Character*>(parentItem()))
        {
            owner->deleteWeapon();
            return;
        }
    }
    this->deleteLater();
}

void WoodSword::showFire()
{
    auto fire=new FireEffect(this);
    scene()->addItem(fire);
    fire->setParentItem(this);
    fire->mountToParent();
    fire->setPos(-7,-20);
}

bool WoodSword::isMetal() const
{
    return 0;
}
