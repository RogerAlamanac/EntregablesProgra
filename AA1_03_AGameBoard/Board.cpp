#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include "Board.h"
Squares board[NUM_ROWS][NUM_COLUMNS];
Player player;

void initializeBoard(Player& player) {
    int row, column;
    for (int coins = 0; coins < NUM_COINS;) {
        row = rand() % (NUM_ROWS);
        column = rand() % (NUM_COLUMNS);
        if (!board[row][column].coin) {                                    //Place coins in a random square of the board that has no coins
            board[row][column].coin = true;
            coins++;
        }
    }
    for (int rocks = 0; rocks < NUM_ROCKS; ) {
        row = rand() % (NUM_ROWS);
        column = rand() % (NUM_COLUMNS);
        if (!board[row][column].rock && !board[row][column].coin) {        //Place rocks in a random square of the board that has no rocks or coins
            board[row][column].rock = true;
            rocks++;
        }
    }
    for (bool placePlayer = false; !placePlayer;) {
        row = rand() % (NUM_ROWS);
        column = rand() % (NUM_COLUMNS);
        if (!board[row][column].rock && !board[row][column].coin) {       //Place player in a random square of the board that has no rocks or coins
            player.row = row;
            player.column = column;
            board[row][column].player = true;
            placePlayer = true;
        }
    }
}

bool checkMovement(Player player) {
    int newRow = player.row, newColumn = player.column;
    if (player.move == Movement::UP) newRow--;
    else if (player.move == Movement::DOWN) newRow++;
    else if (player.move == Movement::LEFT) newColumn--;
    else if (player.move == Movement::RIGHT) newColumn++;
    if (newRow < 0 || newRow >= NUM_ROWS || newColumn < 0 || newColumn >=NUM_COLUMNS || board[newRow][newColumn].rock) return false;
    return true; 
}

bool existsCoins(Player player) {
    if (board[player.row][player.column].coin) return true;
    return false;
}

void printBoard() {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int column = 0; column < NUM_COLUMNS; column++) {
            if (board[row][column].coin) board[row][column].draw = 36;
            else if (board[row][column].rock) board[row][column].draw = 254;    //Numeros en la tabla ASCII
            else if (board[row][column].player) board[row][column].draw = 197;
            else board[row][column].draw = ' ';
            std::cout << '|' << board[row][column].draw << '|';
        }
        std::cout << std::endl;
    }
}

void setPos(Player& player) {
    if (player.move == Movement::UP) player.row--;
    else if (player.move == Movement::DOWN) player.row++;
    else if (player.move == Movement::LEFT) player.column--;
    else if(player.move == Movement::RIGHT) player.column++;
}

void movePlayer(Player& player) {
    board[player.row][player.column].player = false;
    setPos(player);
    if (existsCoins(player)) addScore(player);
    board[player.row][player.column].coin = false;
    board[player.row][player.column].player = true;
}

bool gameOver() {
    int coins;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (board[i][j].coin) return true;
        }
    }
    return false;
}

bool setMovement(char move, Player& player) {
    if (move == 'w' || move == UP_ARROW) player.move = Movement::UP;
    else if(move == 's' || move == DOWN_ARROW)player.move = Movement::DOWN;
    else if (move == 'd' || move == RIGHT_ARROW)player.move = Movement::RIGHT;
    else if (move == 'a' || move == LEFT_ARROW)player.move = Movement::LEFT;
    else return false;
    return true;
}