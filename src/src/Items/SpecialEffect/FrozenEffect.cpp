//
// @brief: 实现游戏中冰冻效果的贴图
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#include "FrozenEffect.h"

FrozenEffect::FrozenEffect(QGraphicsItem *parent, const QString &imagePath)
    :Item(parent,"://Items/SpecialEffects/be_freeze.png")
{

}

void FrozenEffect::mountToParent()
{
    Mountable::mountToParent();
    this->setOpacity(0.7);
    setPos(-20,-10);
}

void FrozenEffect::update()
{
    qDebug()<<19;
}

