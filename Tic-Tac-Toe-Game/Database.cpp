#include "Database.h"


// Function to check if a file exists
bool Database::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void Database::saveUserData(const UserData& user) {
    ofstream file(user.username + "_data.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    file << user.username << " " << user.passwordHash << endl; // Save username and password hash
    for (const auto& game : user.games) {
        file << game.time << " " << game.won << " " << game.firstPlayer << " " << game.gamestate << " ";
        for (int i = 0; i < 9; ++i) {
            file << game.moves[i] << " "; // Save moves array
        }
        file << endl;
    }
    file.close();
}

// Function to load user data from a file
void Database::loadUserData(UserData& user, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
    user.games.clear(); // Clear existing game history
    string line;
    getline(file, line);
    stringstream ss(line);
    ss >> user.username >> user.passwordHash;
    while (getline(file, line)) {
        stringstream ss(line);
        GameRecord game;
        ss >> game.time >> game.won >> game.firstPlayer >> game.gamestate;
        for (int i = 0; i < 9; ++i) {
            ss >> game.moves[i]; // Load moves array
        }
        user.games.push_back(game);
    }
    file.close();
}

void Database::registerUser() {
    UserData newUser;
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    // Check if the username already exists
    if (fileExists(username + "_data.txt")) {
        cout << "Username already exists. Please choose a different username." << endl;
        return; // Exit the function if username already exists
    }

    cout << "Enter password: ";
    cin >> password;
    string passwordHash = password; // Hash password
    newUser.username = username;
    newUser.passwordHash = passwordHash;
    newUser.games.clear(); // Initialize games as empty vector
    saveUserData(newUser);
    cout << "User registered successfully!" << endl;
}

bool Database::login(UserData& loggedInUser) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    string passwordHash = password; // Hash password
    string filename = username + "_data.txt";
    if (!fileExists(filename)) {
        cout << "User does not exist or invalid username/password." << endl;
        return false;
    }
    loggedInUser.username = username;
    loggedInUser.passwordHash = passwordHash;
    loadUserData(loggedInUser, filename); // Load user data
    if (loggedInUser.passwordHash == passwordHash) {
        cout << "Login successful!" << endl;
        return true;
    }
    cout << "Invalid username or password." << endl;
    return false;
}
void Database::playGame(UserData& user, const int moves[3][3], int won, string time, int firstPlayer, int gamestate) {
    // Implement tic-tac-toe game logic here
    // After the game, save the game record to the user's data
    GameRecord game;
    game.won = won;
    game.time = time;
    game.firstPlayer = firstPlayer;
    game.gamestate = gamestate;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) 
            game.moves[3*i+j] = moves[i][j];
    }

    user.games.push_back(game);
    saveUserData(user);
}

// Function to view game history for a specific user
void Database::viewHistory(const UserData& user, int& firstPlayer, int log[3][3]) {
    cout << "User: " << user.username << endl;
    if (user.games.empty()) {
        cout << "No game history available." << endl;
    }
    else {
        cout << "Game History : " << endl;
        int c = 1;
        for (const auto& game : user.games) {
            cout <<  c++ << " -  Date: " << game.time << ", Won: " << game.won << ", FirsttoPlay: " << game.firstPlayer << ", GameState: " << game.gamestate << endl;
           }
        int b = 0;
        cout << "select Board : ";
        cin >> b;
        firstPlayer = user.games[b - 1].firstPlayer;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                log[i][j] = user.games[b - 1].moves[i*3+j];
    
            cout << endl;
        
    }
}