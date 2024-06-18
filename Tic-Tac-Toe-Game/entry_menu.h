#ifndef ENTRY_MENU_H
#define ENTRY_MENU_H

#include <QMainWindow>
#include "login_window.h"
#include "profile_menu.h"

#include "game_window.h"

namespace Ui {
class entry_menu;
}

class entry_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit entry_menu(QWidget *parent = nullptr);
    ~entry_menu();

private slots:
    void on_profile_button_clicked();

    void on_pvp_button_clicked();

    void on_pvai_button_clicked();

    void on_entry_menu_destroyed();

    void on_history_button_clicked();

private:
    Ui::entry_menu *ui;
    login_window *my_login_window;
    profile_menu *my_profile_menu;

    game_window *my_game_window;
};

#endif // ENTRY_MENU_H
