#include "more_info.h"
#include "ui_more_info.h"
#include <stylesheets.h>

more_info::more_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::more_info)
{
    ui->setupUi(this);
    this->pPrevious_results = new Previous_results;
    this->pAbout = new About_MS;
    this->pBMR = new BMR;
    this->pBMR->pBack = this;
    this->pBMI = new BMI;
    this->pBMI->pBack = this;
    this->pSponsorsList = new SponsorsList;
    this->pSponsorsList->pBack = this;
    this->ui->label_3->setText(StyleSheets::getDate()); // отсчёт
}

more_info::~more_info()
{    delete ui;    }

void more_info::setPressed(QPushButton * b)
{
    b->setStyleSheet(
                "border-style:  outset;"
                "border-width:  1px;"
                "border-radius: 5px;"
                "border-color:  beige;"
                "min-width:     7em;"
                "padding:       1px;"
                "border-color:  rgb(80,80,80);"
                "color: black;" );
}

void more_info::setReleased(QPushButton *b)
{
    b->setStyleSheet(
                "background-color: rgb(209, 209, 209);"
                "border-style: outset;"
                "border-width: 1px;"
                "border-radius: 5px;"
                "border-color: beige;"
                "min-width: 7em;"
                "padding: 1px;"
                "border-color: grey;"
                "color: black;");
}

void more_info::on_pushButton_pressed() // кнопка Назад - нажата
{
    StyleSheets::setPressedOther(this->ui->pushButton);
}

void more_info::on_pushButton_released() // кнопка Назад - отжата
{
    StyleSheets::setReleasedOther(this->ui->pushButton);
    pWidget->show();
    this->hide();
}

void more_info::on_pushButton_6_pressed() // Marathon Skills 2017 - нажата
{
    this->setPressed(this->ui->pushButton_6);
}

void more_info::on_pushButton_6_released() // Marathon Skills 2017 - отжата
{
    this->setReleased(this->ui->pushButton_6);
    pAbout->pBack = this;
    pAbout->show();
    this->hide();
}

void more_info::on_pushButton_7_pressed() // предыдущие результаты - нажата
{
    this->setPressed(this->ui->pushButton_7);
}

void more_info::on_pushButton_7_released() // предыдущие результаты - отжата
{
    this->setReleased(this->ui->pushButton_7);
    pPrevious_results->pBack = this;
    pPrevious_results->show();
    this->hide();
}

void more_info::on_pushButton_8_pressed()
{
    this->setPressed(this->ui->pushButton_8);
}

void more_info::on_pushButton_8_released() // BMI
{
    this->setReleased(this->ui->pushButton_8);
    this->pBMI->show();
    this->hide();
}

void more_info::on_pushButton_3_pressed()
{
    this->setPressed(this->ui->pushButton_3);
}

void more_info::on_pushButton_3_released()
{
    this->setReleased(this->ui->pushButton_3);
}

void more_info::on_pushButton_4_pressed()
{
    this->setPressed(this->ui->pushButton_4);
}

void more_info::on_pushButton_4_released()
{
    this->setReleased(this->ui->pushButton_4);
    this->pSponsorsList->show();
    this->hide();
}

void more_info::on_pushButton_5_pressed()
{
    this->setPressed(this->ui->pushButton_5);
}

void more_info::on_pushButton_5_released() // BMR
{
    this->setReleased(this->ui->pushButton_5);
    this->pBMR->show();
    this->hide();
}
