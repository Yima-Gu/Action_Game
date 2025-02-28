//
// @brief:实现游戏中的弓的基类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "Bow.h"
#include "../Characters/Character.h"
#include "Arrow/NormalArrow.h"
#include "Arrow/FireArrow.h"
#include "Arrow/FrozenArrow.h"
#include "Arrow/ThunderArrow.h"

#include <QGraphicsScene>


Bow::Bow(QGraphicsItem *parent, const QString &pixmapPath) : GravityMountableItem(parent, pixmapPath)
{

}

//弓射出箭的方法
void Bow::bowFireArrow(int bowArrowNum, int bowArrowType)
{
    for (int i=0;i<bowArrowNum;i++)
    {
        Arrow* arrow=nullptr;
        //申请的内存的BattleScene中管理
        switch(bowArrowType)
        {
        case 1:
            arrow = new NormalArrow();
            break;
        case 2:
            arrow = new FireArrow();
            break;
        case 3:
            arrow = new FrozenArrow();
            break;
        case 4:
            arrow = new ThunderArrow();
            break;
        }

        if (parentItem()!=nullptr&&arrow!=nullptr)
        {
            QPointF tempPos=parentItem()->pos();
            tempPos.setY(tempPos.y()-10);
            arrow->setPos(tempPos);
            scene()->addItem(arrow);
            arrow->unmount();
            arrow->gravityHandler.setOnGround(false);
            arrow->setOwner(dynamic_cast<Character *>(parentItem()));
            qreal rotationAngle = dynamic_cast<Character *>(parentItem())->getRotationAngle();
            if (rotationAngle >= -90 && rotationAngle <= 90)
            {
                arrow->gravityHandler.setVelocity(QPointF(-this->getBowRange(),-2));
            }
            else
            {
                arrow->gravityHandler.setVelocity(QPointF(this->getBowRange(),-2));
            }
        }
    }
}
