#include <iostream>
#include "Board.h"
#include <conio.h>      //Para que el usuario no tenga que presionar el enter constantemente como pasaria con el cin. Para esto usaremos _getch()

int main() {
    srand(time(NULL));
    Player player;
    Movement move = Movement::INVALID;
    char movement;
    initializeBoard(player);
    while (gameOver()) {
        system("cls");
        printBoard();
        std::cout << std::endl << "Score: " << player.score << std::endl;
        movement = _getch();
        if (setMovement(movement, move) && checkMovement(player, move)) {
            movePlayer(player, move);
        }
    }
    system("cls");
    std::cout << "GAME OVER" << std::endl;
    std::cout << "Final punctuation: " << player.score++ << std::endl;
    return 0;
}