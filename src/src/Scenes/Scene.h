//
// @brief: 主要的战斗场景类定义，继承自 QGraphicsScene，提供游戏循环和场景更新功能
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#ifndef QT_PROGRAMMING_2024_SCENE_H
#define QT_PROGRAMMING_2024_SCENE_H

#include <QGraphicsScene>
#include <QTimer>

class Scene : public QGraphicsScene
{
Q_OBJECT

public:
    explicit Scene(QObject *parent);

    //启动定时器，开始游戏循环。
    void startLoop();

    //处理游戏中的输入，拾起，移动
    virtual void processInput();
    virtual void processMovement();
    virtual void processPicking();

protected slots:
    //用于更新场景，通常会在定时器超时时调用。
    virtual void update();

protected:
    //记录自上次更新以来的时间差，用于处理基于时间的运动和动画
    qint64 deltaTime{};

private:
    QTimer *timer;
    qint64 lastTime{-1};
};


#endif //QT_PROGRAMMING_2024_SCENE_H
