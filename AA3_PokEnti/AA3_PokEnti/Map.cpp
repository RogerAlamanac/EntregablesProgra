#include "Map.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>

Map::Map() {
	pokemons = new Pokemon[totalPokemons];
	map = new Square *[NUM_ROWS];
	for (int i = 0; i < NUM_ROWS; i++) {
		map[i] = new Square[NUM_COLS];
	}
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {								
			if (i == player.position.y && j == player.position.x) map[i][j] = Square::PLAYER;
			else if (i == NUM_ROWS / 2 || j == NUM_COLS / 2 || i == 0 || j == 0 || i == NUM_ROWS - 1 || j == NUM_COLS - 1) map[i][j] = Square::WALL;
			else map[i][j] = Square::NOTHING;
		}
	}
	InitializePokemons();
}
//Vida Nivel 1 = 10->39
//Vida Nivel 2 = 40->69
//Vida Nivel 3 = 70->99
//Vida Nivel 4 = 100->129
//Vida Nivel 5 = 130->159 
//Vida Nivel 6 = 160->180
const int NUM_LEVEL_1 = 10;
const int NUM_LEVEL_2 = 8;		
const int NUM_LEVEL_3 = 6;
const int NUM_LEVEL_4 = 4;
const int NUM_LEVEL_5 = 3;
const int NUM_LEVEL_6 = 3;

