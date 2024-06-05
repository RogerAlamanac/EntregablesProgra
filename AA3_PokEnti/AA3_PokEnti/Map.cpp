#include "Map.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>
#include <chrono>


Map::Map() {
	pokemons = new Pokemon[totalPokemons];
	map = new Square *[NUM_ROWS];
	pokeballs = new Pokeballs[maxPokeBalls];
	for (int i = 0; i < NUM_ROWS; i++) {
		map[i] = new Square[NUM_COLS];
	}
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {								
			if (i == player.GetPosition().y && j == player.GetPosition().x) map[i][j] = Square::PLAYER;
			else if (i == NUM_ROWS / 2 || j == NUM_COLS / 2 || i == 0 || j == 0 || i == NUM_ROWS - 1 || j == NUM_COLS - 1) map[i][j] = Square::WALL;
			else map[i][j] = Square::NOTHING;
		}
	}
	InitializePokemons();
	InsertPokeballs();
	timer = clock();
}

const int NUM_LEVEL_1 = 6;
const int NUM_LEVEL_2 = 5;		
const int NUM_LEVEL_3 = 4;
const int NUM_LEVEL_4 = 4;
const int NUM_LEVEL_5 = 2;
const int NUM_LEVEL_6 = 3;

void Map::InitializePokemons() {
	for (int i = 0; i < totalPokemons; i++) {
		pokemons[i].ChangeIsMewtwo(Pokemons::STANDARD);
		pokemons[i].ChangeTimeToMove(rand() % (maxTimePokemons - minTimePokemons + 1) + minTimePokemons);
		pokemons[i].RandName();
		if (i < NUM_LEVEL_1) {
			pokemons[i].ChangeStrenght(1);
			pokemons[i].ChangeLifes(healthPokemons);
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2) {
			pokemons[i].ChangeStrenght(2);
			pokemons[i].ChangeLifes(healthPokemons);
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3) {
			pokemons[i].ChangeStrenght(3);
			pokemons[i].ChangeLifes(healthPokemons);
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3 + NUM_LEVEL_4) {
			pokemons[i].ChangeStrenght(4);
			pokemons[i].ChangeLifes(healthPokemons);
		}
		else if (i < NUM_LEVEL_1 + NUM_LEVEL_2 + NUM_LEVEL_3 + NUM_LEVEL_4 + NUM_LEVEL_5) {
			pokemons[i].ChangeStrenght(5);
			pokemons[i].ChangeLifes(healthPokemons);
		}
		else if (i == totalPokemons - 1) {
			pokemons[i].ChangeIsMewtwo(Pokemons::MEWTWO);
			pokemons[i].ChangeStrenght(6);
			pokemons[i].ChangeLifes(healthMewtwo);
			pokemons[i].ChangeName(PokemonName::MEWTWO);
		}
		else {
			pokemons[i].ChangeStrenght(6);
			pokemons[i].ChangeLifes(healthPokemons);
		}
		int x;
		int y;
		if (pokemons[i].GetIsMewtwo() == Pokemons::MEWTWO) {
			x = NUM_ROWS * 3 / 4;
			y = NUM_COLS * 3 / 4;
		}
		else {
			do {
				if (i < pokemonsPuebloPaleta) {
					x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
					y = rand() % ((NUM_COLS / 2 - 1) - 2 + 1) + 1;
				}
				else{
					x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
					y = rand() % ((NUM_COLS - 1) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
				}
			} while (map[x][y] != Square::NOTHING);
		}
		pokemons[i].ChangePositionX(x);
		pokemons[i].ChangePositionY(y);
		if (pokemons[i].GetIsMewtwo() == Pokemons::MEWTWO) map[pokemons[i].GetPosition().x][pokemons[i].GetPosition().y] = Square::MEWTWO;
		else map[pokemons[i].GetPosition().x][pokemons[i].GetPosition().y] = Square::POKEMON;
	}
}

void Map::PrintMap() {
	UpdateMap();
	system("cls");
	std::cout << "Captured Pokemons: " << player.GetNumCapturedPokemons() << "   Pokeballs: " << player.GetPokeballs() << std::endl;
	player.PrintScene();
    const int VIEW = 14;
	int firstRow;
	int firstCol;
	int lastRow;
	int lastCol;
	if (player.GetPosition().x < VIEW / 2) {
		firstRow = 0;
		lastRow = VIEW;
	}
	else if (player.GetPosition().x > ((NUM_ROWS) - 1 - VIEW)) {
		firstRow = NUM_ROWS - VIEW;
		lastRow = NUM_ROWS;
	}
	else {
		firstRow = player.GetPosition().x - VIEW / 2;
		lastRow = player.GetPosition().x + VIEW / 2;
	}

	if (player.GetPosition().y < VIEW) {
		firstCol = 0;
		lastCol = VIEW * 2;
	}
	else if (player.GetPosition().y > ((NUM_COLS) - 1 - VIEW)) {
		firstCol = NUM_COLS - VIEW * 2;
		lastCol = NUM_COLS;
	}
	else {
		firstCol = player.GetPosition().y - VIEW;
		lastCol = player.GetPosition().y + VIEW;
	}

	for (int row = firstRow; row < lastRow; row++) {
		for (int col = firstCol; col < lastCol; col++) {
			if (map[row][col] == Square::WALL) std::cout << 'X';
			else if (map[row][col] == Square::PLAYER) {
				if (player.GetMovement() == Movement::UP) {
					player.ChangeLastMovement(Movement::UP);
					std::cout << '^';
				}
				else if (player.GetMovement() == Movement::DOWN) {
					player.ChangeLastMovement(Movement::DOWN);
					std::cout << 'v';
				}
				else if (player.GetMovement() == Movement::RIGHT) {
					player.ChangeLastMovement(Movement::RIGHT);
					std::cout << '>';
				}
				else if (player.GetMovement() == Movement::LEFT) {
					player.ChangeLastMovement(Movement::LEFT);
					std::cout << '<';
				}
				else {
					if (player.GetLastMovement() == Movement::UP) std::cout << '^';
					else if (player.GetLastMovement() == Movement::DOWN) std::cout << 'v';
					else if (player.GetLastMovement() == Movement::RIGHT) std::cout << '>';
					else if (player.GetLastMovement() == Movement::LEFT) std::cout << '<';
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
		if (pokemons[i].GetPosition().x == x && pokemons[i].GetPosition().y == y) return i;
	}
	return -1;
}

void Map::FightPokemon(int x, int y){
	std::cout << std::endl << "You have a Pokemon nearby, do you want to capture it?" << std::endl;
	pokemons[FindPokemonPosition(x, y)].CapturePokemon(player, pikachuPower);
	if (pokemons[FindPokemonPosition(x, y)].GetIsMewtwo() != Pokemons::MEWTWO) {
		NewPokemon();
	}
	else {
		if (!unlockedPokenti) {
			int col = NUM_COLS / 2;
			for (int row = NUM_ROWS / 2 + 1; row < NUM_ROWS - 1; row++) {
				map[row][col] = Square::NOTHING;
			}
			unlockedPokenti = true;
		}
		map[x][y] == Square::NOTHING;
	}
}

void Map::NewPokemon() {
	int position = 0;
	if (player.GetLastMovement() == Movement::UP) position = FindPokemonPosition(player.GetPosition().x - 1, player.GetPosition().y);
	else if (player.GetLastMovement() == Movement::DOWN) position = FindPokemonPosition(player.GetPosition().x + 1, player.GetPosition().y);
	else if (player.GetLastMovement() == Movement::RIGHT) position = FindPokemonPosition(player.GetPosition().x, player.GetPosition().y + 1);
	else if (player.GetLastMovement() == Movement::LEFT) position = FindPokemonPosition(player.GetPosition().x, player.GetPosition().y - 1);

	do {
		if (player.GetScene() == Scene::PUEBLO_PALETA) {
			pokemons[position].ChangePositionX(rand() % (NUM_COLS / 2));
			pokemons[position].ChangePositionY(rand() % (NUM_ROWS / 2 - 1));
		}
		else {
			pokemons[position].ChangePositionX(rand() % (((NUM_COLS - 2) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1)));
			pokemons[position].ChangePositionY(rand() % (((NUM_ROWS / 2 - 1) - 2 + 1) + 2));
		}
		if (pokemons[position].GetPosition().x > NUM_COLS - 1 || pokemons[position].GetPosition().x < 1) {
			pokemons[position].ChangePositionX(NUM_COLS - 2);
		}
		if (pokemons[position].GetPosition().y > NUM_ROWS - 1 || pokemons[position].GetPosition().y < 1) {
			pokemons[position].ChangePositionY(NUM_ROWS - 2);
		}
	} while (map[pokemons[position].GetPosition().x][pokemons[position].GetPosition().y] != Square::NOTHING);
	pokemons[position].ChangeLifes(healthPokemons);
	pokemons[position].RandName();
	pokemons[position].ChangeTimeToMove(rand() % (maxTimePokemons - minTimePokemons + 1) + minTimePokemons);
	map[pokemons[position].GetPosition().x][pokemons[position].GetPosition().y] = Square::POKEMON;
}

void Map::PokemonsMovement() {
	auto now = std::chrono::high_resolution_clock::now();
	float timer = std::chrono::duration<float>(now.time_since_epoch()).count();

	for (int i = 0; i < totalPokemons; i++) {
		if (pokemons[i].GetIsMewtwo() != Pokemons::MEWTWO) {

			if (!pokemons[i].GetHasTakenTime()) {
				pokemons[i].ChangeInitialTime(timer);
				pokemons[i].ChangeHasTakenTime(true);
			}

			if (timer - pokemons[i].GetInitialTime() >= pokemons[i].GetTimeToMove()) {
				int x = pokemons[i].GetPosition().x;
				int y = pokemons[i].GetPosition().y;

				// Asegurarse de que los nuevos valores x e y sean válidos
				int newX, newY;
				do {
					newX = x;
					newY = y;
					int random = rand() % 4;
					switch (random) {
					case 0: newX += 1; break;
					case 1: newX -= 1; break;
					case 2: newY += 1; break;
					case 3: newY -= 1; break;
					}
				} while (newX < 0 || newX >= NUM_ROWS || newY < 0 || newY >= NUM_COLS || map[newX][newY] != Square::NOTHING);

				// Actualizar la posición del Pokémon en el mapa
				map[x][y] = Square::NOTHING;
				pokemons[i].ChangePositionX(newX);
				pokemons[i].ChangePositionY(newY);
				map[newX][newY] = Square::POKEMON;
				pokemons[i].ChangeHasTakenTime(false);
			}
		}
	}
}

void Map::PlayerMovement() {
	UpdateScene();
	system("pause");
	if (GetAsyncKeyState(VK_UP)) player.ChangeMovement(Movement::UP);
	else if (GetAsyncKeyState(VK_DOWN)) player.ChangeMovement(Movement::DOWN);
	else if (GetAsyncKeyState(VK_LEFT))	player.ChangeMovement(Movement::LEFT);
	else if (GetAsyncKeyState(VK_RIGHT)) player.ChangeMovement(Movement::RIGHT);
	else player.ChangeMovement(Movement::INVALID);
	if (GetAsyncKeyState(VK_SPACE)) player.ChangeAction(Action::CAPTURE);
	else player.ChangeAction(Action::MOVE);
	switch (player.GetMovement()) {
	case Movement::UP:
		if (map[player.GetPosition().x - 1][player.GetPosition().y] == Square::NOTHING) {
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangePositionX(player.GetPosition().x - 1);
		}
		else if (map[player.GetPosition().x - 1][player.GetPosition().y] == Square::POKEBALL) {
			NewPokeball();
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangeNumPokeballs(player.GetPokeballs() + 1);
			player.ChangePositionX(player.GetPosition().x - 1);
		}
		break;

	case Movement::DOWN:
		if (map[player.GetPosition().x + 1][player.GetPosition().y] == Square::NOTHING) {
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangePositionX(player.GetPosition().x + 1);
		}
		else if (map[player.GetPosition().x + 1][player.GetPosition().y] == Square::POKEBALL) {
			NewPokeball();
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangeNumPokeballs(player.GetPokeballs() + 1);
			player.ChangePositionX(player.GetPosition().x + 1);
		}
		break;

	case Movement::RIGHT:
		if (map[player.GetPosition().x][player.GetPosition().y + 1] == Square::NOTHING) {
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangePositionY(player.GetPosition().y + 1);
		}
		else if (map[player.GetPosition().x][player.GetPosition().y + 1] == Square::POKEBALL) {
			NewPokeball();
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangeNumPokeballs(player.GetPokeballs() + 1);
			player.ChangePositionY(player.GetPosition().y + 1);
		}
		break;

	case Movement::LEFT:
		if (map[player.GetPosition().x][player.GetPosition().y - 1] == Square::NOTHING) {
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangePositionY(player.GetPosition().y - 1);
		}
		else if (map[player.GetPosition().x][player.GetPosition().y - 1] == Square::POKEBALL) {
			NewPokeball();
			map[player.GetPosition().x][player.GetPosition().y] = Square::NOTHING;
			player.ChangeNumPokeballs(player.GetPokeballs() + 1);
			player.ChangePositionY(player.GetPosition().y - 1);
		}
		break;
	default:
		break;
	}
	switch (player.GetAction()) {
	case Action::CAPTURE:
		if (map[player.GetPosition().x - 1][player.GetPosition().y] == Square::POKEMON || map[player.GetPosition().x - 1][player.GetPosition().y] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x - 1, player.GetPosition().y);
			map[player.GetPosition().x - 1][player.GetPosition().y] = Square::NOTHING;
		}
		else if (map[player.GetPosition().x - 1][player.GetPosition().y - 1] == Square::POKEMON || map[player.GetPosition().x - 1][player.GetPosition().y - 1] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x - 1, player.GetPosition().y - 1);
			map[player.GetPosition().x - 1][player.GetPosition().y - 1] = Square::NOTHING;
		}
		else if (map[player.GetPosition().x - 1][player.GetPosition().y + 1] == Square::POKEMON || map[player.GetPosition().x - 1][player.GetPosition().y + 1] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x - 1, player.GetPosition().y + 1);
			map[player.GetPosition().x - 1][player.GetPosition().y + 1] = Square::NOTHING;
		}
		else if (map[player.GetPosition().x + 1][player.GetPosition().y] == Square::POKEMON || map[player.GetPosition().x + 1][player.GetPosition().y] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x + 1, player.GetPosition().y);
			map[player.GetPosition().x + 1][player.GetPosition().y] = Square::NOTHING;
		}
		else if (map[player.GetPosition().x + 1][player.GetPosition().y - 1] == Square::POKEMON || map[player.GetPosition().x + 1][player.GetPosition().y - 1] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x + 1, player.GetPosition().y - 1);
			map[player.GetPosition().x + 1][player.GetPosition().y - 1] = Square::NOTHING;
		}
		else if (map[player.GetPosition().x + 1][player.GetPosition().y + 1] == Square::POKEMON || map[player.GetPosition().x + 1][player.GetPosition().y + 1] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x + 1, player.GetPosition().y + 1);
			map[player.GetPosition().x + 1][player.GetPosition().y + 1] = Square::NOTHING;
		}
		else if (map[player.GetPosition().x][player.GetPosition().y + 1] == Square::POKEMON || map[player.GetPosition().x][player.GetPosition().y + 1] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x, player.GetPosition().y + 1);
			map[player.GetPosition().x][player.GetPosition().y + 1] = Square::NOTHING;
		}
		else if (map[player.GetPosition().x][player.GetPosition().y - 1] == Square::POKEMON || map[player.GetPosition().x][player.GetPosition().y - 1] == Square::MEWTWO) {
			FightPokemon(player.GetPosition().x, player.GetPosition().y - 1);
			map[player.GetPosition().x][player.GetPosition().y - 1] = Square::NOTHING;
		}
		break;
	default:
		PokemonsMovement();
		break;
	}
	map[player.GetPosition().x][player.GetPosition().y] = Square::PLAYER;
}

