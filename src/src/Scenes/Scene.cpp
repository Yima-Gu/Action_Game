//
// @brief: 实现作战场景的基类
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//


#include "Scene.h"

#include <QDateTime>

Scene::Scene(QObject *parent) : QGraphicsScene(parent), timer(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &Scene::update);
}

//计算当前时间与上次更新时间的时间差（deltaTime），用于处理时间相关的操作。
//调用 processInput()、processMovement() 和 processPicking()，处理输入、移动和拾取操作。
void Scene::update()
{
    auto currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    if (lastTime == -1)
    { // first frame
        deltaTime = 0;
    }
    else
    {
        deltaTime = currentTime - lastTime;
    }
    lastTime = currentTime;

    processInput();
    processMovement();
    processPicking();
}

void Scene::startLoop()
{
    timer->start(1000 / 90); // 90FPS
}

void Scene::processInput() {

}

void Scene::processMovement()
{

}

void Scene::processPicking() {

}

