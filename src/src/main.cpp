//
// @brief: 主程序入口，创建并显示游戏窗口
// @author: Gu Yima
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-03
// @history:
//   - V0.1.0: Initial version created by Ling Jingwang on 2024-08-21
//   - V1.0.0: Revised by Gu Yima on 2024-09-03
//


#include "MyGame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyGame myGame;
    myGame.show();
    return QApplication::exec();
}
