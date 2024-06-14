#include "register_window.h"
#include "ui_register_window.h"
#include "entry_menu.h"
#include "Database.h"




register_window::register_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::register_window)
{
    myparent = parent;
    ui->setupUi(this);
}

register_window::~register_window()
{
    delete ui;
}




void register_window::on_register_button_clicked()
{
   register_result register_test = registerUser(ui->username->text().toStdString(),ui->password->text().toStdString());
    switch (register_test){
   case null_user:
        ui->warning_line->styleSheet() = "color:rgb(255, 0, 0)";
        ui->warning_line->setText("please enter valid username");
        break;
   case user_is_already_registered:
       ui->warning_line->styleSheet() = "color:rgb(255, 0, 0)";
       ui->warning_line->setText("username is already registered.");
       break;
   case null_password:
       ui->warning_line->styleSheet() = "color:rgb(255, 0, 0)";
       ui->warning_line->setText("please enter valid password");
       break;
   case weak_password:
       ui->warning_line->styleSheet() = "color:rgb(255, 0, 0)";
       ui->warning_line->setText("select stronger password");
       break;
   case register_correct:
       ui->warning_line->styleSheet() = "color:rgb(0, 255, 0)";
       ui->warning_line->setText("registerd succesfully");
       break;
   default:
       break;
   }
}

extern
void register_window::on_cancel_button_clicked()
{
    ui->username->clear();
    ui->password->clear();
    ui->warning_line->setText("");
    close();                // Close the registration form
    myparent->show();
}

