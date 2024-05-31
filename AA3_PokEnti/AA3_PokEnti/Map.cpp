#include "Map.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>


Map::Map() {
	pokemons = new Pokemon[totalPokemons];
	map = new Square *[NUM_ROWS];
	pokeballs = new Pokeballs[maxPokeBalls];
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
	InsertPokeballs();
	timer = clock();
}

const int NUM_LEVEL_1 = 10;
const int NUM_LEVEL_2 = 8;		
const int NUM_LEVEL_3 = 6;
const int NUM_LEVEL_4 = 4;
const int NUM_LEVEL_5 = 3;
const int NUM_LEVEL_6 = 3;

void Map::InitializePokemons() {
	for (int i = 0; i < totalPokemons; i++) {
		pokemons[i].pokemon = Pokemons::STANDARD;
		pokemons[i].timeToMove = rand() % (maxTimePokemons - minTimePokemons + 1) + minTimePokemons;
		if (i < NUM_LEVEL_1) {
			pokemons[i].strengthLevel = 1;
			pokemons[i].lifes = healthPokemons;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2) {
			pokemons[i].strengthLevel = 2;
			pokemons[i].lifes = healthPokemons;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3) {
			pokemons[i].strengthLevel = 3;
			pokemons[i].lifes = healthPokemons;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3 + NUM_LEVEL_4) {
			pokemons[i].strengthLevel = 4;
			pokemons[i].lifes = healthPokemons;
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3 + NUM_LEVEL_4 + NUM_LEVEL_5) {
			pokemons[i].strengthLevel = 5;
			pokemons[i].lifes = healthPokemons;
		}
		else if (i == totalPokemons - 1) {
			pokemons[i].pokemon = Pokemons::MEWTWO;
			pokemons[i].lifes = healthMewtwo;
			pokemons[i].strengthLevel = 6;
		}
		else {
			pokemons[i].strengthLevel = 6;
			pokemons[i].lifes = healthPokemons;
		}
		int x;
		int y;
		if (pokemons[i].pokemon == Pokemons::MEWTWO) {
			x = NUM_ROWS * 3 / 4;
			y = NUM_COLS * 1 / 4;
		}
		else {
			do {
				if (i < pokemonsPuebloPaleta) {
					x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
					y = rand() % ((NUM_COLS / 2 - 1) - 2 + 1) + 1;
				}
				else if (i < pokemonsForest) {
					x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
					y = rand() % ((NUM_COLS - 1) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
				}
				else {
					x = rand() % ((NUM_ROWS - 2) - (NUM_ROWS / 2 + 1) + 1) + (NUM_ROWS / 2 + 1);
					y = rand() % ((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
				}
			} while (map[x][y] != Square::NOTHING);
		}
		pokemons[i].position.x = x;
		pokemons[i].position.y = y;
		if (pokemons[i].pokemon == Pokemons::MEWTWO) map[pokemons[i].position.x][pokemons[i].position.y] = Square::MEWTWO;
		else map[pokemons[i].position.x][pokemons[i].position.y] = Square::POKEMON;
	}
}

void Map::PrintMap() {
	UpdateMap();
	system("cls");
	std::cout << "Captured Pokemons: " << player.numCapturedPokemons << "   Pokeballs: " << player.numPokeballs << std::endl;
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
			else if(map[row][col] == Square::POKEBALL) std::cout << "O";
			else if (map[row][col] == Square::MEWTWO) std::cout << "M";
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

int Map::FindPokemonPosition(int x, int y) const {
	for (int i = 0; i < totalPokemons; i++) {
		if (pokemons[i].position.x == x && pokemons[i].position.y == y) return i;
	}
	return -1;
}

void Map::FightPokemon(int x, int y){
	std::cout << std::endl << "You have a Pokemon nearby, do you want to capture it?" << std::endl;
	pokemons[FindPokemonPosition(x, y)].CapturePokemon(player);
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
			pokemons[position].position.y = rand() % (NUM_ROWS / 2 - 1);
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
	pokemons[position].lifes = healthPokemons;
	pokemons[position].timeToMove = rand() % (maxTimePokemons - minTimePokemons + 1) + minTimePokemons;
	map[pokemons[position].position.x][pokemons[position].position.y] = Square::POKEMON;
}

void Map::PokemonsMovement() {
	timer = clock();
	for (int i = 0; i < totalPokemons; i++) {
		if (!pokemons[i].hasTakenTime) {
			pokemons[i].initialTime = float(timer) / CLOCKS_PER_SEC;
			pokemons[i].hasTakenTime = true;
		}
		if ((float(timer) / CLOCKS_PER_SEC) - pokemons[i].initialTime >= pokemons[i].timeToMove) {
			int x = pokemons[i].position.x;
			int y = pokemons[i].position.y;
			do {
				int random = rand() % 4;
				switch (random) {
				case 0:
					x += 1;
					break;
				case 1:
					x -= 1;
					break;
				case 2:
					y += 1;
					break;
				default:
					y -= 1;
					break;
				}
			} while (map[x][y] != Square::NOTHING);
			map[pokemons[i].position.x][pokemons[i].position.y] = Square::NOTHING;
			pokemons[i].position.x = x;
			pokemons[i].position.y = y;
			map[pokemons[i].position.x][pokemons[i].position.y] = Square::POKEMON;
			pokemons[i].hasTakenTime = false;
		}
	}
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
		else if (map[player.position.x - 1][player.position.y] == Square::POKEBALL) {
			NewPokeball();
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.numPokeballs++;
			player.position.x--;
		}
		break;

	case Movement::DOWN:
		if (map[player.position.x + 1][player.position.y] == Square::NOTHING) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.x++;
		}
		else if (map[player.position.x + 1][player.position.y] == Square::POKEBALL) {
			NewPokeball();
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.numPokeballs++;
			player.position.x++;
		}
		break;

	case Movement::RIGHT:
		if (map[player.position.x][player.position.y + 1] == Square::NOTHING) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.y++;
		}
		else if (map[player.position.x][player.position.y + 1] == Square::POKEBALL) {
			NewPokeball();
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.numPokeballs++;
			player.position.y++;
		}
		break;

	case Movement::LEFT:
		if (map[player.position.x][player.position.y - 1] == Square::NOTHING) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.y--;
		}
		else if (map[player.position.x][player.position.y - 1] == Square::POKEBALL) {
			NewPokeball();
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.numPokeballs++;
			player.position.y--;
		}
		break;
	default:
		break;
	}
	switch (player.action) {
	case Action::CAPTURE:
		if (map[player.position.x - 1][player.position.y] == Square::POKEMON) {
			FightPokemon(player.position.x - 1, player.position.y);
			map[player.position.x - 1][player.position.y] = Square::NOTHING;
		}
		else if (map[player.position.x - 1][player.position.y - 1] == Square::POKEMON) {
			FightPokemon(player.position.x - 1, player.position.y - 1);
			map[player.position.x - 1][player.position.y - 1] = Square::NOTHING;
		}
		else if (map[player.position.x - 1][player.position.y + 1] == Square::POKEMON) {
			FightPokemon(player.position.x - 1, player.position.y + 1);
			map[player.position.x - 1][player.position.y + 1] = Square::NOTHING;
		}
		else if (map[player.position.x + 1][player.position.y] == Square::POKEMON) {
			FightPokemon(player.position.x + 1, player.position.y);
			map[player.position.x + 1][player.position.y] = Square::NOTHING;
		}
		else if (map[player.position.x + 1][player.position.y - 1] == Square::POKEMON) {
			FightPokemon(player.position.x + 1, player.position.y - 1);
			map[player.position.x + 1][player.position.y - 1] = Square::NOTHING;
		}
		else if (map[player.position.x + 1][player.position.y + 1] == Square::POKEMON) {
			FightPokemon(player.position.x + 1, player.position.y + 1);
			map[player.position.x + 1][player.position.y + 1] = Square::NOTHING;
		}
		else if (map[player.position.x][player.position.y + 1] == Square::POKEMON) {
			FightPokemon(player.position.x, player.position.y + 1);
			map[player.position.x][player.position.y + 1] = Square::NOTHING;
		}
		else if (map[player.position.x][player.position.y - 1] == Square::POKEMON) {
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

void Map::InsertPokeballs() {
	int x = 0;
	int y = 0;
	for (int i = 0; i < maxPokeBalls;) {
		if (i < pokeballsPuebloPaleta) {
			x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
			y = rand() % ((NUM_COLS / 2 - 1) - 2 + 1) + 1;
		}
		else if (i < pokeballsPuebloPaleta + pokeballsCave) {
			x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
			y = rand() % ((NUM_COLS - 1) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
		}
		else {
			x = rand() % ((NUM_ROWS - 2) - (NUM_ROWS / 2 + 1) + 1) + (NUM_ROWS / 2 + 1);
			y = rand() % ((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
		}
		if (map[x][y] == Square::NOTHING) {
			pokeballs[i].ChangePosition(x, y);
			map[pokeballs[i].GetPositionX()][pokeballs[i].GetPositionY()] = Square::POKEBALL;
			i++;
		}
	}
}

void Map::NewPokeball(){
	int position = 0;
	if (player.lastMovement == Movement::UP) position = FindPokeballPosition(player.position.x - 1, player.position.y);
	else if (player.lastMovement == Movement::DOWN) position = FindPokeballPosition(player.position.x + 1, player.position.y);
	else if (player.lastMovement == Movement::RIGHT) position = FindPokeballPosition(player.position.x, player.position.y + 1);
	else if (player.lastMovement == Movement::LEFT) position = FindPokeballPosition(player.position.x, player.position.y - 1);
	int x = 0;
	int y = 0;
	do {
		if (player.scene == Scene::PUEBLO_PALETA) {
			x = rand() % (NUM_COLS / 2);
			y = rand() % (NUM_ROWS / 2 - 1);
		}
		else if (player.scene == Scene::BOSQUE) {
			x = rand() % (((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1));
			y = rand() % (((NUM_ROWS / 2 - 1) - 2 + 1) + 2);
		}
		else if (player.scene == Scene::CUEVA_CELESTE) {
			x = rand() % (((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1));
			y = rand() % (((NUM_ROWS - 2) - (NUM_ROWS / 2 + 1) + 1) + (NUM_ROWS / 2 + 1));
		}
	} while (map[x][y] != Square::NOTHING);
	pokeballs[position].ChangePosition(x, y);
	map[x][y] = Square::POKEBALL;
}

int Map::FindPokeballPosition(int x, int y) {
	for (int i = 0; i < maxPokeBalls; i++) {
		if (pokemons[i].position.x == x && pokemons[i].position.y == y) return i;
	}
	return -1;
	return -1;
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
	if (pokeballs != nullptr) {
		delete[] pokeballs;
		pokeballs = nullptr;
	}
	timer = clock() - timer;
}