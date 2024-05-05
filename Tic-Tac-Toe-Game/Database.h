#pragma once
#include <fstream>
#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

class Database {
public:
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
	bool fileExists(const string& filename);
	void saveUserData(const UserData& user);
	void loadUserData(UserData& user, const string& filename);
	void registerUser();
	bool login(UserData& loggedInUser);
	void playGame(UserData& user, const int moves[3][3], int won, string time, int firstPlayer, int gamestate);
	void viewHistory(const UserData& user, int& firstPlayer, int log[3][3]);
};

