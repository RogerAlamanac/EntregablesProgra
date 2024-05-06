#include <iostream>
#include "Map.h"
#include "Windows.h"
#include <WinUser.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
	Map map;
	//map.PrintMap();
	std::string scene;
	while (true) {
		// Simular algunos movimientos del jugador
		map.PrintMap();        // Imprime el mapa
		map.PlayerMovement();  // Se mueve el jugador
		if (map.player.scene == Scene::PUEBLO_PALETA) scene = "PUEBLO_PALETA";
		else if (map.player.scene == Scene::BOSQUE) scene = "BOSQUE";
		else if (map.player.scene == Scene::CUEVA_CELESTE) scene = "CUEVA_CELESTE";
		else scene = "LIGA_POKENTI";
		std::cout << scene << std::endl;
	}
}

/*int main() {
	//CONFIGURATION
	std::cout << "CONFIGURATION" << std::endl;
	//Setup initial paramketers of the game (weather, player name, fps)
	const int FPS = 15;
	int frameCount = 0;
	bool userPressedUpKey = false;

	// GAME LOOP
	while (true) {
		// INPUT
		if (GetAsyncKeyState(VK_ESCAPE)) {//Si apretes esc surt del bucle
			std::cout << "EXITING GAME LOOP" << std::endl;
			break;
		}
		if (GetAsyncKeyState(VK_UP)) {
			userPressedUpKey = true;
		}
		//Update
		if (frameCount >= 9 || userPressedUpKey) {
			frameCount = 0;
		}

		if (userPressedUpKey) {
			system("cls");
			userPressedUpKey = false;
		}
		//RENDER
		std::cout << ++frameCount<< std::endl;


		//FRAME CONTROL
		Sleep(1000 / FPS); // 1000 milisegons, 1 segon en total
	}
}*/