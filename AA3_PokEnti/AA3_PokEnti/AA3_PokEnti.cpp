#include <iostream>
#include "Map.h"
#include "PrintPokemons.h"
#include "Windows.h"
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
const int FPS = 60;

int main() {
	srand(time(NULL));
	Map map;
	std::string scene;
	PrintLogo();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	int selected = 0;
	int decision = 0;
	while (true) {
		system("cls");
		PrintMenu(selected);
		decision = _getch();
		if (GetAsyncKeyState(VK_UP) < 0) selected = 0;
		else if(GetAsyncKeyState(VK_DOWN) < 0) selected = 1;
		else if (GetAsyncKeyState(VK_SPACE)) break;
	}
	switch (selected) {
	case 0:
		while (map.player.GetScene() != Scene::LIGA_POKENTI) {
			system("cls");
			map.PrintMap();
			map.PlayerMovement();
			Sleep(1000 / FPS);
		}
		if(map.player.GetCapturedMewtwo()){
			PrintPikachu();
			std::cout << "YOU WIN =)" << std::endl;
		} 
		else{
			PrintMewtwo();
			std::cout << "YOU LOSE =(" << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(5));
		exit(0);
		break;
	case 1:
		exit(0);
		break;
	}
}