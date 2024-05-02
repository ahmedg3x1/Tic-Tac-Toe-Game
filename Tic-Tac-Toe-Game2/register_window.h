#ifndef REGISTER_WINDOW_H
#define REGISTER_WINDOW_H

#include <QMainWindow>

namespace Ui {
class register_window;
}

class register_window : public QMainWindow
{
    Q_OBJECT

public:
     register_window(QWidget *parent = nullptr);
     QWidget *myparent;
    ~register_window();



private slots:


     void on_register_button_clicked();

     void on_cancel_button_clicked();

private:
    Ui::register_window *ui;
};

#endif // REGISTER_WINDOW_H
