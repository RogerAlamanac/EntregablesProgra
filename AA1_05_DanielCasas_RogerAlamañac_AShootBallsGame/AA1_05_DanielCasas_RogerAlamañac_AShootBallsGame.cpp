#include <iostream>
#include <windows.h>
#include <ctime>
#include "Player.h"

int main()
{
    srand(time(NULL));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);       //2 Verd, 3 Blau fluix, 4 Vermell, 5 Lila, 6 Taronja
    std::cout << "Hello World!\n";
}
