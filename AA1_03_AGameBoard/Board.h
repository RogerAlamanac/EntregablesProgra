#pragma once
#include <windows.h>
#include <WinUser.h>
#include "Player.h"
#define NUM_ROWS 3
#define NUM_COLUMNS 3
#define MIN_ROCKS 1
#define MAX_ROCKS ((20/100) * NUM_ROWS * NUM_COLUMNS)       //Creamos un numero maximo de rocas, el 20% de las casillas
#define NUM_ROCKS rand() % (MAX_ROCKS - MIN_ROCKS + 1) + MIN_ROCKS  //Creamos un numero random, entre 1(minimo de rocas) i el 20% de las casillas, para decidir el numero de rocas que habra
#define MIN_COINS 1
#define MAX_COINS ((30/100) * NUM_ROWS * NUM_COLUMNS)   //Creamos un numero maximo de monedas, el 30% de las casillas
#define NUM_COINS rand() % (MAX_COINS - MIN_COINS + 1) + MIN_COINS  //Creamos un numero random, entre 1(minimo de monedas) i el 30% de las casillas, para decidir el numero de monedas que habrá

struct Squares {
    char draw = ' ';
    bool rock = false, coin = false, player = false;
};
Squares board[NUM_ROWS][NUM_COLUMNS];

void initializeBoard(Player& player);
bool checkMovement(Player player);
bool existsCoins(Player player);
void movePlayer(Player& player);
bool gameOver();
void printBoard();
void setPos(Player& player);
bool charToEnum(char move, Player& player);