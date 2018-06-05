#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    info = new more_info;
    info->pWidget = this;
    this->pDonateSponsor = new DonateSponsor;
    this->pDonateSponsor->pBack = this;
    this->pWannaBecomeARunner = new WannaBecomeARunner;
    this->pWannaBecomeARunner->pBack = this;
    this->ui->label_3->setText(StyleSheets::getDate());
}

Widget::~Widget()
{    delete ui;    }

void Widget::on_pushButton_pressed() // Я Хочу стать бегуном - нажата
{
    this->ui->pushButton->setStyleSheet(
                "border-style:  outset;"
                "border-width:  1px;"
                "border-radius: 5px;"
                "border-color:  beige;"
                "min-width:     7em;"
                "padding:       1px;"
                "border-color:  rgb(80,80,80);");
}

void Widget::on_pushButton_released() // Я хочу стать бегуном - отжата
{
    this->ui->pushButton->setStyleSheet(
                "background-color: rgb(209, 209, 209);"
                "border-style: outset;"
                "border-width: 1px;"
                "border-radius: 5px;"
                "border-color: beige;"
                "min-width: 7em;"
                "padding: 1px;"
                "border-color: grey;");
    this->pWannaBecomeARunner->show();
    this->hide();
}

void Widget::on_pushButton_2_released() // Донат кнопочка :)
{
    this->ui->pushButton_2->setStyleSheet(
                "background-color: rgb(209, 209, 209);"
                "border-style: outset;"
                "border-width: 1px;"
                "border-radius: 5px;"
                "border-color: beige;"
                "min-width: 7em;"
                "padding: 1px;"
                "border-color: grey;");
    pDonateSponsor->show();
    this->hide();
}

void Widget::on_pushButton_2_pressed()
{
    this->ui->pushButton_2->setStyleSheet(
                "border-style:  outset;"
                "border-width:  1px;"
                "border-radius: 5px;"
                "border-color:  beige;"
                "min-width:     7em;"
                "padding:       1px;"
                "border-color:  rgb(80,80,80);");
}

void Widget::on_pushButton_3_pressed()
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

void Widget::on_pushButton_3_released()
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
    info->show();
    this->hide();
}

void Widget::on_pushButton_4_pressed() // Авторизация - нажата
{
    this->ui->pushButton_4->setStyleSheet(
                "border-style:  outset;"
                "border-width:  1px;"
                "border-radius: 5px;"
                "border-color:  beige;"
                "min-width:     7em;"
                "padding:       1px;"
                "border-color:  rgb(80,80,80);"
                "color: white;" );
}

void Widget::on_pushButton_4_released() // Авторизация - отжата
{
    this->ui->pushButton_4->setStyleSheet(
                "border-style: outset;"
                "border-width: 1px;"
                "border-radius: 5px;"
                "border-color: beige;"
                "min-width: 7em;"
                "padding: 1px;"
                "border-color: grey;"
                "color: white;" );
    LoginDialog * pLoginDialog = new LoginDialog;
    QObject::connect(pLoginDialog,SIGNAL(rejected()),this,SLOT(tryToConnect()));
    QObject::connect(pLoginDialog,SIGNAL(rejected()),pLoginDialog,SLOT(deleteLater()));
    QObject::connect(pLoginDialog,SIGNAL(accepted()),this,SLOT(tryToConnect()));
    QObject::connect(pLoginDialog,SIGNAL(accepted()),pLoginDialog,SLOT(deleteLater()));
    pLoginDialog->show();
}

bool Widget::tryToConnect()
{
    qDebug() << "Trying to connect....";
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName("DATABASE_EPTA");
    qDebug() << db.open();

    return false;
}







