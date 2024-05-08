#define _CRT_SECURE_NO_WARNINGS

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

	bool playerMove(int row, int column, int player);
	int checkGameState();
	int minimax(bool isMaximizingPlayer, int alpha, int beta);
	void AiMove();


};



Game::Game(int playerOne, int playerTwo, int firstToPlay, bool AI_Enable) {
	player_1 = playerOne;
	player_2 = playerTwo;
	firstPlayer = firstToPlay;
	aiEnable = AI_Enable;
}


//-------------------to be edited when GUI is finished---------------------
#include <iostream> 

void Game::game_start() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = 0;
	int row, coulmn;
	int currentPlayer = firstPlayer;
	showBoard();
	while (gameState == Continue_State) {
		if (aiEnable && currentPlayer == player_2) {
			AiMove();
			std::cout << "player - 2 --Ai finished-- ";

		}
		else {
			std::cout << "player - " << ((currentPlayer == player_1) ? 1 : 2) << "--Enter row[0:2] coulmen[0:2] : ";
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
	std::cout << "=================================================== " << std::endl << std::endl;
}


void Game::showBoard() {
	std::cout << std::endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << board[i][j] << "  ";

		std::cout << std::endl;
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

#include <fstream>
#include <iostream> 
#include <vector>
#include <sstream>
#include <cstring>
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
	void viewHistory(const UserData& user);
	string md5(std::string dat);
};



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
	string passwordHash = md5(password); // Hash password
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
	string passwordHash = md5(password); // Hash password
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
			game.moves[3 * i + j] = moves[i][j];
	}

	user.games.push_back(game);
	saveUserData(user);
}
extern const int player_X;
extern const int player_O;
// Function to view game history for a specific user
void showLog(int firstPlayer, int timelog[3][3]) {

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
	int currentPlayer = firstPlayer;

	std::cin.ignore();

	for (int i = 0; i < 9; i++) {
		if (moveStorage[i][0] != -1) {
			row = moveStorage[i][0];
			column = moveStorage[i][1];
			logBoard[row][column] = currentPlayer;

			std::cout << std::endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					std::cout << logBoard[i][j] << "  ";
				std::cout << std::endl;
			}
			std::cout << "press enter to cont....";
			std::cin.ignore();
			currentPlayer = currentPlayer != player_X ? player_X : player_O; //Switch Players
		}
	}
}

void Database::viewHistory(const UserData& user) {
	cout << "User: " << user.username << endl;
	if (user.games.empty()) {
		cout << "No game history available." << endl;
	}
	else {
		cout << "Game History : " << endl;
		int c = 1;
		for (const auto& game : user.games) {
			cout << c++ << " -  Date: " << game.time << ", Won: " << game.won << ", FirsttoPlay: " << game.firstPlayer << ", GameState: " << game.gamestate << endl;
		}
		int b = 0;
		int firstPlayer;
		int log[3][3];
		cout << "select Board : ";
		cin >> b;
		firstPlayer = user.games[b - 1].firstPlayer;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				log[i][j] = user.games[b - 1].moves[i * 3 + j];
		cout << endl;

		cout << "=============================log start================================" << endl;
		showLog(firstPlayer, log);
		cout << "==============================log end=================================" << endl;;

	}
}

//=======password hashing algorithm from :: https://github.com/ulwanski/md5 =====================//
#ifndef HAVE_OPENSSL

#define F(x, y, z)   ((z) ^ ((x) & ((y) ^ (z))))
#define G(x, y, z)   ((y) ^ ((z) & ((x) ^ (y))))
#define H(x, y, z)   ((x) ^ (y) ^ (z))
#define I(x, y, z)   ((y) ^ ((x) | ~(z)))
#define STEP(f, a, b, c, d, x, t, s) \
		(a) += f((b), (c), (d)) + (x) + (t); \
		(a) = (((a) << (s)) | (((a) & 0xffffffff) >> (32 - (s)))); \
		(a) += (b);

#if defined(__i386__) || defined(__x86_64__) || defined(__vax__)
#define SET(n) \
			(*(MD5_u32 *)&ptr[(n) * 4])
#define GET(n) \
			SET(n)
#else
#define SET(n) \
			(ctx->block[(n)] = \
			(MD5_u32)ptr[(n) * 4] | \
			((MD5_u32)ptr[(n) * 4 + 1] << 8) | \
			((MD5_u32)ptr[(n) * 4 + 2] << 16) | \
			((MD5_u32)ptr[(n) * 4 + 3] << 24))
