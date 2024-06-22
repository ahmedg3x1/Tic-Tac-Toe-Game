#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QMainWindow>

#include "game_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class login_window;
}
QT_END_NAMESPACE

class login_window : public QMainWindow {
  Q_OBJECT

 public:
  login_window(QWidget *parent = nullptr, bool First_Player_Login = true, bool PVAI = false);
  ~login_window();

 private slots:
  void on_register_button_clicked();

  void on_login_button_clicked();

  void on_cancel_button_clicked();

  void on_start_clicked();

  void on_back_clicked();

  void on_swap_tics_clicked();

 private:
  Ui::login_window *ui;
  QWidget *myparent;
  game_window *my_game_window;

  bool aiEnable;

  bool first_player_login;
};
#endif  // LOGIN_WINDOW_H
