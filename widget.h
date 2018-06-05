#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <stylesheets.h>
#include <QPushButton>
#include <more_info.h>
#include <wannabecomearunner.h>
#include <logindialog.h>
#include <donatesponsor.h>
class more_info;
class WannaBecomeARunner;
class LoginDialog;
class DonateSponsor;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    DonateSponsor * pDonateSponsor;
    WannaBecomeARunner * pWannaBecomeARunner;
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    static bool tryToConnect();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

private:
    Ui::Widget *ui;
    more_info * info;
};

#endif // WIDGET_H
