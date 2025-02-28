//
// @brief: 本文件用来实现作弊码输入的对话框
// @author: Gu Yima
// @birth: created by Gu Yima on 2024-09-02
// @version: V1.0.0
// @revision: last revised by Gu Yima on 2024-09-02
//


#ifndef CHEATCODEDIALOG_H
#define CHEATCODEDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "../Items/CheatCodeManager.h"

class CheatCodeDialog : public QDialog
{
    Q_OBJECT

public:
    CheatCodeDialog(CheatCodeManager *manager, QWidget *parent = nullptr);

private slots:
    void onApplyButtonClicked();

private:
    QLineEdit *cheatCodeLineEdit;
    QPushButton *applyButton;
    CheatCodeManager *cheatCodeManager;
};

#endif // CHEATCODEDIALOG_H