void Map::InitializePokemons() {
	for (int i = 0; i < totalPokemons; i++) {
		if (i < NUM_LEVEL_1) {
			pokemons[i].strengthLevel = 1;
			pokemons[i].lifes = rand() % (39 - 10 + 1) + 10;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2) {
			pokemons[i].strengthLevel = 2;
			pokemons[i].lifes = rand() % (69 - 40 + 1) + 40;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3) {
			pokemons[i].strengthLevel = 3;
			pokemons[i].lifes = rand() % (99 - 70 + 1) + 70;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3 + NUM_LEVEL_4) {
			pokemons[i].strengthLevel = 4;
			pokemons[i].lifes = rand() % (129 - 100 + 1) + 100;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3 + NUM_LEVEL_4 + NUM_LEVEL_5) {
			pokemons[i].strengthLevel = 5;
			pokemons[i].lifes = rand() % (159 - 130 + 1) + 130;
		}
		else {
			pokemons[i].strengthLevel = 6;
			pokemons[i].lifes = rand() % (180 - 160 + 1) + 160;
		}
		int x;
		int y;
		do {
			if (i < pokemonsPuebloPaleta) {
				x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
				y = rand() % ((NUM_COLS / 2 - 1) - 2 + 1) + 1;
			}
			else if(i < pokemonsForest) {
				x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
				y = rand() % ((NUM_COLS - 1) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
			}
			else {
				x = rand() % ((NUM_ROWS - 2) - (NUM_ROWS / 2 + 1) + 1) + (NUM_ROWS / 2 + 1);
				y = rand() % ((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
			}
		} while (map[x][y] != Square::NOTHING);
		pokemons[i].position.x = x;
		pokemons[i].position.y = y;
		map[x][y] = Square::POKEMON;
	}
}

void Map::PrintMap() {
	system("cls");
    const int VIEW = 7;
	/*if (player.position.y <= VIEW / 2) {
		if (player.position.x <= VIEW / 2) {
			for (int rows = 0; rows < VIEW; rows++) {
				for (int cols = 0; cols < VIEW; cols++) {
					if (map[rows][cols] == Square::WALL) std::cout << 'X';
					else if (map[rows][cols] == Square::POKEMON) std::cout << 'P';
					else if (map[rows][cols] == Square::PLAYER) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					else {																																				
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}														
		}
		else if (player.position.x >= (file.NUM_ROWS - 1) - VIEW / 2) {
			for (int rows = 0; rows < VIEW; rows++) {
				for (int cols = (file.NUM_COLS - 1) - VIEW; cols < file.NUM_COLS; cols++) {
					if (rows = file.NUM_ROWS / 2) std::cout << 'X';
					else if (cols = file.NUM_COLS / 2) std::cout << 'X';
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
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
					if (rows = file.NUM_ROWS / 2) std::cout << 'X';
					else if (cols = file.NUM_COLS / 2) std::cout << 'X';
					else if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					else {
						std::cout << " ";
					}
				}
				std::cout << std::endl;
			}
		}
	}
	else if (player.position.y >= (file.NUM_COLS - 1) - VIEW / 2) {
		if (player.position.x <= VIEW / 2) {
			for (int rows = (file.NUM_COLS - 1) - VIEW; rows < file.NUM_COLS; rows++) {
				for (int cols = 0; cols < VIEW; cols++) {
					if (rows = file.NUM_ROWS / 2) std::cout << 'X';
					else if (cols = file.NUM_COLS / 2) std::cout << 'X';
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
		else if (player.position.x >= (file.NUM_ROWS - 1) - VIEW / 2) {
			for (int rows = (file.NUM_COLS - 1) - VIEW; rows < file.NUM_COLS; rows++) {
				for (int cols = (file.NUM_COLS - 1) - VIEW; cols < file.NUM_COLS; cols++) {
					if (rows = file.NUM_ROWS / 2) std::cout << 'X';
					else if (cols = file.NUM_COLS / 2) std::cout << 'X';
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
					else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
		else {
			for (int rows = (file.NUM_COLS - 1) - VIEW; rows < file.NUM_COLS; rows++) {
				for (int cols = player.position.x - VIEW / 2; cols < player.position.x + VIEW / 2; cols++) {
					if (rows = file.NUM_ROWS / 2) std::cout << 'X';
					else if (cols = file.NUM_COLS / 2) std::cout << 'X';
					if (player.position.y == rows && player.position.x == cols) {
						if (player.movement == Movement::UP) std::cout << '^';
						else if (player.movement == Movement::DOWN) std::cout << 'v';
						else if (player.movement == Movement::RIGHT) std::cout << '>';
						else if (player.movement == Movement::LEFT) std::cout << '<';
					}
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
				if (rows = file.NUM_ROWS / 2) std::cout << 'X';
				else if (cols = file.NUM_COLS / 2) std::cout << 'X';
				if (player.position.y == rows && player.position.x == cols) {
					if (player.movement == Movement::UP) std::cout << '^';
					else if (player.movement == Movement::DOWN) std::cout << 'v';
					else if (player.movement == Movement::RIGHT) std::cout << '>';
					else if (player.movement == Movement::LEFT) std::cout << '<';
				}
				else {
					std::cout << ' ';
				}
			}
			std::cout << std::endl;
		}
	}*/
	for (int rows = 0; rows < NUM_ROWS; rows++) {
		for (int cols = 0; cols < NUM_COLS; cols++) {
			if (map[rows][cols] == Square::WALL) std::cout << 'X';
			else if (map[rows][cols] == Square::PLAYER) {
				if (player.movement == Movement::UP) {
					player.lastMovement = Movement::UP;
					std::cout << '^';
				}
				else if (player.movement == Movement::DOWN) {
					player.lastMovement = Movement::DOWN;
					std::cout << 'v';
				}
				else if (player.movement == Movement::RIGHT) {
					player.lastMovement = Movement::RIGHT;
					std::cout << '>';
				}
				else if (player.movement == Movement::LEFT) {
					player.lastMovement = Movement::LEFT;
					std::cout << '<';
				}
				else {
					if (player.lastMovement == Movement::UP) std::cout << '^';
					else if (player.lastMovement == Movement::DOWN) std::cout << 'v';
					else if (player.lastMovement == Movement::RIGHT) std::cout << '>';
					else if (player.lastMovement == Movement::LEFT) std::cout << '<';
				}
			}
			else if (map[rows][cols] == Square::POKEMON) std::cout << "P";
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Captured Pokemons: " << player.numCapturedPokemons << std::endl;
}

int Map::FindPokemonPosition(int x, int y) {
	for (int i = 0; i < totalPokemons; i++) {
		if (pokemons[i].position.x == x && pokemons[i].position.y == y) return i;
	}
}

void Map::FightPokemon(int x, int y){
	std::cout << std::endl << "You have a Pokemon nearby, do you want to capture it? Press 1 for YES press 0 for no" << std::endl;
	int choice;
	bool correctChoice = false;
	do {
		std::cin >> choice;
		if (choice == 1) {
			system("cls");
			pokemons[FindPokemonPosition(x, y)].CapturePokemon(player);
			correctChoice = true;
		}
		else if (choice == 0) {
			std::cout << "Pokemon escaped" << std::endl;
			correctChoice = true;
		}
		else {
			std::cout << "WRONG COMMAND!" << std::endl;
		}
	} while (!correctChoice);

}

void Map::PlayerMovement() {
	UpdateScene();
	system("pause");
	if (GetAsyncKeyState(VK_UP)) player.movement = Movement::UP;
	else if (GetAsyncKeyState(VK_DOWN)) player.movement = Movement::DOWN;
	else if (GetAsyncKeyState(VK_LEFT))	player.movement = Movement::LEFT;
	else if (GetAsyncKeyState(VK_RIGHT)) player.movement = Movement::RIGHT;
	else player.movement = Movement::INVALID;
	switch (player.movement) {
	case Movement::UP:
		if (player.scene == Scene::PUEBLO_PALETA || player.scene == Scene::BOSQUE) {
			if (player.position.x > 1) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.x--;
			}
		}
		else if (player.scene == Scene::CUEVA_CELESTE) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.x--;
		}
		else if (player.scene == Scene::LIGA_POKENTI) {
			if (player.position.x > NUM_ROWS / 2 + 1) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.x--;
			}
		}
		if (map[player.position.x][player.position.y] == Square::POKEMON) FightPokemon(player.position.x, player.position.y);
		break;

	case Movement::DOWN:
		if (player.scene == Scene::PUEBLO_PALETA) {
			if (player.position.x < NUM_ROWS / 2 - 1) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.x++;
			}
		}
		else if (player.scene == Scene::BOSQUE) {
			if (player.numCapturedPokemons >= pokemonsToUnlockCave) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.x++;
			}
			else {
				if (player.position.x < NUM_ROWS / 2 - 1) {
					map[player.position.x][player.position.y] = Square::NOTHING;
					player.position.x++;
				}
			}
		}
		else if (player.scene == Scene::CUEVA_CELESTE || player.scene == Scene::LIGA_POKENTI) {
			if (player.position.x < NUM_ROWS - 2) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.x++;
			}
		}
		if (map[player.position.x][player.position.y] == Square::POKEMON) FightPokemon(player.position.x, player.position.y);
		break;

	case Movement::RIGHT:
		if (player.scene == Scene::PUEBLO_PALETA) {
			if (player.numCapturedPokemons >= pokemonsToUnlockForest) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y++;
			}
			else {
				if (player.position.y < NUM_COLS / 2 - 1) {
					map[player.position.x][player.position.y] = Square::NOTHING;
					player.position.y++;
				}
			}
		}
		else if (player.scene == Scene::CUEVA_CELESTE || player.scene == Scene::BOSQUE) {
			if (player.position.y < NUM_COLS - 2) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y++;
			}
		}
		else if (player.scene == Scene::LIGA_POKENTI) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.y++;
		}
		if (map[player.position.x][player.position.y] == Square::POKEMON) FightPokemon(player.position.x, player.position.y);
		break;

	case Movement::LEFT:
		if (player.scene == Scene::PUEBLO_PALETA || player.scene == Scene::LIGA_POKENTI) {
			if (player.position.y > 1) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y--;
			}
		}
		else if (player.scene == Scene::BOSQUE) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.y--;
		}
		else if (player.scene == Scene::CUEVA_CELESTE) {
			if (player.numCapturedPokemons >= pokemonsToUnlockPokenti) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y--;
			}
			else {
				if (player.position.y > NUM_COLS / 2 + 1) {
					map[player.position.x][player.position.y] = Square::NOTHING;
					player.position.y--;
				}
			}
		}
		if (map[player.position.x][player.position.y] == Square::POKEMON) FightPokemon(player.position.x, player.position.y);
		break;
	default:
		break;
	}
	map[player.position.x][player.position.y] = Square::PLAYER;
}

void Map::UpdateScene(){
	if (player.position.x < NUM_ROWS / 2 && player.position.y < NUM_COLS / 2) player.scene = Scene::PUEBLO_PALETA;
	else if (player.position.x < NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) player.scene = Scene::BOSQUE;
	else if (player.position.x > NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) player.scene = Scene::CUEVA_CELESTE;
	else if (player.position.x < NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) player.scene = Scene::LIGA_POKENTI;
}