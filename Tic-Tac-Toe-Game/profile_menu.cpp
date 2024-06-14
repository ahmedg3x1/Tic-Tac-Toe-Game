#include "profile_menu.h"
#include "ui_profile_menu.h"
#include "Database.h"
#include <QString>
#include <string>

extern QString player_1_name, player_2_name;

profile_menu::profile_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profile_menu)
{
    ui->setupUi(this);
    ui->user_textbox->setText(player_1_name);
    ui->wins_label->setText(QString::number(wins(player_1_name.toStdString())));
    ui->draw_label->setText(QString::number(loses(player_1_name.toStdString())));
    ui->lose_label->setText(QString::number(ties(player_1_name.toStdString())));
}

profile_menu::~profile_menu()
{
    delete ui;
}

void profile_menu::on_cancel_button_clicked()
{
    this->hide();
}


void profile_menu::on_save_button_clicked()
{
    //change_password(ui->new_password->text().toStdString());
    this->hide();
}


void profile_menu::on_profile_menu_destroyed()
{

}


void profile_menu::on_profile_menu_destroyed(QObject *arg1)
{

}
