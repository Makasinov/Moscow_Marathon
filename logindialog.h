#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <qdebug.h>
#include <widget.h>
#include <runnercreate.h>
class Widget;
class RunnerCreate;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_buttonBox_rejected();

    void on_LoginDialog_destroyed();

    void on_LoginDialog_accepted();

    void on_LoginDialog_rejected();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