#define GET(n) \
			(ctx->block[(n)])
#endif

typedef unsigned int MD5_u32;

typedef struct {
	MD5_u32 lo, hi;
	MD5_u32 a, b, c, d;
	unsigned char buffer[64];
	MD5_u32 block[16];
} MD5_CTX;

static void MD5_Init(MD5_CTX* ctx);
static void MD5_Update(MD5_CTX* ctx, const void* data, unsigned long size);
static void MD5_Final(unsigned char* result, MD5_CTX* ctx);

static const void* body(MD5_CTX* ctx, const void* data, unsigned long size) {
	const unsigned char* ptr;
	MD5_u32 a, b, c, d;
	MD5_u32 saved_a, saved_b, saved_c, saved_d;

	ptr = (const unsigned char*)data;

	a = ctx->a;
	b = ctx->b;
	c = ctx->c;
	d = ctx->d;

	do {
		saved_a = a;
		saved_b = b;
		saved_c = c;
		saved_d = d;

		STEP(F, a, b, c, d, SET(0), 0xd76aa478, 7)
			STEP(F, d, a, b, c, SET(1), 0xe8c7b756, 12)
			STEP(F, c, d, a, b, SET(2), 0x242070db, 17)
			STEP(F, b, c, d, a, SET(3), 0xc1bdceee, 22)
			STEP(F, a, b, c, d, SET(4), 0xf57c0faf, 7)
			STEP(F, d, a, b, c, SET(5), 0x4787c62a, 12)
			STEP(F, c, d, a, b, SET(6), 0xa8304613, 17)
			STEP(F, b, c, d, a, SET(7), 0xfd469501, 22)
			STEP(F, a, b, c, d, SET(8), 0x698098d8, 7)
			STEP(F, d, a, b, c, SET(9), 0x8b44f7af, 12)
			STEP(F, c, d, a, b, SET(10), 0xffff5bb1, 17)
			STEP(F, b, c, d, a, SET(11), 0x895cd7be, 22)
			STEP(F, a, b, c, d, SET(12), 0x6b901122, 7)
			STEP(F, d, a, b, c, SET(13), 0xfd987193, 12)
			STEP(F, c, d, a, b, SET(14), 0xa679438e, 17)
			STEP(F, b, c, d, a, SET(15), 0x49b40821, 22)
			STEP(G, a, b, c, d, GET(1), 0xf61e2562, 5)
			STEP(G, d, a, b, c, GET(6), 0xc040b340, 9)
			STEP(G, c, d, a, b, GET(11), 0x265e5a51, 14)
			STEP(G, b, c, d, a, GET(0), 0xe9b6c7aa, 20)
			STEP(G, a, b, c, d, GET(5), 0xd62f105d, 5)
			STEP(G, d, a, b, c, GET(10), 0x02441453, 9)
			STEP(G, c, d, a, b, GET(15), 0xd8a1e681, 14)
			STEP(G, b, c, d, a, GET(4), 0xe7d3fbc8, 20)
			STEP(G, a, b, c, d, GET(9), 0x21e1cde6, 5)
			STEP(G, d, a, b, c, GET(14), 0xc33707d6, 9)
			STEP(G, c, d, a, b, GET(3), 0xf4d50d87, 14)
			STEP(G, b, c, d, a, GET(8), 0x455a14ed, 20)
			STEP(G, a, b, c, d, GET(13), 0xa9e3e905, 5)
			STEP(G, d, a, b, c, GET(2), 0xfcefa3f8, 9)
			STEP(G, c, d, a, b, GET(7), 0x676f02d9, 14)
			STEP(G, b, c, d, a, GET(12), 0x8d2a4c8a, 20)
			STEP(H, a, b, c, d, GET(5), 0xfffa3942, 4)
			STEP(H, d, a, b, c, GET(8), 0x8771f681, 11)
			STEP(H, c, d, a, b, GET(11), 0x6d9d6122, 16)
			STEP(H, b, c, d, a, GET(14), 0xfde5380c, 23)
			STEP(H, a, b, c, d, GET(1), 0xa4beea44, 4)
			STEP(H, d, a, b, c, GET(4), 0x4bdecfa9, 11)
			STEP(H, c, d, a, b, GET(7), 0xf6bb4b60, 16)
			STEP(H, b, c, d, a, GET(10), 0xbebfbc70, 23)
			STEP(H, a, b, c, d, GET(13), 0x289b7ec6, 4)
			STEP(H, d, a, b, c, GET(0), 0xeaa127fa, 11)
			STEP(H, c, d, a, b, GET(3), 0xd4ef3085, 16)
			STEP(H, b, c, d, a, GET(6), 0x04881d05, 23)
			STEP(H, a, b, c, d, GET(9), 0xd9d4d039, 4)
			STEP(H, d, a, b, c, GET(12), 0xe6db99e5, 11)
			STEP(H, c, d, a, b, GET(15), 0x1fa27cf8, 16)
			STEP(H, b, c, d, a, GET(2), 0xc4ac5665, 23)
			STEP(I, a, b, c, d, GET(0), 0xf4292244, 6)
			STEP(I, d, a, b, c, GET(7), 0x432aff97, 10)
			STEP(I, c, d, a, b, GET(14), 0xab9423a7, 15)
			STEP(I, b, c, d, a, GET(5), 0xfc93a039, 21)
			STEP(I, a, b, c, d, GET(12), 0x655b59c3, 6)
			STEP(I, d, a, b, c, GET(3), 0x8f0ccc92, 10)
			STEP(I, c, d, a, b, GET(10), 0xffeff47d, 15)
			STEP(I, b, c, d, a, GET(1), 0x85845dd1, 21)
			STEP(I, a, b, c, d, GET(8), 0x6fa87e4f, 6)
			STEP(I, d, a, b, c, GET(15), 0xfe2ce6e0, 10)
			STEP(I, c, d, a, b, GET(6), 0xa3014314, 15)
			STEP(I, b, c, d, a, GET(13), 0x4e0811a1, 21)
			STEP(I, a, b, c, d, GET(4), 0xf7537e82, 6)
			STEP(I, d, a, b, c, GET(11), 0xbd3af235, 10)
			STEP(I, c, d, a, b, GET(2), 0x2ad7d2bb, 15)
			STEP(I, b, c, d, a, GET(9), 0xeb86d391, 21)

			a += saved_a;
		b += saved_b;
		c += saved_c;
		d += saved_d;

		ptr += 64;
	} while (size -= 64);

	ctx->a = a;
	ctx->b = b;
	ctx->c = c;
	ctx->d = d;

	return ptr;
}

