#ifndef ABOUT_MS_H
#define ABOUT_MS_H

#include <QWidget>
#include <interactive_map.h>
#include <more_info.h>
class Map;
class more_info;

namespace Ui {
class About_MS;
}

class About_MS : public QWidget
{
    Q_OBJECT

public:
    more_info * pBack;
    Map * pMap;
    explicit About_MS(QWidget *parent = 0);
    ~About_MS();

private slots:
    void on_pushButton_released();

    void on_pushButton_pressed();

    void on_commandLinkButton_released();

private:
    Ui::About_MS *ui;
};

#endif // ABOUT_MS_H