void Map::UpdateMap() {
	if (player.GetNumCapturedPokemons() >= pokemonsToUnlockForest && !unlockedForest) {
		int col = NUM_COLS / 2;
		for (int row = 1; row < NUM_ROWS / 2; row++) {
			map[row][col] = Square::NOTHING;
		}
		unlockedForest = true;
	}
	if (player.GetNumCapturedPokemons() >= pokemonsToUnlockCave && !unlockedCave) {
		int row = NUM_ROWS / 2;
		for (int col = NUM_COLS / 2 + 1; col < NUM_COLS - 1; col++) {
			map[row][col] = Square::NOTHING;
		}
		unlockedCave = true;
	}
}

void Map::UpdateScene(){
	if (player.GetPosition().x < NUM_ROWS / 2 && player.GetPosition().y < NUM_COLS / 2) player.ChangeScene(Scene::PUEBLO_PALETA);
	else if (player.GetPosition().x < NUM_ROWS / 2 && player.GetPosition().y > NUM_COLS / 2) player.ChangeScene(Scene::BOSQUE);
	else if (player.GetPosition().x > NUM_ROWS / 2 && player.GetPosition().y > NUM_COLS / 2) player.ChangeScene(Scene::CUEVA_CELESTE);
	else if (player.GetPosition().x > NUM_ROWS / 2 && player.GetPosition().y < NUM_COLS / 2) player.ChangeScene(Scene::LIGA_POKENTI);
}

