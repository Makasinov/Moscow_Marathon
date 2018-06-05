#include "donatesponsor.h"
#include "ui_donatesponsor.h"
#include <stylesheets.h>

DonateSponsor::DonateSponsor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DonateSponsor)
{
    ui->setupUi(this);
    this->ui->label_3->setText(StyleSheets::getDate());
}

DonateSponsor::~DonateSponsor()
{    delete ui;    }

void DonateSponsor::on_pushButton_released()
{
    StyleSheets::setReleasedOther(this->ui->pushButton);
    this->pBack->show();
    this->hide();
}

void DonateSponsor::on_pushButton_pressed()
{
    StyleSheets::setPressedOther(this->ui->pushButton);
}
