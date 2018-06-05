#ifndef BMR_H
#define BMR_H

#include <QWidget>
#include <stylesheets.h>
#include <more_info.h>
class more_info;

namespace Ui {
class BMR;
}

class BMR : public QWidget
{
    Q_OBJECT

public:
    more_info * pBack;
    explicit BMR(QWidget *parent = 0);
    ~BMR();

private slots:

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_clicked();

private:
    Ui::BMR *ui;
};

#endif // BMR_H
