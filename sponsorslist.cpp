#include "sponsorslist.h"
#include "ui_sponsorslist.h"

SponsorsList::SponsorsList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SponsorsList)
{
    ui->setupUi(this);
    this->ui->timerLabel->setText(StyleSheets::getDate());
}

SponsorsList::~SponsorsList()
{
    delete ui;
}

void SponsorsList::on_pushButton_pressed()
{
    StyleSheets::setPressedOther(this->ui->pushButton);
}

void SponsorsList::on_pushButton_released()
{
    StyleSheets::setReleasedOther(this->ui->pushButton);
    this->pBack->show();
    this->hide();
}
