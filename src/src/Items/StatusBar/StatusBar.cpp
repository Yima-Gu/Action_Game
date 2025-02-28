//
// @brief: 实现展示玩家状态的面板
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-01
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "StatusBar.h"
#include "../Characters/Character.h"

//创建面板中的图标和数字
StatusBar::StatusBar(QGraphicsItem *parent,const QString &pixmapPath)
    :Item(parent, "://Items/Player/StatusBar.png")
{
    spareNormalArrow = new StatusIcon(this, "://Items/Arrow/spare_basic_arrow.png");
    spareNormalArrow->setPos(20,20);

    spareFireArrow =new StatusIcon(this, "://Items/Arrow/spare_fire_arrow.png");
    spareFireArrow->setPos(120,20);

    spareFrozenArrow= new StatusIcon(this, "://Items/Arrow/spare_freeze_arrow.png");
    spareFrozenArrow->setPos(220,20);

    spareThunderArrow= new StatusIcon(this, "://Items/Arrow/spare_thunder_arrow.png");
    spareThunderArrow->setPos(320,20);

    fireDefense= new StatusIcon(this, "://Items/SpecialEffects/fire_defense.png");
    fireDefense->setScale(0.5);
    fireDefense->setPos(250,130);

    QFont font;
    font.setPointSize(30);  // 设置字体大小为14

    normalNum= new QGraphicsTextItem(this);
    normalNum->setPos(80,20);
    normalNum->setFont(font);
    normalNum->setDefaultTextColor(Qt::black);

    fireNum= new QGraphicsTextItem(this);
    fireNum->setPos(180,20);
    fireNum->setFont(font);
    fireNum->setDefaultTextColor(Qt::black);

    // 创建 frozenNum
    frozenNum = new QGraphicsTextItem(this);
    frozenNum->setPos(280, 20);  // 横坐标在 fireNum 的基础上加 100
    frozenNum->setFont(font);
    frozenNum->setDefaultTextColor(Qt::black);

    // 创建 thunderNum
    thunderNum = new QGraphicsTextItem(this);
    thunderNum->setPos(380, 20); // 横坐标在 frozenNum 的基础上加 100
    thunderNum->setFont(font);
    thunderNum->setDefaultTextColor(Qt::black);

    frozenDefense= new StatusIcon(this, "://Items/SpecialEffects/freeze_defence.png");
    frozenDefense->setScale(0.5);
    frozenDefense->setPos(150,130);

    thunderDefense= new StatusIcon(this, "://Items/SpecialEffects/thunder_defence.png");
    thunderDefense->setScale(0.5);
    thunderDefense->setPos(50,130);
}

void  StatusBar::setOwner(Character* newOwner)
{
    if  (newOwner!=nullptr)
    {
        owner= newOwner;
    }
}

//根据玩家的状态更新游戏面板的显示
void StatusBar::update()
{
    if (owner!=nullptr)
    {
        normalNum->setPlainText(QString::number(owner->getArrowNum()[1]));
        fireNum->setPlainText(QString::number(owner->getArrowNum()[2]));
        frozenNum->setPlainText(QString::number(owner->getArrowNum()[3]));
        thunderNum->setPlainText(QString::number(owner->getArrowNum()[4]));

        // 设置所有箭和状态图标的初始不透明度为 0.3
        normalNum->setOpacity(0.3);
        fireNum->setOpacity(0.3);
        frozenNum->setOpacity(0.3);
        thunderNum->setOpacity(0.3);
        spareNormalArrow->setOpacity(0.3);
        spareFireArrow->setOpacity(0.3);
        spareFrozenArrow->setOpacity(0.3);
        spareThunderArrow->setOpacity(0.3);

        // 根据箭的类型设置对应箭和状态图标的不透明度为 1.0
        switch(owner->getArrowType()) {
        case 1: // Normal arrow
            normalNum->setOpacity(1.0);
            spareNormalArrow->setOpacity(1.0);
            break;
        case 2: // Fire arrow
            fireNum->setOpacity(1.0);
            spareFireArrow->setOpacity(1.0);
            break;
        case 3: // Frozen arrow
            frozenNum->setOpacity(1.0);
            spareFrozenArrow->setOpacity(1.0);
            break;
        case 4: // Thunder arrow
            thunderNum->setOpacity(1.0);
            spareThunderArrow->setOpacity(1.0);
            break;
        default:
            break;
        }

        fireDefense->setOpacity(0.3);
        thunderDefense->setOpacity(0.3);
        frozenDefense->setOpacity(0.3);

        if (owner->isFireDefense())
        {
            fireDefense->setOpacity(1);
        }
        if (owner->isFrozenDefense())
        {
            frozenDefense->setOpacity(1);
        }
        if (owner->isThunderDefnese())
        {
            thunderDefense->setOpacity(1);
        }

    }
}
