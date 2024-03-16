#include <iostream>
#include "Board.h"

void initializeBoard(Squares board[NUM_ROWS][NUM_COLUMNS], Player& player) {
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

bool checkMovement(Player player, Squares board[NUM_ROWS][NUM_COLUMNS]) {
    if ((player.move == Movement::UP && player.row == 0) || (player.move == Movement::DOWN && player.row == NUM_ROWS - 1)
        || (player.move == Movement::LEFT && player.column == 0) || (player.move == Movement::RIGHT && player.column == NUM_COLUMNS - 1)) return false;
    else if ((player.move == Movement::UP && board[player.row--][player.column].rock) || (player.move == Movement::DOWN && board[player.row++][player.column].rock)
        || (player.move == Movement::LEFT && board[player.row][player.column--].rock) || (player.move == Movement::RIGHT && board[player.row][player.column++].rock)) return false;
    return true;
}

bool existsCoins(Player player, Squares board[NUM_ROWS][NUM_COLUMNS]) {
    if ((player.move == Movement::UP && board[player.row--][player.column].coin) || (player.move == Movement::DOWN && board[player.row++][player.column].coin)
        || (player.move == Movement::LEFT && board[player.row][player.column--].coin) || (player.move == Movement::RIGHT && board[player.row][player.column++].coin)) return true;
    return false;
}

void printBoard(Squares board[NUM_ROWS][NUM_COLUMNS]) {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int column = 0; column < NUM_COLUMNS; column++) {
            if (board[row][column].coin) board[row][column].draw = 184;
            else if (board[row][column].rock) board[row][column].draw = 254;
            else if (board[row][column].player) board[row][column].draw = 197;
        }
    }
}

void setPos(Player& player) {
    if (player.move == Movement::UP) player.row--;
    else if (player.move == Movement::DOWN) player.row++;
    else if (player.move == Movement::LEFT) player.column--;
    else if(player.move == Movement::RIGHT) player.column++;
}

void movePlayer(Player& player, Squares board[NUM_ROWS][NUM_COLUMNS]) {
    if (player.move == Movement::UP) {
        board[player.row][player.column].player = false;
        board[player.row--][player.column].player = true;
        setPos(player);
    }
    else if (player.move == Movement::DOWN) {
        board[player.row][player.column].player = false;
        board[player.row++][player.column].player = true;
        setPos(player);
    }
    else if (player.move == Movement::LEFT) {
        board[player.row][player.column].player = false;
        board[player.row][player.column--].player = true;
        setPos(player);
    }
    else if (player.move == Movement::RIGHT) {
        board[player.row][player.column].player = false;
        board[player.row][player.column++].player = true;
        setPos(player);
    }
}

bool gameOver(Squares board[NUM_ROWS][NUM_COLUMNS]) {
    int coins;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (board[i][j].coin) return true;
        }
    }
    return false;
}