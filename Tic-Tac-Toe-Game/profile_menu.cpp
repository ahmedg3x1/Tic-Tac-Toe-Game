#include "profile_menu.h"
#include "ui_profile_menu.h"
#include "Database.h"
#include <QString>
#include <string>

profile_menu::profile_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profile_menu)
{
    ui->setupUi(this);
    //ui->user_textbox->text() =  QString::fromStdString(my_database.userdata.username);
    //ui->wins_label->text() =  QString::fromStdString(getwins());
    //ui->draw_label->text() =  QString::fromStdString(getdraws());
    //ui->lose_label->text() =  QString::fromStdString(getloses());
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
