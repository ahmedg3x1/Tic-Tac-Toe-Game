#include "login_window.h"
#include "./ui_login_window.h"
#include "register_window.h"
#include "entry_menu.h"

QString player_1_name = "Host", player_2_name = "Guest";
QString player_1_tic  = "X",    player_2_tic  = "O";

login_window::login_window(QWidget *parent, bool First_Player_Login)
    : QMainWindow(parent)
    , ui(new Ui::login_window)
{

    ui->setupUi(this);
    myparent = parent;

    ui->stackedWidget->setCurrentWidget(ui->login_page);

    first_player_login = First_Player_Login;

}

login_window::~login_window()
{
    delete ui;
}


extern bool login(QString name,QString password);



void login_window::on_register_button_clicked()
{

    // Create a new instance of your registration form
   static register_window *registrationForm = new register_window(this); // Pass 'this' as parent

    // Optionally, set initial values for the registration form (if needed)

    // Show the registration form modally and hide the login form
    hide();
    registrationForm->show();

}


void login_window::on_login_button_clicked()
{

    //this is the condition
    //login(ui->username_combobox->currentText(),ui->password_line_edit->text())
    if(1)
    {
        if(first_player_login)
        {
            player_1_name = ui->username_combobox->currentText();
            //go to next window
            static entry_menu *my_entry_menu = new entry_menu(this);
            hide();
            my_entry_menu->show();
        }
        else
        {
            player_2_name = ui->username_combobox->currentText();
            // tic choosing page initilization

            /* show tic choosing page */
            ui->stackedWidget->setCurrentWidget(ui->game_settings_page);
        }
    }
    else
    {
        ui->warning_label->setText("Password is incorrect.");
        ui->warning_label->show();
    }

}


void login_window::on_cancel_button_clicked()
{
    close();
    myparent->show();
}


void login_window::on_swap_tics_clicked()
{
    QString temp = ui->first_player_tic->text();
    ui->first_player_tic->setText(ui->second_player_tic->text());
    ui->second_player_tic->setText(temp);
}


void login_window::on_start_clicked()
{
    player_1_tic = ui->first_player_tic->text();
    player_2_tic = ui->second_player_tic->text();

    my_game_window = new game_window(myparent);
    hide();
    my_game_window->show();
}


void login_window::on_back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->login_page);
}
