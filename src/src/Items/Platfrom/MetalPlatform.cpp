//
// @brief: 实现游戏中的金属质地的平台，实现电传导的方法
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "MetalPlatform.h"
#include "../Characters/Character.h"

#include <QGraphicsScene>

MetalPlatform::MetalPlatform(QGraphicsItem *parent, const QString &imagePath)
    : AirPlatform(parent)
{
    pixmap.load("://Items/Platform/IronPlatform.png");
}


//检测是否处于带电状态，并且传导电流
void MetalPlatform::ThunderDetector()
{
    bool tempThunder=false;
    QRectF platformRect = mapRectToScene(boundingRect());
    for (QGraphicsItem *item : scene()->items())
    {
        if (auto character = dynamic_cast<Character*>(item))
        {
            QRectF characterRect = character->mapRectToScene(character->boundingRect());
            if (platformRect.intersects(characterRect)
                &&character->isStruck())
            {
                tempThunder=true;
            }
        }
    }

    withThunder=tempThunder;

    if (tempThunder)
    {
        for (QGraphicsItem *item : scene()->items())
        {
            if (auto character = dynamic_cast<Character*>(item))
            {
                QRectF characterRect = character->mapRectToScene(character->boundingRect());
                if (platformRect.intersects(characterRect)
                    &&!character->isStruck())
                {
                    character->setStruck(true);
                }
            }
        }
    }
    this->showThunder();
}

//展示电流特效
void MetalPlatform::showThunder()
{
    if (thunderEffect==nullptr
        &&withThunder)
    {
        thunderEffect = new ThunderEffect();
        thunderEffect->mountToParent();
        thunderEffect->setParentItem(this);
        thunderEffect->setPos(150,0);
        thunderEffect->setOpacity(1);
    }
    if (!withThunder
        &&thunderEffect!=nullptr)
    {
        thunderEffect->deleteLater();
        thunderEffect=nullptr;
    }
}


void MetalPlatform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(0, 0, width, height, pixmap);
}
