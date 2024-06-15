#include "game_window.h"
#include "ui_game_window.h"

extern QString player_1_name, player_2_name;
extern QString player_1_tic,  player_2_tic;

game_window::game_window(QWidget *parent, bool PVAI)
    : QMainWindow(parent)
    , ui(new Ui::game_window)
    , aiEnable(PVAI)
{
    ui->setupUi(this);
    myparent = parent;

    PlayerOneBoardCode = (player_1_tic == "X") ? player_X : player_O;
    PlayerTwoBoardCode = (player_2_tic == "X") ? player_X : player_O;

    PlayerOneisStarting = true;     // Player One starts every time
    isPlayerOneTurn = true;         // Initialize the player turn to 'X'
    ui->Label->setText(player_1_name + QString(" Starts !"));


    Slot[0][0] = ui->Slot_1;
    Slot[0][1] = ui->Slot_2;
    Slot[0][2] = ui->Slot_3;
    Slot[1][0] = ui->Slot_4;
    Slot[1][1] = ui->Slot_5;
    Slot[1][2] = ui->Slot_6;
    Slot[2][0] = ui->Slot_7;
    Slot[2][1] = ui->Slot_8;
    Slot[2][2] = ui->Slot_9;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

game_window::~game_window()
{
    delete ui;
}


void game_window::on_Slot_1_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_1->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_1->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(0, 0, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_2_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_2->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_2->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(0, 1, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_3_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_3->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_3->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(0, 2, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_4_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_4->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_4->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(1, 0, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_5_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_5->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_5->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(1, 1, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_6_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_6->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_6->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(1, 2, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_7_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_7->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_7->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(2, 0, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_8_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_8->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_8->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(2, 1, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Slot_9_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_9->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_9->setText(isPlayerOneTurn ? player_1_tic : player_2_tic);

        playerMove(2, 2, isPlayerOneTurn ? PlayerOneBoardCode : PlayerTwoBoardCode);

        if(aiEnable && checkGameState() == Continue_State){
            AiMove();
        }
        else {
            // Toggle player turn
            isPlayerOneTurn = !isPlayerOneTurn;
        }
        controlGameFlow(checkGameState());
    }
}


void game_window::on_Home_clicked()
{
    close();
    myparent->show();
}


void game_window::on_Play_Again_clicked()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
            Slot[i][j]->setEnabled(true);
            Slot[i][j]->setText("");
        }

    if(aiEnable){
        PlayerOneisStarting = true;
        isPlayerOneTurn = true;
    }
    else{
        PlayerOneisStarting = !PlayerOneisStarting;       // Switch the starting player
        isPlayerOneTurn = PlayerOneisStarting;
    }

    ui->Label->setText((PlayerOneisStarting ? player_1_name : player_2_name) + QString(" Starts !"));

    winner = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}


bool game_window::playerMove(int row, int column, int player)
{
    if (board[row][column] == EMPTY) {
        board[row][column] = player;
        timelog[row][column] = log_counter;
        log_counter++;
        return 1;
    }
    return 0;
}


int game_window::minimax(bool isMaximizingPlayer = false, int alpha = -10, int beta = 10)
{
    if (checkGameState() != Continue_State) {
        if (winner == PlayerTwoBoardCode) return winScore;
        else if (winner == PlayerOneBoardCode) return loseScore;
        else return tieScore;
    }

    if (isMaximizingPlayer) {
        int bestScore = -10;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PlayerTwoBoardCode;
                    int score = minimax(false, alpha, beta);
                    bestScore = std::max(bestScore, score);
                    alpha = std::max(alpha, score);
                    board[i][j] = EMPTY;
                    if (alpha >= beta) break;
                }
                if (alpha >= beta) break;
            }
        return bestScore;
    }
    else {
        int bestScore = 10;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PlayerOneBoardCode;
                    int score = minimax(true, alpha, beta);
                    bestScore = std::min(bestScore, score);
                    beta = std::min(beta, bestScore);
                    board[i][j] = EMPTY;
                    if (alpha >= beta) break;
                }
                if (alpha >= beta) break;
            }
        return bestScore;
    }
}


void game_window::AiMove()
{
    int row, coulmn;
    int bestScore = -10;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PlayerTwoBoardCode;
                int score = minimax();
                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                    coulmn = j;
                }
                board[i][j] = EMPTY;
            }

        }
    playerMove(row, coulmn, PlayerTwoBoardCode);

    Slot[row][coulmn]->setText(player_2_tic);
}


//change the Winner Var to ((the player pice)) but it was a tie it will change the var to ((0)).
int game_window::checkGameState()
{

    //Check Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] != EMPTY && board[i][1] == board[i][0] && board[i][2] == board[i][0]) {
            winner = board[i][0];
            return Winner_State;
        }

    //Check Coulmns
    for (int j = 0; j < 3; j++)
        if (board[0][j] != EMPTY && board[1][j] == board[0][j] && board[2][j] == board[0][j]) {
            winner = board[0][j];
            return Winner_State;
        }

    //Check diagonal
    if (board[0][0] != EMPTY && board[1][1] == board[0][0] && board[2][2] == board[0][0]) {
        winner = board[0][0];
        return Winner_State;
    }
    else if (board[0][2] != EMPTY && board[1][1] == board[0][2] && board[2][0] == board[0][2]) {
        winner = board[0][2];
        return Winner_State;
    }

    //Check tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return Continue_State;  // game is not finished yet;
    }
    winner = 0;
    return Tie_State;
}


void game_window::controlGameFlow(int gameState)
{
    switch (gameState)
    {
    case Continue_State:
        ui->Label->setText("");
        break;

    case Winner_State:
        switch (winner)
        {
        case player_X:
            ui->Label->setText(((player_1_tic == "X") ? player_1_name : player_2_name) + QString(" Won !"));
            break;

        case player_O:
            ui->Label->setText(((player_1_tic == "O") ? player_1_name : player_2_name) + QString(" Won !"));
            break;
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                Slot[i][j]->setEnabled(false);
        break;

    case Tie_State:
        ui->Label->setText("Tie !");
        break;
    }

    return;
}

