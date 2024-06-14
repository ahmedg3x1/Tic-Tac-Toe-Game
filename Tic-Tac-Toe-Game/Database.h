#pragma once
#include <fstream>
#include <iostream> 
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

enum login_result {user_wrong,correct,password_wrong,database_error};



struct GameRecord {
    int moves[9];
    int won;
    string time;
    int firstPlayer;
    int gamestate;
};

struct UserData {
    string username;
    string passwordHash; // Store hashed password instead of plain password
    vector<GameRecord> games; // Use vector to store multiple game records
};

class Database {
public:

    UserData userdata;
	bool fileExists(const string& filename);
	void saveUserData(const UserData& user);
	void loadUserData(UserData& user, const string& filename);
    void registerUser(const string& username, const string& password);
    login_result login(UserData& loggedInUser);
	void playGame(UserData& user, const int moves[3][3], int won, string time, int firstPlayer, int gamestate);
    void viewHistory(const UserData& user);
    string md5(std::string dat);
};

