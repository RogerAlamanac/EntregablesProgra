#include <iostream>
#include <windows.h>
#include <ctime>
#include "Panel.h"

const int FPS = 60;

int main(){
    srand(time(NULL));
    std::cout << "To move press 'a' or 'd'. To shoot press 'j'" << std::endl << std::endl;
    system("pause");
    std::string name;
    std::cout << "ENTER YOUR NAME:  ";
    std::cin >> name;
    Player player;
    Panel panel;
    panel.init();
    player.init(name, panel.size / 2);
    while (!gameOver) {
        system("cls");
        panel.printPanel(player);
        panel.printPlayer(player);
        playerMovement(player, panel);
        //FRAME CONTROL
        Sleep(1000 / FPS);
    }
}
