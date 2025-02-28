// CheatCodeDialog.cpp
// @brief: 实现 CheatCodeDialog 类，用于用户输入作弊码并应用。
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02

#include "CheatCodeDialog.h"

#include <QVBoxLayout>

// 构造函数，初始化作弊码输入框和应用按钮，并设置布局。
CheatCodeDialog::CheatCodeDialog(CheatCodeManager *manager, QWidget *parent)
    : QDialog(parent), cheatCodeManager(manager)
{
    // 创建输入框和按钮
    cheatCodeLineEdit = new QLineEdit(this);
    applyButton = new QPushButton("Apply Cheat Code", this);

    // 设置垂直布局，并添加输入框和按钮
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(cheatCodeLineEdit);
    layout->addWidget(applyButton);

    // 设置布局
    setLayout(layout);

    // 连接按钮点击信号到槽函数
    connect(applyButton, &QPushButton::clicked, this, &CheatCodeDialog::onApplyButtonClicked);
}

// 槽函数，处理应用按钮点击事件，获取输入的作弊码并应用
void CheatCodeDialog::onApplyButtonClicked()
{
    QString cheatCode = cheatCodeLineEdit->text(); // 获取输入的作弊码
    cheatCodeManager->applyCheatCode(cheatCode);   // 调用管理器应用作弊码
    accept(); // 关闭对话框
}
