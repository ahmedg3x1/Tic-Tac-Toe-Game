#include "entry_menu.h"
#include "ui_entry_menu.h"
#include "profile_menu.h"
#include "Database.h"


extern Database my_database;

entry_menu::entry_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::entry_menu)
{
    ui->setupUi(this);
}

entry_menu::~entry_menu()
{
    delete ui;
}

void entry_menu::on_profile_button_clicked()
{
    static profile_menu *my_profile_menu = new profile_menu();
    my_profile_menu->show();
}


void entry_menu::on_pvp_button_clicked()
{
    //should make game window and pass the Game class object as member to it
    /*Game new_game(player1_name,player2_name,player1_name,0);
      then in the game-window-class-constructor add parameter of type(Game)
      then make window of the game with input parameters(Game)


    */
    my_game_window = new game_window(this);
    hide();
    my_game_window->show();
}


void entry_menu::on_pvai_button_clicked()
{
    my_game_window = new game_window(this, true);
    hide();
    my_game_window->show();
}

