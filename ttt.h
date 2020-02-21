#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define __CLS_ system("cls")
#define __PLAY_GAME_ 1
#define __EXIT_ 2
#define __SIZE_ 3
#define __RAND_MAX_ __SIZE_ * __SIZE_

int display_menu();

void game_loop();

int is_winner(char board[][__SIZE_], char *winner);

void display_board(char board[][__SIZE_]);

int player_choice(char board[][__SIZE_]);

int computer_choice(char board[][__SIZE_]);