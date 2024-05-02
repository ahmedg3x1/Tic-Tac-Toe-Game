#include "register_window.h"
#include "ui_register_window.h"
#include "mainwindow.h"
#include "entry_menu.h"
register_window::register_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::register_window)
{
    myparent= parent;
    ui->setupUi(this);
}

register_window::~register_window()
{
    delete ui;
}

extern bool reg(QString name,QString password);




void register_window::on_register_button_clicked()
{
    //reg(ui->user->text(),ui->password->text())
    if(1)
    {
        //login automaticily
        //close the window
        static entry_menu *my_entry_menu = new entry_menu(myparent);
        close();
        my_entry_menu->show();
    }
}

extern
void register_window::on_cancel_button_clicked()
{
    myparent->show();
    close(); // Close the registration form
}

