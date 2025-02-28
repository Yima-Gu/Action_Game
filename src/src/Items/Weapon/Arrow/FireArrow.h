//
// @brief: 火属性的箭
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef FIREARROW_H
#define FIREARROW_H

#include "../Arrow.h"

class FireArrow: public Arrow
{
    Q_OBJECT
public:
    explicit FireArrow(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    //重载伤害值，更新和伤害监测方法
    int getDamageValue() const override;
    void update() override;
    bool InjuryDetector() override;

signals:
    //在击中木质平台时发出信号
    void hitWood(QPointF);

private:
    void connectSignalSlot();
};

#endif // FIREARROW_H
