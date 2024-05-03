#ifndef ENTRY_MENU_H
#define ENTRY_MENU_H

#include <QMainWindow>

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

private:
    Ui::entry_menu *ui;
};

#endif // ENTRY_MENU_H
