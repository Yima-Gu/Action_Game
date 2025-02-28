//
// @brief: 主要的游戏主窗口类定义，继承自 QMainWindow，提供游戏视图和场景管理功能
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-02
//

#ifndef QT_PROGRAMMING_2024_MYGAME_H
#define QT_PROGRAMMING_2024_MYGAME_H

#include "Scenes/Scene.h"
#include "Items/CheatCodeManager.h"

#include <QGraphicsView>
#include <QMainWindow>

class MyGame : public QMainWindow
{
Q_OBJECT

public:
    explicit MyGame(QWidget *parent = nullptr);

public slots:
    void gameover(int winner);

private:
    Scene *battleScene;
    QGraphicsView *view;
    CheatCodeManager* cheatCodeManager;
};

#endif //QT_PROGRAMMING_2024_MYGAME_H
