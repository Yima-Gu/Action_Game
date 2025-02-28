//
// @brief: 金属材质的平台，实现传导电流的方法
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//

#ifndef METALPLATFORM_H
#define METALPLATFORM_H

#include "AirPlatform.h"
#include "../SpecialEffect/ThunderEffect.h"

class MetalPlatform:public AirPlatform
{
public:
    explicit MetalPlatform (QGraphicsItem *parent = nullptr, const QString &imagePath = "");

    //用于检测和传导电流的接口
    void ThunderDetector();

    //绘制边框
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    //保存图片
    QPixmap pixmap;

    //处理平台是否带电展示带电状态的方法
    bool withThunder {false};
    void showThunder();
    ThunderEffect* thunderEffect {nullptr};
};

#endif // METALPLATFORM_H
