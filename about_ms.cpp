#include "about_ms.h"
#include "ui_about_ms.h"

About_MS::About_MS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About_MS)
{
    this->pMap = new Map;
    this->pMap->pBack = this;
    ui->setupUi(this);
    this->ui->label_3->setText(StyleSheets::getDate());
}

About_MS::~About_MS()
{
    delete ui;
}

void About_MS::on_pushButton_pressed()
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

void About_MS::on_pushButton_released()
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
    this->pBack->show();
    this->hide();
}


void About_MS::on_commandLinkButton_released()
{
    pMap->show();
    this->hide();
}
