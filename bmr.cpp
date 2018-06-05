#include "bmr.h"
#include "ui_bmr.h"

BMR::BMR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BMR)
{
    ui->setupUi(this);
    this->ui->label_3->setText(StyleSheets::getDate()); // отсчёт
    this->ui->lineEdit->setValidator(   new QIntValidator(1, 300, this) );
    this->ui->lineEdit_2->setValidator( new QIntValidator(1, 300, this) );
    this->ui->lineEdit_3->setValidator( new QIntValidator(1, 100, this) );

}

BMR::~BMR()
{    delete ui;    }

void BMR::on_pushButton_pressed()
{
    StyleSheets::setPressedOther(this->ui->pushButton);
}

void BMR::on_pushButton_released()
{
    StyleSheets::setReleasedOther(this->ui->pushButton);
    this->pBack->show();
    this->hide();
}

void BMR::on_pushButton_2_clicked()
{
    //  BMR = 10 × weight(kg) + 6.25 × height(cm) - 5 × age(y) + 5         (man)
    //  BMR = 10 × weight(kg) + 6.25 × height(cm) - 5 × age(y) - 161     (woman)
    if ( !this->ui->lineEdit->text().isEmpty()   &&
         !this->ui->lineEdit_2->text().isEmpty() &&
         !this->ui->lineEdit_3->text().isEmpty() )
    {
        qint64 result;
        qint64 height = this->ui->lineEdit->text().toInt();
        qint64 weight = this->ui->lineEdit_2->text().toInt();
        qint64 age    = this->ui->lineEdit_3->text().toInt();
        if(this->ui->radioButton->isChecked())
            result = 10 * weight + 6.25 * height - 5 * age + 5;
        else
            result = 10 * weight + 6.25 * height - 5 * age - 161;
        this->ui->label_13->setText(QString::number(result));
    }
}
