#ifndef PREVIOUS_RESULTS_H
#define PREVIOUS_RESULTS_H

#include <QWidget>
#include <more_info.h>
class more_info;

namespace Ui {
class Previous_results;
}

class Previous_results : public QWidget
{
    Q_OBJECT

public:
    more_info * pBack;
    explicit Previous_results(QWidget *parent = 0);
    ~Previous_results();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

private:
    Ui::Previous_results *ui;
};

#endif // PREVIOUS_RESULTS_H
