//
// @brief: 木质的平台，实现燃烧的相关方法
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef WOODPLATFORM_H
#define WOODPLATFORM_H

#include "AirPlatform.h"
#include <QTimer>

class WoodPlatform:public QObject, public AirPlatform
{
    Q_OBJECT
public:
    explicit WoodPlatform (QGraphicsItem *parent = nullptr, const QString &imagePath = "");

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    //点燃平台的接口
    void setOnFire();

protected:
    QPixmap pixmap;
    bool onFire {false};
    //内部计时器，燃尽时发信号
    QTimer* fireTimer{nullptr};

private slots:
    //私有槽函数，用于燃尽时处理内存
    void burnOut();

public slots:
    //接收火特效与木平台接触的信号
    void getBurnt(QPointF burnPoint);

signals:
    //燃尽的信号
    void woodPlatformBurnOut();
};

#endif // WOODPLATFORM_H
