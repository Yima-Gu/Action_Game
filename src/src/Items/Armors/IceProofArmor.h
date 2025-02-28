//
// @brief: 本文件是具体的冰属性的防护护甲
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef ICEPROOFARMOR_H
#define ICEPROOFARMOR_H

#include "../GravityMountableItem.h"

class IceProofArmor: public GravityMountableItem
{
public:
    explicit IceProofArmor(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;
};

#endif // ICEPROOFARMOR_H
