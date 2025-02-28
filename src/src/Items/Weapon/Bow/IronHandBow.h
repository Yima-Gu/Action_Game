//
// @brief: 铁材质的连发弓弩
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef IRONHANDBOW_H
#define IRONHANDBOW_H

#include "../Bow.h"
#include <QTimer>

class IronHandBow : public Bow
{
public:

    IronHandBow(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;
    void unmount() override;
    int getBowType() const override;
    int getBowRange() const override;
    int getArrowNum() const override;
    bool isMetal() const override;
};

#endif // IRONHANDBOW_H
