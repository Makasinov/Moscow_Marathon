#ifndef MORE_INFO_H
#define MORE_INFO_H

#include <QPushButton>
#include <QWidget>
#include <widget.h>
#include <previous_results.h>
#include <about_ms.h>
#include <bmr.h>
#include <bmi.h>
#include <sponsorslist.h>
class Widget;
class Previous_results;
class About_MS;
class BMR;
class BMI;
class SponsorsList;

namespace Ui {
class more_info;
}

class more_info : public QWidget
{
    Q_OBJECT

public:
    SponsorsList * pSponsorsList;
    Widget * pWidget;
    Previous_results * pPrevious_results;
    About_MS * pAbout;
    BMR * pBMR;
    BMI * pBMI;
    void setPressed(QPushButton * b);
    void setReleased(QPushButton * b);
    explicit more_info(QWidget *parent = 0);
    ~more_info();

private slots:
    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_pushButton_6_pressed();
    void on_pushButton_6_released();
    void on_pushButton_7_pressed();
    void on_pushButton_7_released();
    void on_pushButton_8_released();
    void on_pushButton_8_pressed();
    void on_pushButton_3_pressed();
    void on_pushButton_3_released();
    void on_pushButton_4_pressed();
    void on_pushButton_4_released();
    void on_pushButton_5_pressed();
    void on_pushButton_5_released();

private:
    Ui::more_info *ui;
};

#endif // MORE_INFO_H
