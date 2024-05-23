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
	UpdateMap();
	system("cls");
	std::cout << "Captured Pokemons: " << player.numCapturedPokemons << std::endl;
	player.PrintScene();
    const int VIEW = 14;
	int firstRow;
	int firstCol;
	int lastRow;
	int lastCol;
	if (player.position.x < VIEW / 2) {
		firstRow = 0;
		lastRow = VIEW;
	}
	else if (player.position.x > ((NUM_ROWS - 1) - VIEW)) {
		firstRow = NUM_ROWS - 1 - VIEW;
		lastRow = NUM_ROWS - 1;
	}
	else {
		firstRow = player.position.x - VIEW / 2;
		lastRow = player.position.x + VIEW / 2;
	}

	if (player.position.y < VIEW) {
		firstCol = 0;
		lastCol = VIEW * 2;
	}
	else if (player.position.y > ((NUM_COLS)-1 - VIEW)) {
		firstCol = NUM_COLS - 1 - VIEW * 2;
		lastCol = NUM_COLS - 1;
	}
	else {
		firstCol = player.position.y - VIEW;
		lastCol = player.position.y + VIEW;
	}

	for (int row = firstRow; row < lastRow; row++) {
		for (int col = firstCol; col < lastCol; col++) {
			if (map[row][col] == Square::WALL) std::cout << 'X';
			else if (map[row][col] == Square::PLAYER) {
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
			else if (map[row][col] == Square::POKEMON) std::cout << "P";
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

int Map::FindPokemonPosition(int x, int y) const {
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
	NewPokemon();
}

void Map::NewPokemon() {
	int position = 0;
	if (player.lastMovement == Movement::UP) position = FindPokemonPosition(player.position.x - 1, player.position.y);
	else if (player.lastMovement == Movement::DOWN) position = FindPokemonPosition(player.position.x + 1, player.position.y);
	else if (player.lastMovement == Movement::RIGHT) position = FindPokemonPosition(player.position.x, player.position.y + 1);
	else if (player.lastMovement == Movement::LEFT) position = FindPokemonPosition(player.position.x, player.position.y - 1);

	do {
		if (player.scene == Scene::PUEBLO_PALETA) {
			pokemons[position].position.x = rand() % (NUM_COLS / 2);
			pokemons[position].position.y = rand() % (NUM_ROWS / 2);
		}
		else if (player.scene == Scene::BOSQUE) {
			pokemons[position].position.x = rand() % (((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1));
			pokemons[position].position.y = rand() % (((NUM_ROWS / 2 - 1) - 2 + 1) + 2);
		}
		else if (player.scene == Scene::CUEVA_CELESTE) {
			pokemons[position].position.x = rand() % (((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1));
			pokemons[position].position.y = rand() % (((NUM_ROWS - 2) - (NUM_ROWS / 2 + 1) + 1) + (NUM_ROWS / 2 + 1));
		}
	} while (map[pokemons[position].position.x][pokemons[position].position.y] != Square::NOTHING);

	switch (pokemons[position].strengthLevel) {
	case 1:
		pokemons[position].lifes = rand() % (39 - 10 + 1) + 10;
		break;
	case 2:
		pokemons[position].lifes = rand() % (69 - 40 + 1) + 40;
		break;
	case 3:
		pokemons[position].lifes = rand() % (99 - 70 + 1) + 70;
		break;
	case 4:
		pokemons[position].lifes = rand() % (129 - 100 + 1) + 100;
		break;
	case 5:
		pokemons[position].lifes = rand() % (159 - 130 + 1) + 130;
		break;
	case 6:
		pokemons[position].lifes = rand() % (180 - 160 + 1) + 160;
		break;
	}
	map[pokemons[position].position.x][pokemons[position].position.y] = Square::POKEMON;
}

void Map::PlayerMovement() {
	UpdateScene();
	system("pause");
	if (GetAsyncKeyState(VK_UP)) player.movement = Movement::UP;
	else if (GetAsyncKeyState(VK_DOWN)) player.movement = Movement::DOWN;
	else if (GetAsyncKeyState(VK_LEFT))	player.movement = Movement::LEFT;
	else if (GetAsyncKeyState(VK_RIGHT)) player.movement = Movement::RIGHT;
	else player.movement = Movement::INVALID;
	if (GetAsyncKeyState(VK_SPACE)) player.action = Action::CAPTURE;
	else player.action = Action::MOVE;
	switch (player.movement) {
	case Movement::UP:
		if (map[player.position.x - 1][player.position.y] == Square::NOTHING) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.x--;
		}
		break;

	case Movement::DOWN:
		if (map[player.position.x + 1][player.position.y] == Square::NOTHING) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.x++;
		}
		break;

	case Movement::RIGHT:
		if (map[player.position.x][player.position.y + 1] == Square::NOTHING) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.y++;
		}
		break;

	case Movement::LEFT:
		if (map[player.position.x][player.position.y - 1] == Square::NOTHING) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.y--;
		}
		break;
	default:
		break;
	}
	switch (player.action) {
	case Action::CAPTURE:
		if (player.lastMovement == Movement::UP && map[player.position.x - 1][player.position.y] == Square::POKEMON) {
			FightPokemon(player.position.x - 1, player.position.y);
			map[player.position.x - 1][player.position.y] = Square::NOTHING;
		}
		else if (player.lastMovement == Movement::DOWN && map[player.position.x + 1][player.position.y] == Square::POKEMON) {
			FightPokemon(player.position.x + 1, player.position.y);
			map[player.position.x + 1][player.position.y] = Square::NOTHING;
		}
		else if (player.lastMovement == Movement::RIGHT && map[player.position.x][player.position.y + 1] == Square::POKEMON) {
			FightPokemon(player.position.x, player.position.y + 1);
			map[player.position.x][player.position.y + 1] = Square::NOTHING;
		}
		else if (player.lastMovement == Movement::LEFT && map[player.position.x][player.position.y - 1] == Square::POKEMON) {
			FightPokemon(player.position.x, player.position.y - 1);
			map[player.position.x][player.position.y - 1] = Square::NOTHING;
		}
		break;
	default:
		break;
	}
	map[player.position.x][player.position.y] = Square::PLAYER;
}

void Map::UpdateMap() {
	if (player.numCapturedPokemons >= pokemonsToUnlockForest && !unlockedForest) {
		int col = NUM_COLS / 2;
		for (int row = 1; row < NUM_ROWS / 2; row++) {
			map[row][col] = Square::NOTHING;
		}
		unlockedForest = true;
	}
	if (player.numCapturedPokemons >= pokemonsToUnlockCave && !unlockedCave) {
		int row = NUM_ROWS / 2;
		for (int col = NUM_COLS / 2 + 1; col < NUM_COLS - 1; col++) {
			map[row][col] = Square::NOTHING;
		}
		unlockedCave = true;
	}
	if (player.numCapturedPokemons >= pokemonsToUnlockPokenti && !unlockedPokenti) {
		int col = NUM_COLS / 2;
		for (int row = NUM_ROWS / 2 + 1; row < NUM_ROWS - 1; row++) {
			map[row][col] = Square::NOTHING;
		}
		unlockedPokenti = true;
	}
}

void Map::UpdateScene(){
	if (player.position.x < NUM_ROWS / 2 && player.position.y < NUM_COLS / 2) player.scene = Scene::PUEBLO_PALETA;
	else if (player.position.x < NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) player.scene = Scene::BOSQUE;
	else if (player.position.x > NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) player.scene = Scene::CUEVA_CELESTE;
	else if (player.position.x < NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) player.scene = Scene::LIGA_POKENTI;
}

Map::~Map() {
	if (pokemons != nullptr) {
		delete[] pokemons;
		pokemons = nullptr;
	}
	if (map != nullptr) {
		delete[] map;
		map = nullptr;
	}
}