#ifndef RUNNERCREATE_H
#define RUNNERCREATE_H

#include <QWidget>
#include <stylesheets.h>
#include <wannabecomearunner.h>
class StyleSheets;
class WannaBecomeARunner;

namespace Ui {
class RunnerCreate;
}

class RunnerCreate : public QWidget
{
    Q_OBJECT

public:
    WannaBecomeARunner * pBack;
    explicit RunnerCreate(QWidget *parent = 0);
    ~RunnerCreate();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_clicked();

private:
    Ui::RunnerCreate *ui;
};

#endif // RUNNERCREATE_H
