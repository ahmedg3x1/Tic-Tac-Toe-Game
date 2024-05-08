#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Game.h"
#include "Database.h"
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

                if(sel == 1) {
                    Player_One = player_X; Player_two = player_O;
                } else {
                    Player_One = player_O; Player_two = player_X;
                }

                int firstToPlay;
                cout << "select who play first p1 or p2 by writing 1 or 2 : ";
                cin >> sel;

                if (sel == 1) 
                    firstToPlay =Player_One;
                else
                    firstToPlay = Player_two;
                

                bool AI_Enable; //Ai will allways be player_two

                cout <<"select player vs player or player vs ai  write 1 or 2 : ";        
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


