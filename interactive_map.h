#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <about_ms.h>
class About_MS;


namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    About_MS * pBack;
    explicit Map(QWidget *parent = 0);
    ~Map();

private slots:
    void on_pushButton_released();

    void on_pushButton_pressed();

    void on_commandLinkButton_6_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_5_clicked();

private:
    Ui::Map *ui;
};

#endif // MAP_H
