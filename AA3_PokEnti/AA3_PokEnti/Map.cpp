#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Windows.h"
#include <conio.h>

Map::Map() {
	//GetMapData();

}

void Map::GetMapData(){
    std::string linea;
    std::ifstream myFile("config.txt");

    if (myFile.is_open()) {
        // Leer dimensiones del mapa
        getline(myFile, linea);
        std::string dimensiones;
        getline(myFile, dimensiones, ';');
        int ancho, alto;
        myFile >> ancho;
        myFile.ignore(); // Ignorar el ';' entre los valores
        myFile >> alto;

        std::cout << "Dimensiones del mapa: " << ancho << "x" << alto << std::endl;

        // Leer información de Pueblo Paleta
        getline(myFile, linea);
        myFile >> enemiesPuebloPaleta >> NUM_ROWS >> NUM_COLS;

        std::cout << "Pueblo Paleta: Enemigos - " << enemiesPuebloPaleta
            << ", Filas - " << NUM_ROWS
            << ", Columnas - " << NUM_COLS << std::endl;
        myFile.close();
    }
    else {
        std::cout << "No se pudede abrir el myFile .txt" << std::endl;
    }
}

void Map::PrintMap() {
    const int VIEW = 7;
	if (player.position.y <= VIEW / 2) {
		if (player.position.x <= VIEW / 2) {
			for (int rows = 0; rows < VIEW; rows++) {
				for (int cols = 0; cols < VIEW; cols++) {
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					//if(muro)
					else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
		else if (player.position.x >= (NUM_ROWS - 1) - VIEW / 2) {
			for (int rows = 0; rows < VIEW; rows++) {
				for (int cols = (NUM_COLS - 1) - VIEW; cols < NUM_COLS; cols++) {
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					//if(muro)
					else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
		else {
			for (int rows = 0; rows < VIEW; rows++) {
				for (int cols = player.position.x - VIEW / 2; cols < player.position.x + VIEW / 2; cols++) {
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					//if(muro)
				}
				std::cout << std::endl;
			}
		}
	}
	else if (player.position.y >= (NUM_COLS - 1) - VIEW / 2) {
		if (player.position.x <= VIEW / 2) {
			for (int rows = (NUM_COLS - 1) - VIEW; rows < NUM_COLS; rows++) {
				for (int cols = 0; cols < VIEW; cols++) {
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					//if(muro)
					else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
		else if (player.position.x >= (NUM_ROWS - 1) - VIEW / 2) {
			for (int rows = (NUM_COLS - 1) - VIEW; rows < NUM_COLS; rows++) {
				for (int cols = (NUM_COLS - 1) - VIEW; cols < NUM_COLS; cols++) {
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					//if(muro)
					else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
		else {
			for (int rows = (NUM_COLS - 1) - VIEW; rows < NUM_COLS; rows++) {
				for (int cols = player.position.x - VIEW / 2; cols < player.position.x + VIEW / 2; cols++) {
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					//if(muro)
					else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
	}
	else {
		for (int rows = player.position.y - VIEW / 2; rows < player.position.y + VIEW / 2; rows++) {
			for (int cols = player.position.x - VIEW / 2; cols < player.position.x + VIEW / 2; cols++) {
				if (player.position.y == rows && player.position.x == cols) {
					if (player.movement == Movement::UP) std::cout << '^';
					else if (player.movement == Movement::DOWN) std::cout << 'v';
					else if (player.movement == Movement::RIGHT) std::cout << '>';
					else if (player.movement == Movement::LEFT) std::cout << '<';
				}
				//if(muro)
				else {
					std::cout << ' ';
				}
			}
			std::cout << std::endl;
		}
	}
}

void Map::PlayerMovement() {
	UpdateScene();
	char Tecla = _getch();
	if (GetAsyncKeyState(VK_UP)) player.movement = Movement::UP;
	else if (GetAsyncKeyState(VK_DOWN)) player.movement = Movement::DOWN;
	else if (GetAsyncKeyState(VK_LEFT))	player.movement = Movement::LEFT;
	else if (GetAsyncKeyState(VK_RIGHT)) player.movement = Movement::RIGHT;
	else player.movement = Movement::INVALID;

	switch (player.movement) {
	case Movement::UP:
		if (scene == Scene::PUEBLO_PALETA || scene == Scene::BOSQUE) {
			if (player.position.x != 0) player.position.x--;
		}
		else if (scene == Scene::CUEVA_CELESTE) player.position.x--;
		else if (scene == Scene::LIGA_POKENTI) {
			if (player.position.x > NUM_ROWS / 2) player.position.x--;
		}
		break;

	case Movement::DOWN:
		if (scene == Scene::PUEBLO_PALETA) {
			if (player.position.x != NUM_ROWS / 2) player.position.x++;
		}
		else if (scene == Scene::BOSQUE) player.position.x++;
		else if (scene == Scene::CUEVA_CELESTE || scene == Scene::LIGA_POKENTI) {
			if (player.position.x != NUM_ROWS - 1) player.position.x++;
		}
		break;

	case Movement::RIGHT:
		if (scene == Scene::PUEBLO_PALETA || scene == Scene::LIGA_POKENTI) player.position.y++;

		else if (scene == Scene::CUEVA_CELESTE || scene == Scene::BOSQUE) {
			if (player.position.y != NUM_COLS) player.position.y++;
		}

		break;

	case Movement::LEFT:
		if (scene == Scene::PUEBLO_PALETA || scene == Scene::LIGA_POKENTI) {
			if (player.position.y != 0) player.position.y--;
		}
		else if (scene == Scene::BOSQUE || scene == Scene::CUEVA_CELESTE) player.position.y--;
		break;
	default:
		break;
	}

}

void Map::UpdateScene() {
	if (player.position.x < NUM_ROWS / 2 && player.position.y < NUM_COLS / 2) scene = Scene::PUEBLO_PALETA;
	else if (player.position.x > NUM_ROWS / 2 && player.position.y < NUM_COLS / 2) scene = Scene::BOSQUE;
	else if (player.position.x < NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) scene = Scene::CUEVA_CELESTE;
	else scene = Scene::LIGA_POKENTI;
}