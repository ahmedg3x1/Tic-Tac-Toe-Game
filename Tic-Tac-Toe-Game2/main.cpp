#include "mainwindow.h"
#include "register_window.h"
#include <QApplication>
#include "entry_menu.h"
#include "profile_menu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow my_main_menu;
    my_main_menu.show();

    return a.exec();
}
