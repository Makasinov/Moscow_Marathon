#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginDialog_accepted(){}

void LoginDialog::on_LoginDialog_rejected(){}

void LoginDialog::on_LoginDialog_destroyed(){}

void LoginDialog::on_buttonBox_rejected(){}
