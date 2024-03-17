#include <iostream>
#include <ctime>
#include "Board.h"

void main() {
    srand(time(NULL));
    Player player;
    char movement;
    initializeBoard(player);
    while (!gameOver()) {
        system("cls");
        printBoard();
        std::cin >> movement;
        if (charToEnum(movement, player)) {
            if (checkMovement(player)) {

            }
        }
        else {
            std::cout << "Not valid comand" << std::endl;
        }
        system("pause");
    }
}