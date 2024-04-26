#include <iostream>
#include "Game.h"


const int player_X = 1;
const int player_O = 2;
//player_X,player_O can not equal zero,because Empty space = zero

bool AI_Enable = 0;

int main() {
	Game game = Game(player_X, player_O, player_X, AI_Enable);
	game.game_start();
	std::cout << "=============================log start================================"<<std::endl;
	game.showLog();
	std::cout << "==============================log end=================================";
	return 0;
}


