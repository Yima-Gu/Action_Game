#ifndef THUNDERSWORD_H
#define THUNDERSWORD_H

#include "../Weapon.h"

class ThunderSword: public Weapon
{
public:
    explicit ThunderSword(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;

    int getDamageValue() const override;

    void InjuryDetector() override;

    bool isMetal() const override;
};

#endif // THUNDERSWORD_H
