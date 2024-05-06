#include <iostream>
#include "Map.h"
#include "Windows.h"
#include <string>
const int FPS = 60;

int main() {
	srand(time(NULL));
	Map map;
	std::string scene;
	while (true) {
		system("cls");
		map.PrintMap();
		map.PlayerMovement();
		Sleep(1000 / FPS);
	}
}