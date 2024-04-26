#include "Game.h"
Game::Game(int playerOne, int playerTwo, int firstToPlay, bool AI_Enable) {
	player_1 = playerOne;
	player_2 = playerTwo;
	firstPlayer = firstToPlay;
	aiEnable = AI_Enable;
}


//-------------------to be edited when GUI is finished---------------------
#include <iostream> 

void Game::game_start() {
	int row, coulmn;
	int currentPlayer = firstPlayer;
	showBoard();
	while (gameState == Continue_State) {
		if (aiEnable && currentPlayer == player_2) {
			AiMove();
			std::cout << "player - " << currentPlayer << " --Ai finished-- ";

		}
		else {
			std::cout << "player - " << currentPlayer << "--Enter row[0:2] coulmen[0:2] : ";
			std::cin >> row >> coulmn;

			bool validMove = playerMove(row, coulmn, currentPlayer);

			while (!validMove) {
				std::cout << "Not Valid Try again : ";
				std::cin >> row >> coulmn;
				validMove = playerMove(row, coulmn, currentPlayer);
			}
		}
		std::cout << std::endl << "=================================================== " << std::endl;

		showBoard();

		currentPlayer = currentPlayer != player_1 ? player_1 : player_2; //Switch Players


		gameState = checkGameState();
	}
	std::cout << "Game State: " << gameState << " winner :" << winner << std::endl;
}


void Game::showBoard() {
	std::cout << std::endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << board[i][j] << "  ";

		std::cout << std::endl;
	}

}

void Game::showLog() {
	int logBoard[3][3] = {};

	int moveStorage[9][2];
	for (int i = 0; i < 9; i++) {
		moveStorage[i][0] = -1;
		moveStorage[i][1] = -1;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (timelog[i][j] != 0) {
				moveStorage[timelog[i][j] - 1][0] = i;
				moveStorage[timelog[i][j] - 1][1] = j;
			}
		}
	}

	int row, column;
	bool showlog;

	std::cout << "enter 1 to show log or 0 to exit : ";
	std::cin >> showlog;
	std::cin.ignore();

	if (showlog) {
		for (int i = 0; i < 9; i++) {
			if (moveStorage[i][0] != -1) {
				row = moveStorage[i][0];
				column = moveStorage[i][1];
				logBoard[row][column] = board[row][column];

				std::cout << std::endl;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++)
						std::cout << logBoard[i][j] << "  ";
					std::cout << std::endl;
				}
				std::cout << "press enter to cont....";
				std::cin.ignore();
			}
		}

	}

}
//-------------------------------the previous to be edited when GUI is finished----------------------------------------



//change the Winner Var to ((the player pice)) but it was a tie it will change the var to ((0)). 
int Game::checkGameState() {

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

	//Check dignal 

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


bool Game::playerMove(int row, int column, int player) {
	if (board[row][column] == EMPTY) {
		board[row][column] = player;
		timelog[row][column] = log_counter;
		log_counter++;
		return 1;
	}
	return 0;
}



int Game::minimax(bool isMaximizingPlayer = false, int alpha = -10, int beta = 10) {
	if (checkGameState() != Continue_State) {
		if (winner == player_2) return winScore;
		else if (winner == player_1) return loseScore;
		else return tieScore;
	}

	if (isMaximizingPlayer) {
		int bestScore = -10;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == EMPTY) {
					board[i][j] = player_2;
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
					board[i][j] = player_1;
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

void Game::AiMove() {
	int row, coulmn;
	int bestScore = -10;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY) {
				board[i][j] = player_2;
				int score = minimax();
				if (score > bestScore) {
					bestScore = score;
					row = i;
					coulmn = j;
				}
				board[i][j] = EMPTY;
			}

		}
	playerMove(row, coulmn, player_2);
}

