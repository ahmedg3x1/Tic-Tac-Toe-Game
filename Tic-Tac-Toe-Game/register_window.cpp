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

extern bool reg(QString name,QString password);




void register_window::on_register_button_clicked()
{
    //registerUser(ui->username->text().toStdString(),ui->password->text().toStdString());
}

extern
void register_window::on_cancel_button_clicked()
{
    close();                // Close the registration form
    myparent->show();
}

