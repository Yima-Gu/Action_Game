#ifndef SWORD_H
#define SWORD_H

#include "../Weapon.h"

class Sword:public Weapon
{
public:
    explicit Sword(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;

    int getDamageValue() const override;

    bool isMetal() const override;
};

#endif // SWORD_H
