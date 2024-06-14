#include "profile.h"
#include "ui_profile.h"
#include "Database.h"
#include <QString>
#include <string>
profile::profile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::profile)
{
    ui->setupUi(this);
    //ui->wins_label->text() =  QString::fromStdString(getwins());
    //ui->draw_label->text() =  QString::fromStdString(getdraws());
    //ui->lose_label->text() =  QString::fromStdString(getloses());
}

profile::~profile()
{
    delete ui;
}

void profile::on_save_button_clicked()
{
    //change_password(ui->new_password->text().toStdString());
    this->hide();
}


void profile::on_cancel_button_clicked()
{
    this->hide();
}

