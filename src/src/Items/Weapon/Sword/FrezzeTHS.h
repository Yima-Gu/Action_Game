#ifndef FREZZETHS_H
#define FREZZETHS_H

#include "../Weapon.h"

#include <QTimer>

class FreezeTHS : public Weapon
{
    Q_OBJECT

public:
    explicit FreezeTHS(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;

    int getDamageValue () const override;

    void Attack() override;

    void Reversion() override;

    void InjuryDetector() override;

    bool isMetal() const override;

private:
    bool isCoolingDown = false; // 冷却状态
    //int attackDirection = 1; // 攻击方向，1代表面向方向，-1代表背向方向
    //const int attackDelay = 500; // 攻击延迟时间，单位毫秒

    int AttackStage=0;

    QTimer* timer;

private slots:
    void performAttack();
};

#endif // FREZZETHS_H
