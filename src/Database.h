#pragma once
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

enum login_result { user_wrong, login_correct, password_wrong, database_error };
enum register_result {
  null_user,
  register_correct,
  null_password,
  weak_password,
  user_is_already_registered,
  bad_user
};

struct GameRecord {
  string date;
  string time;
  string opponentName;
  bool accountHolderStarted;
  int accountHolder;
  int won;
  int moves[9];

  int gamestate;
};

struct UserData {
  string username;
  string passwordHash;       // Store hashed password instead of plain password
  vector<GameRecord> games;  // Use vector to store multiple game records
};

bool fileExists(const string& filename);
void saveUserData(const UserData& user);
void loadUserData(UserData& user, const string& filename);
register_result registerUser(const string& username, const string& password);
login_result login(UserData& loggedInUser);
void SaveLastGame(UserData& host, const int moves[3][3], int won, bool accountHolderStarted, int gamestate,
                  int accountHolder, bool PVP = false, string opponentName = "Machine", UserData* guest = nullptr);
void viewHistory(const UserData& user);
int wins(const string& username);
int loses(const string& username);
int ties(const string& username);
string md5(std::string dat);
