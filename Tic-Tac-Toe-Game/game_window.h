#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class game_window;
}
QT_END_NAMESPACE

const int player_X = 1;     // player_X,player_O can not equal zero,
const int player_O = 2;     // because Empty space = zero

const int Continue_State = 0;
const int Winner_State = 1;
const int Tie_State = 2;

const int winScore = 1;
const int loseScore = -1;
const int tieScore = 0;
const int EMPTY = 0;

class game_window : public QMainWindow
{
    Q_OBJECT

public:
    game_window(QWidget *parent = nullptr, bool PVAI = false,
                QString Player_One_Name = "Host", int Player_One_Tic = player_X,
                QString Player_Two_Name = "Guest", int Player_Two_Tic = player_O);
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

    void on_Home_clicked();

    void on_Play_Again_clicked();

private:
    Ui::game_window *ui;
    QWidget* myparent;

    QPushButton* Slot[3][3];

    int player_1_tic, player_2_tic;
    QString player_1_name, player_2_name;
    bool aiEnable;

    bool isPlayerOneTurn; // Variable to track current player's turn

    int winner = 0;

    int board[3][3] = {};
    int timelog[3][3] = {};
    int log_counter = 1;

    /* Private functions */
    bool playerMove(int row, int column, int player);

    int minimax(bool isMaximizingPlayer, int alpha, int beta);

    void AiMove();

    int checkGameState();

    void controlGameFlow(int gameState);
};

#endif // GAME_WINDOW_H
