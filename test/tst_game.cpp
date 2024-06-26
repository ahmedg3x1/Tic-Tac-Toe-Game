#include <gtest/gtest.h>

#include "../src/game_window.h"

class GameTest : public ::testing::Test {
 public:
  game_window game;
  void emptyBoard() {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) game.board[i][j] = EMPTY;
  }
  void applayTestBoard(int testBoard[3][3]) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) game.board[i][j] = testBoard[i][j];
  }
  void SetUp() override {
    game.PlayerOneBoardCode = player_X;
    game.PlayerTwoBoardCode = player_O;
  }
};

TEST_F(GameTest, checkGameState) {
  emptyBoard();
  EXPECT_EQ(Start_State, game.checkGameState());

  int testWinDiagonalBoard[3][3] = {1, 2, 2, 2, 1, 1, 0, 0, 1};

  applayTestBoard(testWinDiagonalBoard);
  EXPECT_EQ(Winner_State, game.checkGameState());
  EXPECT_EQ(game.winner, 1);

  int testWinRowBoard[3][3] = {2, 2, 2, 2, 1, 1, 0, 0, 1};
  applayTestBoard(testWinRowBoard);
  EXPECT_EQ(Winner_State, game.checkGameState());
  EXPECT_EQ(game.winner, 2);

  int testWinCoulmnBoard[3][3] = {1, 2, 2, 2, 2, 1, 0, 2, 0};
  applayTestBoard(testWinCoulmnBoard);
  EXPECT_EQ(Winner_State, game.checkGameState());
  EXPECT_EQ(game.winner, 2);

  int testTieBoard[3][3] = {1, 2, 2, 2, 1, 1, 1, 2, 2};
  applayTestBoard(testTieBoard);
  EXPECT_EQ(Tie_State, game.checkGameState());
  EXPECT_EQ(game.winner, 0);

  int testContinueBoard[3][3] = {1, 2, 2, 2, 2, 1, 0, 0, 1};
  applayTestBoard(testContinueBoard);
  EXPECT_EQ(Continue_State, game.checkGameState());
}

TEST_F(GameTest, playerMove) {
  emptyBoard();
  int row = 0;
  int col = 1;
  int testPlayer = game.PlayerOneBoardCode;
  game.playerMove(row, col, testPlayer);
  EXPECT_EQ(game.board[row][col], testPlayer);
  EXPECT_FALSE(game.playerMove(row, col, testPlayer));  // check if the same slot can be used again
}

TEST_F(GameTest, AiMove) {
  int testBoard[3][3] = {1, 2, 2, 2, 1, 1, 0, 0, 0};
  applayTestBoard(testBoard);

  game.AiMove();

  EXPECT_EQ(game.board[2][2], game.PlayerTwoBoardCode);
}
