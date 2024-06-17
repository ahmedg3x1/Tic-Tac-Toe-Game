#include "profile_menu.h"
#include "ui_profile_menu.h"
#include "Database.h"
#include <QString>
#include <string>

extern UserData loggedInHost, loggedInGuest;

extern QString player_1_name, player_2_name;

profile_menu::profile_menu(QWidget *parent, bool history) :
    QMainWindow(parent),
    ui(new Ui::profile_menu)
{
    ui->setupUi(this);

    if(history){
        string filename = loggedInHost.username + "_data.txt";
        loadUserData(loggedInHost, filename);
        //create the hitory table

        ui->stackedWidget->setCurrentWidget(ui->history_page);
    }
    else{
        ui->user_textbox->setText(player_1_name);
        ui->wins_label->setText(QString::number(wins(player_1_name.toStdString())));
        ui->lose_label->setText(QString::number(loses(player_1_name.toStdString())));
        ui->draw_label->setText(QString::number(ties(player_1_name.toStdString())));

        ui->stackedWidget->setCurrentWidget(ui->profile_page);
    }
}

profile_menu::~profile_menu()
{
    delete ui;
}


void profile_menu::on_profile_menu_destroyed()
{

}


void profile_menu::on_profile_menu_destroyed(QObject *arg1)
{

}
