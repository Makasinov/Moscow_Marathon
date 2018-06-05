#include "bmi.h"
#include "ui_bmi.h"
#include <QPixmap>

BMI::BMI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BMI)
{
    ui->setupUi(this);
    this->ui->label_3->setText(StyleSheets::getDate()); // отсчёт
    this->ui->lineEdit->setValidator(   new QIntValidator(1, 300, this) );
    this->ui->lineEdit_2->setValidator( new QIntValidator(1, 300, this) );
}

BMI::~BMI()
{    delete ui;    }

void BMI::on_pushButton_pressed()
{
    StyleSheets::setPressedOther(this->ui->pushButton);
}

void BMI::on_pushButton_released()
{
    StyleSheets::setReleasedOther(this->ui->pushButton);
    this->pBack->show();
    this->hide();
}

void BMI::on_pushButton_2_clicked()
{
    // кг / м * м
    if ( !this->ui->lineEdit->text().isEmpty() && !this->ui->lineEdit_2->text().isEmpty() )
    {
        qint64 height = this->ui->lineEdit->text().toInt();           // рост
        qint64 weight = this->ui->lineEdit_2->text().toInt() * 10000;   // вес
        qreal result = 0;
        if (height > 0 && weight > 0) result = weight / (height * height);
        //qDebug() << weight << "/(" << height << "*" << height << ") = " << result;
        if ( result > 0 )
        {
            this->ui->number->setText(QString::number(result));
            if ( result < 20 )
            {
                QPixmap pixmap(":/images/bmi-underweight-icon.png");
                this->ui->word->setText(tr("Недовес"));
                this->ui->pixmap->setPixmap(pixmap);
            }
            else if ( result >= 20 && result <= 25 )
            {
                QPixmap pixmap(":/images/bmi-healthy-icon.png");
                this->ui->pixmap->setPixmap(pixmap);
                this->ui->word->setText(tr("Нормальный вес"));
            }
            else if ( result >= 26 && result <= 30 )
            {
                QPixmap pixmap(":/images/bmi-overweight-icon.png");
                this->ui->pixmap->setPixmap(pixmap);
                this->ui->word->setText(tr("Избыточный вес"));
            }
            else if ( result >= 31)
            {
                QPixmap pixmap(":/images/bmi-obese-icon.png");
                this->ui->pixmap->setPixmap(pixmap);
                this->ui->word->setText(tr("Ожирение"));
            }
        }
    }
}


