#ifndef PROFILE_MENU_H
#define PROFILE_MENU_H

#include <QMainWindow>

namespace Ui {
class profile_menu;
}

class profile_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit profile_menu(QWidget *parent = nullptr, bool history = false);
    ~profile_menu();

private slots:
    void on_profile_menu_destroyed();

    void on_profile_menu_destroyed(QObject *arg1);

private:
    Ui::profile_menu *ui;
};

#endif // PROFILE_MENU_H
