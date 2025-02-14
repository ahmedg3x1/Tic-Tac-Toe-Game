#include "../ui/ui_login_window.h"
#include "Database.h"
#include "entry_menu.h"
#include "login_window.h"
#include "register_window.h"

UserData loggedInHost, loggedInGuest;

QString player_1_name = "Host", player_2_name = "Guest";
QString player_1_tic = "X", player_2_tic = "O";

login_window::login_window(QWidget *parent, bool First_Player_Login, bool PVAI)
    : QMainWindow(parent), ui(new Ui::login_window), aiEnable(PVAI) {
  ui->setupUi(this);
  myparent = parent;

  first_player_login = First_Player_Login;

  if (PVAI) {
    ui->stackedWidget->setCurrentWidget(ui->game_settings_page);
    player_2_name = QString("Machine");
  } else {
    ui->stackedWidget->setCurrentWidget(ui->login_page);
  }

  ui->first_player_name->setText(player_1_name);
  ui->second_player_name->setText(player_2_name);
  ui->starting_player_name->setText(player_1_name + QString(" Will start !"));
}

login_window::~login_window() { delete ui; }

void login_window::on_register_button_clicked() {
  // Create a new instance of your registration form
  static register_window *registrationForm = new register_window(this);  // Pass 'this' as parent

  // Optionally, set initial values for the registration form (if needed)

  // Show the registration form modally and hide the login form
  ui->username->clear();
  ui->password->clear();
  ui->warning_label->setText("");
  close();
  registrationForm->show();
}

void login_window::on_login_button_clicked() {
  // this is the condition
  UserData input_user;
  input_user.username = (ui->username->text().toStdString());
  input_user.passwordHash = (ui->password->text().toStdString());
  login_result login_test = login(input_user);

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
    case login_correct:
      if (first_player_login) {
        player_1_name = ui->username->text();
        loggedInHost.username = ui->username->text().toStdString();
        loggedInHost.passwordHash = md5(ui->password->text().toStdString());
        loadUserData(loggedInHost, loggedInHost.username + "_data.txt");
        cout << "now player 1 name is: " + player_1_name.toStdString() << endl;

        static entry_menu *my_entry_menu = new entry_menu(this);
        ui->username->clear();
        ui->password->clear();
        ui->warning_label->setText("");
        close();
        my_entry_menu->show();
      } else {
        if (ui->username->text() != player_1_name) {
          player_2_name = ui->username->text();
          loggedInGuest.username = player_2_name.toStdString();
          loggedInGuest.passwordHash = md5(ui->password->text().toStdString());
          cout << "now player 2 name is: " + player_2_name.toStdString() << endl;

          // tic choosing page initilization
          ui->first_player_name->setText(player_1_name);
          ui->second_player_name->setText(player_2_name);
          ui->starting_player_name->setText(player_1_name + QString(" Will start !"));

          /* show tic choosing page */
          ui->username->clear();
          ui->password->clear();
          ui->warning_label->setText("");
          ui->stackedWidget->setCurrentWidget(ui->game_settings_page);
        } else {
          ui->warning_label->setText("Please select different user!");
          ui->warning_label->show();
        }
      }

      break;
    default:
      break;
  }
}

void login_window::on_cancel_button_clicked() {
  close();
  if (myparent) myparent->show();
}

void login_window::on_swap_tics_clicked() {
  QString temp = ui->first_player_tic->text();
  ui->first_player_tic->setText(ui->second_player_tic->text());
  ui->second_player_tic->setText(temp);
}

void login_window::on_start_clicked() {
  player_1_tic = ui->first_player_tic->text();
  player_2_tic = ui->second_player_tic->text();

  my_game_window = new game_window(myparent, aiEnable);
  my_game_window->setWindowModality(Qt::ApplicationModal);
  hide();
  my_game_window->show();
}

void login_window::on_back_clicked() {
  if (aiEnable) {
    close();
    myparent->show();
  } else {
    ui->stackedWidget->setCurrentWidget(ui->login_page);
  }
}
