#ifndef WOODSWORD_H
#define WOODSWORD_H
#include "../Weapon.h"

class WoodSword:public Weapon
{
    Q_OBJECT
public:
    explicit WoodSword(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;

    void unmount() override;

    int getDamageValue() const override;

    //void update() override;

    void checkOnFire();

    bool isMetal() const override;

private:
    QTimer* fireTimer;

    bool onFire{false};

    void showFire();

private slots:
    void burnOut();

};

#endif // WOODSWORD_H
