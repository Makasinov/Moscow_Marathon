#include "previous_results.h"
#include "ui_previous_results.h"
#include <stylesheets.h>

Previous_results::Previous_results(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Previous_results)
{
    ui->setupUi(this);
    this->ui->label_3->setText(StyleSheets::getDate());
}

Previous_results::~Previous_results()
{
    delete ui;
}

void Previous_results::on_pushButton_pressed()
{
    this->ui->pushButton->setStyleSheet(
        "border-style:  outset;"
        "border-width:  1px;"
        "border-radius: 5px;"
        "border-color:  beige;"
        "min-width:     7em;"
        "padding:       1px;"
        "border-color:  white;"
        "color: white");
}

void Previous_results::on_pushButton_released()
{
    this->ui->pushButton->setStyleSheet(
                    "border-style: outset;"
                    "border-width: 1px;"
                    "border-radius: 5px;"
                    "border-color: beige;"
                    "min-width: 7em;"
                    "padding: 1px;"
                    "border-color: grey;"
                    "color: white;" );
    pBack->show();
    this->hide();
}

void Previous_results::on_pushButton_3_pressed()
{
       this->ui->pushButton_3->setStyleSheet(
                    "border-style:  outset;"
                    "border-width:  1px;"
                    "border-radius: 5px;"
                    "border-color:  beige;"
                    "min-width:     7em;"
                    "padding:       1px;"
                    "border-color:  rgb(80,80,80);");
}

void Previous_results::on_pushButton_3_released()
{
    this->ui->pushButton_3->setStyleSheet(
                    "background-color: rgb(209, 209, 209);"
                    "border-style: outset;"
                    "border-width: 1px;"
                    "border-radius: 5px;"
                    "border-color: beige;"
                    "min-width: 7em;"
                    "padding: 1px;"
                    "border-color: grey;");
}
