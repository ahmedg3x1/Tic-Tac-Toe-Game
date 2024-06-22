#include "Database.h"
#include "entry_menu.h"
#include "register_window.h"
#include "ui_register_window.h"

register_window::register_window(QWidget *parent) : ui(new Ui::register_window) {
  myparent = parent;
  ui->setupUi(this);
}

register_window::~register_window() { delete ui; }

void register_window::on_register_button_clicked() {
  register_result register_test = registerUser(ui->username->text().toStdString(), ui->password->text().toStdString());
  switch (register_test) {
    case null_user:
      ui->warning_line->setStyleSheet("color: red;");
      ui->warning_line->setText("Please enter a valid username.");
      break;
    case user_is_already_registered:
      ui->warning_line->setStyleSheet("color: red;");
      ui->warning_line->setText("This username is already registered. Please choose a different one.");
      break;
    case null_password:
      ui->warning_line->setStyleSheet("color: red;");
      ui->warning_line->setText("Please enter a valid password.");
      break;
    case weak_password:
      ui->warning_line->setStyleSheet("color: red;");
      ui->warning_line->setText("Please choose a stronger password for better security.");
      break;
    case bad_user:
      ui->warning_line->setStyleSheet("color: red;");
      ui->warning_line->setText("Usernames cannot contain spaces. Please choose a different username.");
      break;
    case register_correct:
      ui->warning_line->setStyleSheet("color: green;");
      ui->warning_line->setText("Registration successful!");
      break;
    default:
      break;
  }
}

extern void register_window::on_cancel_button_clicked() {
  ui->username->clear();
  ui->password->clear();
  ui->warning_line->setText("");
  close();  // Close the registration form
  myparent->show();
}