void MD5_Init(MD5_CTX* ctx) {
	ctx->a = 0x67452301;
	ctx->b = 0xefcdab89;
	ctx->c = 0x98badcfe;
	ctx->d = 0x10325476;

	ctx->lo = 0;
	ctx->hi = 0;
}

void MD5_Update(MD5_CTX* ctx, const void* data, unsigned long size) {
	MD5_u32 saved_lo;
	unsigned long used, free;

	saved_lo = ctx->lo;
	if ((ctx->lo = (saved_lo + size) & 0x1fffffff) < saved_lo)
		ctx->hi++;
	ctx->hi += size >> 29;
	used = saved_lo & 0x3f;

	if (used) {
		free = 64 - used;
		if (size < free) {
			memcpy(&ctx->buffer[used], data, size);
			return;
		}

		memcpy(&ctx->buffer[used], data, free);
		data = (unsigned char*)data + free;
		size -= free;
		body(ctx, ctx->buffer, 64);
	}

	if (size >= 64) {
		data = body(ctx, data, size & ~(unsigned long)0x3f);
		size &= 0x3f;
	}

	memcpy(ctx->buffer, data, size);
}

void MD5_Final(unsigned char* result, MD5_CTX* ctx) {
	unsigned long used, free;
	used = ctx->lo & 0x3f;
	ctx->buffer[used++] = 0x80;
	free = 64 - used;

	if (free < 8) {
		memset(&ctx->buffer[used], 0, free);
		body(ctx, ctx->buffer, 64);
		used = 0;
		free = 64;
	}

	memset(&ctx->buffer[used], 0, free - 8);

	ctx->lo <<= 3;
	ctx->buffer[56] = ctx->lo;
	ctx->buffer[57] = ctx->lo >> 8;
	ctx->buffer[58] = ctx->lo >> 16;
	ctx->buffer[59] = ctx->lo >> 24;
	ctx->buffer[60] = ctx->hi;
	ctx->buffer[61] = ctx->hi >> 8;
	ctx->buffer[62] = ctx->hi >> 16;
	ctx->buffer[63] = ctx->hi >> 24;
	body(ctx, ctx->buffer, 64);
	result[0] = ctx->a;
	result[1] = ctx->a >> 8;
	result[2] = ctx->a >> 16;
	result[3] = ctx->a >> 24;
	result[4] = ctx->b;
	result[5] = ctx->b >> 8;
	result[6] = ctx->b >> 16;
	result[7] = ctx->b >> 24;
	result[8] = ctx->c;
	result[9] = ctx->c >> 8;
	result[10] = ctx->c >> 16;
	result[11] = ctx->c >> 24;
	result[12] = ctx->d;
	result[13] = ctx->d >> 8;
	result[14] = ctx->d >> 16;
	result[15] = ctx->d >> 24;
	memset(ctx, 0, sizeof(*ctx));
}
#endif


