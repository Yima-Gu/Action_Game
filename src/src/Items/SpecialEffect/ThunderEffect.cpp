//
// @brief: 实现游戏中电击效果的贴图
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-08-25
// @history:
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "ThunderEffect.h"

ThunderEffect::ThunderEffect(QGraphicsItem *parent, const QString &imagePath)
    :Item(parent, "://Items/SpecialEffects/be_thunder.png")
{

}

void ThunderEffect::mountToParent()
{
    Mountable::mountToParent();
    this->setOpacity(0.7);
    setPos(-20,-20);
}

void ThunderEffect::update()
{

}
