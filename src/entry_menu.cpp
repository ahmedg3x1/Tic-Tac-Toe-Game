#include "entry_menu.h"
#include "../ui/ui_entry_menu.h"

entry_menu::entry_menu(QWidget *parent) : QMainWindow(parent), ui(new Ui::entry_menu) {
    ui->setupUi(this);
    myparent = parent;
}

entry_menu::~entry_menu() { delete ui; }

void entry_menu::closeEvent(QCloseEvent *event)
{
    // Ensure that the entire application quits when the entry window is closed
    QApplication::quit();
}

void entry_menu::on_entry_menu_destroyed() { close(); }

void entry_menu::on_pvp_button_clicked() {
  // should make game window and pass the Game class object as member to it
  /*Game new_game(player1_name,player2_name,player1_name,0);
    then in the game-window-class-constructor add parameter of type(Game)
    then make window of the game with input parameters(Game)


  */
  my_login_window = new login_window(this, false, false);
  my_login_window->setWindowModality(Qt::ApplicationModal);

  my_login_window->show();
}

void entry_menu::on_pvai_button_clicked() {
  my_login_window = new login_window(this, false, true);
  my_login_window->setWindowModality(Qt::ApplicationModal);

  my_login_window->show();
}

void entry_menu::on_profile_button_clicked() {
  my_profile_menu = new profile_menu(this, false);
  my_profile_menu->setWindowModality(Qt::ApplicationModal);

  my_profile_menu->show();
}

void entry_menu::on_history_button_clicked() {
  my_profile_menu = new profile_menu(this, true);
  my_profile_menu->setWindowModality(Qt::ApplicationModal);

  my_profile_menu->show();
}

void entry_menu::on_logout_button_clicked()
{
    close();
    myparent->show();
}

