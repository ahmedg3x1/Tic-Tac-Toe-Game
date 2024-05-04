#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QMainWindow>
#include <Game.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class game_window;
}
QT_END_NAMESPACE

class game_window : public QMainWindow
{
    Q_OBJECT

public:
    game_window(QWidget *parent = nullptr);
    ~game_window();

private slots:
    void on_Slot_1_clicked();

    void on_Slot_2_clicked();

    void on_Slot_3_clicked();

    void on_Slot_4_clicked();

    void on_Slot_5_clicked();

    void on_Slot_6_clicked();

    void on_Slot_7_clicked();

    void on_Slot_8_clicked();

    void on_Slot_9_clicked();

private:
    Ui::game_window *ui;
    bool isPlayerXTurn; // Variable to track current player's turn
};

#endif // GAME_WINDOW_H
