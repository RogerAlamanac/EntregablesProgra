#include <iostream>
#include <windows.h>
#include <ctime>
#include "Player.h"

int main()
{
    srand(time(NULL));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const char ball = static_cast<char> (254);
    SetConsoleTextAttribute(hConsole, 6);       //2 Verd, 3 Blau fluix, 4 Vermell, 5 Lila, 6 Taronja
    std::cout << ball << " ";

    SetConsoleTextAttribute(hConsole, 7);       //2 Verd, 3 Blau fluix, 4 Vermell, 5 Lila, 6 Taronja
    std::cout << ball << "\n\n\n\n\n\n\n\n\n\n\n\n";
}
