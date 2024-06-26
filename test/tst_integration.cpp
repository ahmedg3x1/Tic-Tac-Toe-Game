#include <gtest/gtest.h>

#include "../src/game_window.h"

class IntegrationTest : public ::testing::Test {
 public:
  game_window game;
  string username;
  string passward;
  string fileName;
  UserData testUser;

  void SetUp() override {
    username = "testUser";
    passward = "1233456";
    testUser.username = username;
    testUser.passwordHash = md5(passward);
    game.PlayerOneBoardCode = player_X;
    game.PlayerTwoBoardCode = player_O;
    fileName = username + "_data.txt";
  }
  ofstream createTestFile() {
    ofstream testFile(fileName);
    testFile << testUser.username << " " << testUser.passwordHash << endl;
    return testFile;
  }
};

TEST_F(IntegrationTest, integration_test) {
  ofstream testFile = createTestFile();
  testFile.close();

  /*      test board
        1, 2 ,2,
        2, 1 ,1,
        0, 0, 1
*/
  game.playerMove(0, 0, game.PlayerOneBoardCode);
  game.playerMove(0, 1, game.PlayerTwoBoardCode);
  game.playerMove(0, 2, game.PlayerTwoBoardCode);

  game.playerMove(1, 0, game.PlayerTwoBoardCode);
  game.playerMove(1, 1, game.PlayerOneBoardCode);
  game.playerMove(1, 2, game.PlayerOneBoardCode);

  game.playerMove(2, 2, game.PlayerOneBoardCode);
  // std::cout <<"\n" << game.checkGameState()<<" "<< game.winner;
  SaveLastGame(testUser, game.board, game.winner, true, game.checkGameState(), game.PlayerOneBoardCode);
  loadUserData(testUser, fileName);
  GameRecord gameRecord = testUser.games[0];

  for (int i = 0; i < 9; ++i)
    EXPECT_EQ((*(*(game.board) + i)), gameRecord.moves[i]);

  remove(fileName.c_str());
}
