#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "register_window.h"
#include "entry_menu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


extern bool login(QString name,QString password);



void MainWindow::on_register_button_clicked()
{

    // Create a new instance of your registration form
   static register_window *registrationForm = new register_window(this); // Pass 'this' as parent

    // Optionally, set initial values for the registration form (if needed)

    // Show the registration form modally and hide the login form
    hide();
    registrationForm->show();



}


void MainWindow::on_login_button_clicked()
{

    //this is the condition
    //login(ui->username_combobox->currentText(),ui->password_line_edit->text())
    if(1)
    {
        //go to next window
        static entry_menu *my_entry_menu = new entry_menu(this);
        hide();
        my_entry_menu->show();
    }
    else
    {
        ui->warning_label->setText("Password is incorrect.");
        ui->warning_label->show();
    }

}