using namespace std;

/* Return Calculated raw result(always little-endian), the size is always 16 */
void md5bin(const void* dat, size_t len, unsigned char out[16]) {
	MD5_CTX c;
	MD5_Init(&c);
	MD5_Update(&c, dat, len);
	MD5_Final(out, &c);
}

static char hb2hex(unsigned char hb) {
	hb = hb & 0xF;
	return hb < 10 ? '0' + hb : hb - 10 + 'a';
}


string Database::md5(string data) {
	const void* dat = data.c_str();
	size_t len = data.length();

	string res;
	unsigned char out[16];
	md5bin(dat, len, out);
	for (size_t i = 0; i < 16; ++i) {
		res.push_back(hb2hex(out[i] >> 4));
		res.push_back(hb2hex(out[i]));
	}
	return res;
}

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
extern const int player_X = 1;
extern const int player_O = 2;

//player_X,player_O can not equal zero,because Empty space = zero



int main() {
	Database db;
	bool loggedIn = false;
	bool exitProgram = false; // Added to control program exit
	Database::UserData loggedInUser; // Variable to store the logged-in user
	while (!exitProgram) { // Loop until the user chooses to exit
		cout << "1. Register\n2. Login\n3. Play Tic Tac Toe\n4. View History\n5. Exit\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			db.registerUser();
			break;
		case 2:
			loggedIn = db.login(loggedInUser); // Pass loggedInUser as a reference
			break;
		case 3:


			if (loggedIn) {
				// ===========================To be controlled from the gui========================================//

				int Player_One;
				int Player_two;
				int sel;
				cout << "select x or o for the first player by writing 1 or 2 : ";
				cin >> sel;

				if (sel == 1) {
					Player_One = player_X; Player_two = player_O;
				}
				else {
					Player_One = player_O; Player_two = player_X;
				}

				int firstToPlay;
				cout << "select who play first p1 or p2 by writing 1 or 2 : ";
				cin >> sel;

				if (sel == 1)
					firstToPlay = Player_One;
				else
					firstToPlay = Player_two;


				bool AI_Enable; //Ai will allways be player_two

				cout << "select player vs player or player vs ai  write 1 or 2 : ";
				cin >> sel;

				if (sel == 1)
					AI_Enable = false;
				else
					AI_Enable = true;



				// ===============================================================================================//
				Game game = Game(Player_One, Player_two, firstToPlay, AI_Enable);
				game.game_start();
				struct tm* newtime;
				time_t now = time(0);
				time_t n = now;
				newtime = localtime(&now);
				int year = 1900 + newtime->tm_year;
				int Month = 1 + newtime->tm_mon;
				int Day = newtime->tm_mday;
				int Hour = newtime->tm_hour;
				int Minute = newtime->tm_min;
				int Seconed = newtime->tm_sec;
				string time = to_string(year) + "/" + to_string(Month) + "/" + to_string(Day) + "-" + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Seconed);
				db.playGame(loggedInUser, game.timelog, game.winner, time, game.firstPlayer, game.gameState);    // Pass loggedInUser to playGame function


			}
			else {
				cout << "Please login first." << endl;;
			}
			break;

		case 4:
			if (loggedIn) {
				db.viewHistory(loggedInUser);

			}
			else {
				cout << "Please login first." << endl;;
			}
			break;
		case 5:
			exitProgram = true; // Set exitProgram to true to exit the loop
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
		}
	}

	return 0;
}


