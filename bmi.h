#ifndef BMI_H
#define BMI_H

#include <QWidget>
#include <stylesheets.h>
#include <more_info.h>
class more_info;

namespace Ui {
class BMI;
}

class BMI : public QWidget
{
    Q_OBJECT

public:
    more_info * pBack;
    explicit BMI(QWidget *parent = 0);
    ~BMI();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_clicked();

private:
    Ui::BMI *ui;
};

#endif // BMI_H
