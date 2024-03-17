#include <iostream>
#include "Board.h"

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
    if ((player.move == Movement::UP && player.row == 0) || (player.move == Movement::DOWN && player.row == NUM_ROWS - 1)
        || (player.move == Movement::LEFT && player.column == 0) || (player.move == Movement::RIGHT && player.column == NUM_COLUMNS - 1)) return false;
    else if ((player.move == Movement::UP && board[player.row--][player.column].rock) || (player.move == Movement::DOWN && board[player.row++][player.column].rock)
        || (player.move == Movement::LEFT && board[player.row][player.column--].rock) || (player.move == Movement::RIGHT && board[player.row][player.column++].rock)) return false;
    return true;
}

bool existsCoins(Player player) {
    if ((player.move == Movement::UP && board[player.row--][player.column].coin) || (player.move == Movement::DOWN && board[player.row++][player.column].coin)
        || (player.move == Movement::LEFT && board[player.row][player.column--].coin) || (player.move == Movement::RIGHT && board[player.row][player.column++].coin)) return true;
    return false;
}

void printBoard() {
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

void movePlayer(Player& player) {
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

bool gameOver() {
    int coins;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (board[i][j].coin) return true;
        }
    }
    return false;
}

bool charToEnum(char& move, Player player) {
    switch (move) {
    case 'w':
        player.move = Movement::UP;
        return true
        break;
    case 's':
        player.move = Movement::DOWN;
        return true
        break;
    case 'a':
        player.move = Movement::LEFT;
        return true
        break;
    case 'd':
        player.move = Movement::RIGHT;
        return true
        break;
    }
    return false;
}