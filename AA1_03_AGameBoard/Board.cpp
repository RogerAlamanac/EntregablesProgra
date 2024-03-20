#include <iostream>
#include "Board.h"
Squares board[NUM_ROWS][NUM_COLUMNS];

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

bool checkMovement(Player player, Movement move) {
    int newRow = player.row, newColumn = player.column;
    if (move == Movement::UP) newRow--;
    else if (move == Movement::DOWN) newRow++;
    else if (move == Movement::LEFT) newColumn--;
    else if (move == Movement::RIGHT) newColumn++;
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

void setPos(Player& player, Movement& move) {
    if (move == Movement::UP) player.row--;
    else if (move == Movement::DOWN) player.row++;
    else if (move == Movement::LEFT) player.column--;
    else if(move == Movement::RIGHT) player.column++;
}

void movePlayer(Player& player, Movement move) {
    board[player.row][player.column].player = false;
    setPos(player, move);
    if (existsCoins(player)) addScore(player);
    board[player.row][player.column].coin = false;
    board[player.row][player.column].player = true;
}

bool gameOver() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (board[i][j].coin) return true;
        }
    }
    return false;
}

bool setMovement(char movement, Movement& move) {
    if (movement == 'w' || movement == UP_ARROW) move = Movement::UP;
    else if(movement == 's' || movement == DOWN_ARROW)move = Movement::DOWN;
    else if (movement == 'd' || movement == RIGHT_ARROW) move = Movement::RIGHT;
    else if (movement == 'a' || movement == LEFT_ARROW) move = Movement::LEFT;
    else return false;
    return true;
}