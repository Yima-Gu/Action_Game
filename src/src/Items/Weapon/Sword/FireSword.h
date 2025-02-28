#ifndef FIRESWORD_H
#define FIRESWORD_H

#include "../Weapon.h"

class FireSword: public Weapon
{
public:
    explicit FireSword(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;

    int getDamageValue() const override;

    void InjuryDetector() override;

    bool isMetal() const override;
};

#endif // FIRESWORD_H
