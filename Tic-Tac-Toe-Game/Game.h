#pragma once
class Game
{
public:	
	const int Continue_State = 0;
	const int Winner_State = 1;
	const int Tie_State = 2;

	const int winScore = 1;
	const int loseScore = -1;
	const int tieScore = 0;
	const int EMPTY = 0;

	int board[3][3] = {};
	int timelog[3][3] = {};
	int log_counter = 1;

	int winner = 0;
	bool aiEnable;

	int player_1;
	int player_2;
	int firstPlayer;


	int gameState = Continue_State;

	Game(int playerOne, int playerTwo, int firstToPlay, bool AI_Enable); // player one is allways the account owner
	
	void game_start();
	void showBoard();
	void showLog(int firstPlayer, int timelog[3][3]);
	bool playerMove(int row, int column, int player);
	int checkGameState();
	int minimax(bool isMaximizingPlayer, int alpha, int beta);
	void AiMove();


};

