#include "login_window.h"
#include "register_window.h"
#include <QApplication>
#include "entry_menu.h"
#include "profile_menu.h"
#include "Database.h"

Database my_database;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_window my_main_menu;
    my_main_menu.show();

    return a.exec();
}
