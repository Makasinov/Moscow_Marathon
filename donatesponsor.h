#ifndef DONATESPONSOR_H
#define DONATESPONSOR_H

#include <QWidget>
#include <widget.h>
class Widget;

namespace Ui {
class DonateSponsor;
}

class DonateSponsor : public QWidget
{
    Q_OBJECT

public:
    Widget * pBack;
    explicit DonateSponsor(QWidget *parent = 0);
    ~DonateSponsor();

private slots:
    void on_pushButton_released();

    void on_pushButton_pressed();

private:
    Ui::DonateSponsor *ui;
};

#endif // DONATESPONSOR_H
