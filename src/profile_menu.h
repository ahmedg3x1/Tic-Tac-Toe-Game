#ifndef PROFILE_MENU_H
#define PROFILE_MENU_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "Database.h"
#include "game_window.h"

namespace Ui {
class profile_menu;
}

class profile_menu : public QMainWindow {
  Q_OBJECT

 public:
  explicit profile_menu(QWidget *parent = nullptr, bool history = false);
  ~profile_menu();

 private slots:
  void on_profile_menu_destroyed();

  void on_profile_menu_destroyed(QObject *arg1);

  void on_replay_clicked();

  void on_back_clicked();

  void on_match_list_clicked(const QModelIndex &index);

 private:
  Ui::profile_menu *ui;
  QWidget *myparent;
  game_window *my_history_window;

  QStandardItemModel *model;

  GameRecord selected_match;
};

#endif  // PROFILE_MENU_H
