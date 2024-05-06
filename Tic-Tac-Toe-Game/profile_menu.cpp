#include "profile_menu.h"
#include "ui_profile_menu.h"

profile_menu::profile_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profile_menu)
{
    ui->setupUi(this);
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
    this->hide();
}


void profile_menu::on_profile_menu_destroyed()
{

}


void profile_menu::on_profile_menu_destroyed(QObject *arg1)
{

}