void Map::InsertPokeballs() {
	int x = 0;
	int y = 0;
	for (int i = 0; i < maxPokeBalls;) {
		if (i < pokeballsPuebloPaleta) {
			x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
			y = rand() % ((NUM_COLS / 2 - 1) - 2 + 1) + 1;
		}
		else{
			x = rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1;
			y = rand() % ((NUM_COLS - 1) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1);
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
	if (player.GetMovement() == Movement::UP) position = FindPokeballPosition(player.GetPosition().x - 1, player.GetPosition().y);
	else if (player.GetMovement() == Movement::DOWN) position = FindPokeballPosition(player.GetPosition().x + 1, player.GetPosition().y);
	else if (player.GetMovement() == Movement::RIGHT) position = FindPokeballPosition(player.GetPosition().x, player.GetPosition().y + 1);
	else if (player.GetMovement() == Movement::LEFT) position = FindPokeballPosition(player.GetPosition().x, player.GetPosition().y - 1);
	do {
		if (player.GetScene() == Scene::PUEBLO_PALETA) {
			pokeballs[position].ChangePosition(rand() % (NUM_COLS / 2), rand() % (NUM_ROWS / 2 - 1));
		}
		else if (player.GetScene() == Scene::BOSQUE) {
			pokeballs[position].ChangePosition(rand() % ((NUM_ROWS / 2 - 1) - 2 + 1) + 1, rand() % ((NUM_COLS - 1) - (NUM_COLS / 2 + 1) + 1) + (NUM_COLS / 2 + 1));
		}
	} while (map[pokeballs[position].GetPositionX()][pokeballs[position].GetPositionY()] != Square::NOTHING);
	map[pokeballs[position].GetPositionX()][pokeballs[position].GetPositionY()] = Square::POKEBALL;
}

int Map::FindPokeballPosition(int x, int y) {
	for (int i = 0; i < maxPokeBalls; i++) {
		if (pokemons[i].GetPosition().x == x && pokemons[i].GetPosition().y == y) return i;
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