#ifndef CALYH_H
#define CALYH_H

#include <QDialog>
#include "arcsin.h"
#include "sin.h"

namespace Ui {
class CalYh;
}

class CalYh : public QDialog
{
    Q_OBJECT

public:
    explicit CalYh(QWidget *parent = 0);
    ~CalYh();

private:
    Ui::CalYh *ui;
    void layoutYh();
    QString s;//控件显示的字符串
    bool isClear;//判断已经按过sin/cos/arcsin/arctan按钮，按过表示true，默认ture
    int isNeg;//判断按过几次符号，只能输入一次符号，默认为0

    Sin *sinFunc;
    ArcSin *arcsinYh;
};

#endif // CALYH_H
