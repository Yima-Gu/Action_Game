//
// @brief: 游戏主窗口类，实现游戏窗口的创建、场景管理和作弊码功能
// @author: Gu Yima
// @version: V1.1.0
// @revision: last revised by Gu Yima on 2024-09-03
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-03, added basic game setup and gameover handling
//   - V1.1.0: Revised by Gu Yima on 2024-09-03, added cheat code dialog and integration with battle scene
//


#include "MyGame.h"
#include "Scenes/BattleScene.h"
#include "CheatCode/CheatCodeDialog.h"

#include <QMessageBox>
#include <QApplication>
#include <QPushButton>

// 构造函数，初始化游戏主窗口
MyGame::MyGame(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建战斗场景并将其设置为当前视图
    battleScene = new BattleScene(this);
    view = new QGraphicsView(this);
    view->setScene(battleScene);

    // 设置视图的窗口大小为 1280x720
    view->setFixedSize((int) view->scene()->width(), (int) view->scene()->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 将视图设置为中央控件
    setCentralWidget(view);
    // 调整主窗口大小以适应 QGraphicsView
    setFixedSize(view->sizeHint());
    battleScene->startLoop(); // 启动游戏循环

    // 确保 battleScene 是 BattleScene 类型的指针
    auto actualBattleScene = qobject_cast<BattleScene*>(battleScene);
    if (actualBattleScene != nullptr)
    {
        // 连接战斗场景的游戏结束信号到 MyGame 的 gameover 槽函数
        connect(actualBattleScene, &BattleScene::gameoverSignal, this, &MyGame::gameover);
    }

    // 创建 CheatCodeManager 对象
    if (actualBattleScene != nullptr)
    {
        cheatCodeManager = new CheatCodeManager(actualBattleScene);
    }

    // 创建并设置一个按钮以打开作弊码对话框
    QPushButton *openCheatCodeDialogButton = new QPushButton("CheatCode", this);
    openCheatCodeDialogButton->setFixedSize(100, 30); // 按钮大小为 100x30 像素

    // 连接按钮点击事件到显示作弊码对话框的逻辑
    connect(openCheatCodeDialogButton, &QPushButton::clicked, [this]()
            {
                CheatCodeDialog dialog(cheatCodeManager, this);
                dialog.exec();
            });
}

// 游戏结束处理函数，根据赢家显示不同的消息并退出程序
void MyGame::gameover(int winner)
{
    QMessageBox::StandardButton reply;
    switch (winner)
    {
    case 0:
        reply = QMessageBox::information(this, "游戏结束", "Enemy胜利！", QMessageBox::Ok);
        if (reply == QMessageBox::Ok)
        {
            QApplication::quit();
        }
        break;
    case 1:
        reply = QMessageBox::information(this, "游戏结束", "Link胜利！", QMessageBox::Ok);
        if (reply == QMessageBox::Ok)
        {
            QApplication::quit();
        }
        break;
    }
}
