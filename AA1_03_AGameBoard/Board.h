#pragma once
#include "Player.h"
#define NUM_ROWS 12
#define NUM_COLUMNS 12

#define MIN_ROCKS 1
#define MAX_ROCKS (static_cast<int>((20.0 / 100) * NUM_ROWS * NUM_COLUMNS))  // Calculamos el número máximo de rocas como el 20% de las casillas
#define NUM_ROCKS (rand() % (MAX_ROCKS - MIN_ROCKS + 1) + MIN_ROCKS)         // Generamos un número aleatorio entre el mínimo y máximo de rocas
#define MIN_COINS 1
#define MAX_COINS (static_cast<int>((30.0 / 100) * NUM_ROWS * NUM_COLUMNS))  // Calculamos el número máximo de monedas como el 30% de las casillas
#define NUM_COINS (rand() % (MAX_COINS - MIN_COINS + 1) + MIN_COINS)         // Generamos un número aleatorio entre el mínimo y máximo de monedas

#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define LEFT_ARROW 75

struct Squares {
    char draw = ' ';
    bool rock = false, coin = false, player = false;
};

void initializeBoard(Player& player);
bool checkMovement(Player player);
bool existsCoins(Player player);
void movePlayer(Player& player);
bool gameOver();
void printBoard();
void setPos(Player& player);
bool charToEnum(char move, Player& player);