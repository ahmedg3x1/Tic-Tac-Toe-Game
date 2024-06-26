#include <QApplication>

#include "login_window.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  login_window my_main_menu;
  my_main_menu.show();
  return a.exec();
}
