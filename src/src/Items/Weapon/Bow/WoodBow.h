//
// @brief: 木材质的弓
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef WOODBOW_H
#define WOODBOW_H

#include "../Bow.h"

class WoodBow :public Bow
{
    Q_OBJECT
public:
    WoodBow(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");

    void mountToParent() override;
    void unmount() override;
    int getBowType() const override;
    int getBowRange() const override;
    int getArrowNum() const override;
    bool isMetal() const override;

    //检查木质弓是否会着火的方法
    void checkOnFire();

private:
    //计时器以及与着火相关的变量
    QTimer* fireTimer;
    bool onFire{false};
    void showFire();

private slots:
    //私有槽函数，判断木质弓何时燃尽
    void burnOut();
};

#endif // WOODBOW_H
