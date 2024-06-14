#include "login_window.h"
#include "./ui_login_window.h"
#include "register_window.h"
#include "entry_menu.h"
#include "Database.h"

extern Database my_database;

login_window::login_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login_window)
{
    cout <<"hello world";
    ui->setupUi(this);

}

login_window::~login_window()
{
    delete ui;
}




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

    UserData input_user;
    input_user.username = (ui->username->text().toStdString());
    input_user.passwordHash = (ui->password_line_edit->text().toStdString());
    login_result login_test = my_database.login(input_user);

    switch (login_test) {
    case user_wrong:
        ui->warning_label->setText("Invalid username.");
        ui->warning_label->show();
        break;
    case password_wrong:
        ui->warning_label->setText("Password is incorrect.");
        ui->warning_label->show();
        break;
    case database_error:
        ui->warning_label->setText("Database error during login!");
        ui->warning_label->show();
        break;
    case correct:
        static entry_menu *my_entry_menu = new entry_menu(this);
        hide();
        my_entry_menu->show();
        break;
    default:
        break;
    }




}



