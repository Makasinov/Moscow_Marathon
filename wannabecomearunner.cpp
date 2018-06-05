#include "wannabecomearunner.h"
#include "ui_wannabecomearunner.h"
#include <stylesheets.h>

WannaBecomeARunner::WannaBecomeARunner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WannaBecomeARunner)
{
    ui->setupUi(this);
    this->ui->label_3->setText(StyleSheets::getDate());
    pRunnerCreate = new RunnerCreate;
    pRunnerCreate->pBack = this;
}

WannaBecomeARunner::~WannaBecomeARunner()
{    delete ui;    }

void WannaBecomeARunner::on_pushButton_pressed() // Назад - нажата
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

void WannaBecomeARunner::on_pushButton_released() // Назад - отжата
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

void WannaBecomeARunner::on_pushButton_2_pressed()
{
    StyleSheets::setPressedOrdinary(this->ui->pushButton_2);
}

void WannaBecomeARunner::on_pushButton_2_released()
{
    StyleSheets::setReleasedOrdinary(this->ui->pushButton_2);
    LoginDialog * pLoginDialog = new LoginDialog;
    QObject::connect(pLoginDialog,SIGNAL(rejected()),pBack,SLOT(tryToConnect()));
    QObject::connect(pLoginDialog,SIGNAL(rejected()),pLoginDialog,SLOT(deleteLater()));
    QObject::connect(pLoginDialog,SIGNAL(accepted()),pBack,SLOT(tryToConnect()));
    QObject::connect(pLoginDialog,SIGNAL(accepted()),pLoginDialog,SLOT(deleteLater()));
    pLoginDialog->show();
}

void WannaBecomeARunner::on_pushButton_3_pressed()
{
    StyleSheets::setPressedOrdinary(this->ui->pushButton_3);
}

void WannaBecomeARunner::on_pushButton_3_released()
{
    StyleSheets::setReleasedOrdinary(this->ui->pushButton_3);
    pRunnerCreate->show();
    this->hide();
}
