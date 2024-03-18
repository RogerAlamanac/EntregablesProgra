#include <iostream>
#include "Board.h"
#include <conio.h>      //Para que el usuario no tenga que presionar el espacio constantemente como pasaria con el cin

int main() {
    srand(time(NULL));
    Player player;
    char movement;
    initializeBoard(player);
    while (gameOver()) {
        system("cls");
        printBoard();
        std::cout << std::endl << "Score: " << player.score << std::endl;
        movement = _getch();
        if (charToEnum(movement, player) && checkMovement(player)) {
            movePlayer(player);
        }
    }
    system("cls");
    std::cout << "GAME OVER" << std::endl;
    std::cout << "Final punctuation: " << player.score++ << std::endl;
    return 0;
}
