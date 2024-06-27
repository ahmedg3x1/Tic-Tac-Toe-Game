#include <gtest/gtest.h>

#include "../src/Database.h"

class DatabaseTest : public ::testing::Test {
 public:
  UserData testUser;
  GameRecord testGameRecord;
  string username;
  string passward;
  string fileName;
  int moves[3][3] = {1, 4, 6, 0, 2, 3, 8, 7, 5};
  void SetUp() override {
    username = "testUser";
    passward = "1233456";
    testGameRecord.date = "2024/6/24";
    testGameRecord.time = "12:25:32";
    testGameRecord.opponentName = "Machine";
    testGameRecord.accountHolderStarted = true;
    testGameRecord.accountHolder = 1;  //(player_X)
    testGameRecord.won = 2;            // Machine(player_O)
    for (int i = 0; i < 9; ++i) {
      testGameRecord.moves[i] = *(*(moves) + i);
    }
    testGameRecord.gamestate = 1;

    testUser.username = username;
    testUser.passwordHash = md5(passward);
    fileName = username + "_data.txt";
    remove(fileName.c_str());  // remove old test attempt file if exist
  }
  ofstream createTestFile() {
    ofstream testFile(fileName);
    testFile << testUser.username << " " << testUser.passwordHash << endl;
    return testFile;
  }
};

TEST_F(DatabaseTest, FileExists) {
  ofstream file(fileName);
  EXPECT_TRUE(fileExists(fileName));
  file.close();
  remove(fileName.c_str());
  EXPECT_FALSE(fileExists(fileName));
}

TEST_F(DatabaseTest, Register) {
  ASSERT_EQ(register_correct, registerUser(username, passward))
      << "--Error: Register failed--";

  ifstream file(fileName);
  ASSERT_TRUE(file.good())
      << "--Error: Register failed No file has been created--";
  file.close();
  EXPECT_EQ(user_is_already_registered, registerUser(username, passward));
  EXPECT_EQ(null_user, registerUser("", "123456"));
  EXPECT_EQ(null_password, registerUser("abc", ""));
  EXPECT_EQ(bad_user, registerUser("a bc", "123456"));
  EXPECT_EQ(weak_password, registerUser("abc", "123"));

  remove(fileName.c_str());
}

TEST_F(DatabaseTest, Login) {
  UserData loginTestUser = {"LoginTestUser", "1233456"};
  loginTestUser.passwordHash = md5(loginTestUser.passwordHash);
  UserData wrongPassward = {"LoginTestUser", "LoginWrongPassward"};
  UserData wrongUsername = {"LoginWrongUsername", "1233456"};
  string fileName = loginTestUser.username + "_data.txt";

  ofstream file(fileName);
  file << loginTestUser.username << " " << md5(loginTestUser.passwordHash)
       << endl;
  file.close();

  EXPECT_EQ(user_wrong, login(wrongUsername));
  EXPECT_EQ(password_wrong, login(wrongPassward));
  EXPECT_EQ(login_correct, login(loginTestUser));
  EXPECT_NE(database_error, login(loginTestUser));
  remove(fileName.c_str());
}

TEST_F(DatabaseTest, SaveLastGame) {
  ofstream testFile = createTestFile();
  testFile.close();

  // test :: ai -> enable, accountHolder -> player_X, Machine -> player_O,
  // gamestate -> 1 (win state)

  SaveLastGame(testUser, moves, testGameRecord.won,
               testGameRecord.accountHolderStarted, testGameRecord.gamestate,
               testGameRecord.accountHolder);
  ifstream file(testUser.username + "_data.txt");
  string line;
  getline(file, line);
  getline(file, line);
  stringstream ss(line);
  GameRecord game;
  ss >> game.date >> game.time >> game.opponentName >>
      game.accountHolderStarted >> game.accountHolder >> game.won >>
      game.gamestate;
  for (int i = 0; i < 9; ++i) {
    ss >> game.moves[i];
    EXPECT_EQ((*(*(moves) + i)), game.moves[i]);
  }
  EXPECT_EQ(game.opponentName, testGameRecord.opponentName);
  EXPECT_EQ(game.accountHolderStarted, testGameRecord.accountHolderStarted);
  EXPECT_EQ(game.accountHolder, testGameRecord.accountHolder);
  EXPECT_EQ(game.won, testGameRecord.won);
  EXPECT_EQ(game.gamestate, testGameRecord.gamestate);

  file.close();
  remove(fileName.c_str());
}

TEST_F(DatabaseTest, loadUserData) {
  ofstream testFile = createTestFile();

  testFile << testGameRecord.date << " " << testGameRecord.time << " "
           << testGameRecord.opponentName << " "
           << testGameRecord.accountHolderStarted << " "
           << testGameRecord.accountHolder << " " << testGameRecord.won << " "
           << testGameRecord.gamestate << " ";
  for (int i = 0; i < 9; ++i) testFile << testGameRecord.moves[i] << " ";

  testFile.close();

  loadUserData(testUser, fileName);
  GameRecord game = testUser.games[0];

  for (int i = 0; i < 9; ++i) {
    EXPECT_EQ(game.moves[i], testGameRecord.moves[i]);
  }
  EXPECT_EQ(game.opponentName, testGameRecord.opponentName);
  EXPECT_EQ(game.accountHolderStarted, testGameRecord.accountHolderStarted);
  EXPECT_EQ(game.accountHolder, testGameRecord.accountHolder);
  EXPECT_EQ(game.won, testGameRecord.won);
  EXPECT_EQ(game.gamestate, testGameRecord.gamestate);

  remove(fileName.c_str());
}
