#ifndef WANNABECOMEARUNNER_H
#define WANNABECOMEARUNNER_H

#include <QWidget>
#include <widget.h>
#include <logindialog.h>
#include <runnercreate.h>
class Widget;
class LoginDialog;
class RunnerCreate;

namespace Ui {
class WannaBecomeARunner;
}

class WannaBecomeARunner : public QWidget
{
    Q_OBJECT

public:
    Widget * pBack;
    RunnerCreate * pRunnerCreate;
    explicit WannaBecomeARunner(QWidget *parent = 0);
    ~WannaBecomeARunner();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

private:
    Ui::WannaBecomeARunner *ui;
};

#endif // WANNABECOMEARUNNER_H
