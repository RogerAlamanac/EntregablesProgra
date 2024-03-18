#include <iostream>
#include "Board.h"

void main() {
    Player player;
    char movement;
    initializeBoard(player);
    while (!gameOver()) {
        system("cls");
        printBoard();
        std::cin >> movement;
        if (charToEnum(movement, player) && checkMovement(player)) {
            if (existsCoins(player)) addScore(player);
            movePlayer(player);
        }
        system("pause");
    }
    std::cout << "GAME OVER" << std::endl;
}