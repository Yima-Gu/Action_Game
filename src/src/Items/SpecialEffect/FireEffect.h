//
// @brief: 本文件实现火焰特效
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef FIREEFFECT_H
#define FIREEFFECT_H

#include "../Item.h"
#include "../Mountable.h"
#include <QTimer>

class FireEffect: public QObject, public Item, public Mountable
{
    Q_OBJECT
public:
    explicit FireEffect (QGraphicsItem *parent = nullptr, const QString &imagePath = "");

    void mountToParent() override;
    void update() override;

    //getter和setter接口
    bool isExtingished() const;
    void setExtingished(bool newCondition);

    //显示边界，用来debug
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    //在木质平台上点火的信号
    void setFire(QPointF);

private slots:
    //静态计时器用来控制火焰传播的时延
    void resetCooling();

private:
    static QTimer* timer;
    static bool isCooling;

    //bool量来确保链接信号和销毁对象
    bool isConnected {false};
    bool extinguished {false};

    void connectSignalSlot();
};

#endif // FIREEFFECT_H
