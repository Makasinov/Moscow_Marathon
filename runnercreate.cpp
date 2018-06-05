#include "runnercreate.h"
#include "ui_runnercreate.h"

RunnerCreate::RunnerCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunnerCreate)
{
    ui->setupUi(this);
    this->ui->timerLabel->setText(StyleSheets::getDate()); // отсчёт
}

RunnerCreate::~RunnerCreate()
{    delete ui;    }

void RunnerCreate::on_pushButton_pressed()
{
    StyleSheets::setPressedOther(this->ui->pushButton);
}

void RunnerCreate::on_pushButton_released()
{
    StyleSheets::setReleasedOther(this->ui->pushButton);
    this->pBack->show();
    this->hide();
}

void RunnerCreate::on_pushButton_2_clicked()
{

}
