#ifndef SPONSORSLIST_H
#define SPONSORSLIST_H

#include <QWidget>
#include <stylesheets.h>
#include <more_info.h>
class StyleSheets;
class more_info;

namespace Ui {
class SponsorsList;
}

class SponsorsList : public QWidget
{
    Q_OBJECT

public:
    more_info * pBack;
    explicit SponsorsList(QWidget *parent = 0);
    ~SponsorsList();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::SponsorsList *ui;
};

#endif // SPONSORSLIST_H
