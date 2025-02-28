#ifndef IRONSTAFF_H
#define IRONSTAFF_H

#include "../Weapon.h"

class IronStaff: public Weapon
{
public:
    explicit IronStaff(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;

    int getDamageValue() const override;

    void Attack() override;

    void Reversion() override;

    bool isMetal() const override;
};

#endif // IRONSTAFF_H
