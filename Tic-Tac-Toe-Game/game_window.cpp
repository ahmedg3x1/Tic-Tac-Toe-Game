#include "game_window.h"
#include "ui_game_window.h"

game_window::game_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game_window)
{
    ui->setupUi(this);
    myparent = parent;
    isPlayerXTurn = true;       // Initialize the player turn to 'X'

    board[0][0] = ui->Slot_1;
    board[0][1] = ui->Slot_2;
    board[0][2] = ui->Slot_3;
    board[1][0] = ui->Slot_4;
    board[1][1] = ui->Slot_5;
    board[1][2] = ui->Slot_6;
    board[2][0] = ui->Slot_7;
    board[2][1] = ui->Slot_8;
    board[2][2] = ui->Slot_9;
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
        ui->Slot_1->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_2_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_2->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_2->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_3_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_3->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_3->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_4_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_4->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_4->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_5_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_5->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_5->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_6_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_6->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_6->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_7_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_7->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_7->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_8_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_8->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_8->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Slot_9_clicked()
{
    // Check if the button is already clicked and contains 'X' or 'O'
    if (ui->Slot_9->text().isEmpty()) {
        // Set 'X' or 'O' based on current player's turn
        ui->Slot_9->setText(isPlayerXTurn ? "X" : "O");
        // Toggle player turn
        isPlayerXTurn = !isPlayerXTurn;
    }
}


void game_window::on_Home_clicked()
{
    close();
    myparent->show();
}


void game_window::on_Play_Again_clicked()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            board[i][j]->setText("");
    }
}

