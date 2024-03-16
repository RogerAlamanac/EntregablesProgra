#include <iostream>
#include <ctime>
#include "Board.h"

void main() {
    srand(time(NULL));
    Squares board[NUM_ROWS][NUM_COLUMNS];
    Player player;
    char movement;
    initializeBoard(board, player);
    while (!gameOver(board)) {
        system("cls");
        printBoard(board);
        if (checkMovement) {

        }
    }
}