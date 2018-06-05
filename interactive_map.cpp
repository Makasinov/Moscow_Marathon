#include "interactive_map.h"
#include "ui_interactive_map.h"
#include <stylesheets.h>

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    this->ui->frame->hide();
    this->ui->tabWidget->tabBar()->hide();
    this->ui->label_3->setText(StyleSheets::getDate());
}

Map::~Map()
{
    delete ui;
}


void Map::on_pushButton_pressed() // Назад - нажата
{
    StyleSheets::setPressedOther(this->ui->pushButton);
}

void Map::on_pushButton_released() // Назад - отжата
{
    StyleSheets::setReleasedOther(this->ui->pushButton);
    this->pBack->show();
    this->hide();
}

void Map::on_commandLinkButton_6_clicked()
{
    this->ui->commandLinkButton_7->hide();
    this->ui->frame->show();
    this->ui->tabWidget->tabBar()->setCurrentIndex(0);
}

void Map::on_commandLinkButton_4_clicked()
{
    this->ui->commandLinkButton_7->hide();
    this->ui->frame->show();
    this->ui->tabWidget->tabBar()->setCurrentIndex(1);
}

void Map::on_commandLinkButton_clicked()
{
    this->ui->commandLinkButton_7->hide();
    this->ui->frame->show();
    this->ui->tabWidget->tabBar()->setCurrentIndex(2);
}

void Map::on_commandLinkButton_3_clicked()
{
    this->ui->commandLinkButton_7->hide();
    this->ui->frame->show();
    this->ui->tabWidget->tabBar()->setCurrentIndex(3);
}

void Map::on_commandLinkButton_5_clicked()
{
    this->ui->commandLinkButton_7->hide();
    this->ui->frame->show();
    this->ui->tabWidget->tabBar()->setCurrentIndex(4);
}
