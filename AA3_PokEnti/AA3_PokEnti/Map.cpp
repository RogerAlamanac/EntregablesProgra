#include "Map.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>

Map::Map() {
	pokemons = new Pokemon[totalPokemons];
	InitializePokemons();
	map = new Square *[NUM_ROWS];
	for (int i = 0; i < NUM_ROWS; i++) {
		map[i] = new Square[NUM_COLS];
	}
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (i == player.position.y && j == player.position.x) map[i][j] = Square::PLAYER;
			else if (i == NUM_ROWS / 2 || j == NUM_COLS / 2 || i == 0 || j == 0 || i == NUM_ROWS - 1 || j == NUM_COLS - 1) map[i][j] = Square::WALL;
			else {
				for (int z = 0; z < totalPokemons; z++) {
					if (i == pokemons[z].position.y && j == pokemons[z].position.x) map[i][j] = Square::POKEMON;
					else {
						map[i][j] = Square::NOTHING;
					}
				}
			}
		}
	}
}

const int NUM_LEVEL_1 = 6;
const int NUM_LEVEL_2 = NUM_LEVEL_1 + 5;
const int NUM_LEVEL_3 = NUM_LEVEL_2 + 4;
const int NUM_LEVEL_4 = NUM_LEVEL_3 + 3;
const int NUM_LEVEL_5 = NUM_LEVEL_4 + 2;
const int NUM_LEVEL_6 = NUM_LEVEL_5 + 1;

void Map::InitializePokemons() {
    for (int i = 0; i < NUM_LEVEL_1 ; i++) { //Vida Nivel 1 = 10->39
        pokemons[i].lifes = rand() % (30 - 10 + 1) + 10;
        pokemons[i].strengthLevel = 1;
		int x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
		int y = rand() % (file.NUM_COLS - 1 + 1) + 1;
		for (int j = 0; j < i;) {
			if (pokemons[j].position.x != x && pokemons[j].position.y != y && x != NUM_COLS / 2 && y != NUM_ROWS / 2 && x != 0 && y != 0 && x != NUM_COLS && y != NUM_ROWS) {
				if (j == i - 1) {
					pokemons[i].position.x = x;
					pokemons[i].position.y = y;
				}
				j++;
			}
			else {
				x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
				y = rand() % (file.NUM_COLS - 1 + 1) + 1;
				j = 0;
			}
		}
    }

    for (int i = NUM_LEVEL_1; i < NUM_LEVEL_2; i++) { //Vida Nivel 2 = 40->69
        pokemons[i].lifes = rand() % (69 - 40 + 1) + 40;
        pokemons[i].strengthLevel = 2;
		int x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
		int y = rand() % (file.NUM_COLS - 1 + 1) + 1;
		for (int j = NUM_LEVEL_1; j < i;) {
			if (pokemons[j].position.x != x && pokemons[j].position.y != y && x != NUM_COLS / 2 && y != NUM_ROWS / 2 && x != 0 && y != 0 && x != NUM_COLS && y != NUM_ROWS) {
				if (j == i - 1) {
					pokemons[i].position.x = x;
					pokemons[i].position.y = y;
				}
				j++;
			}
			else {
				x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
				y = rand() % (file.NUM_COLS - 1 + 1) + 1;
				j = NUM_LEVEL_1;
			}
		}
    }

    for (int i = NUM_LEVEL_2; i < NUM_LEVEL_3; i++) { //Vida Nivel 3 = 70->99
        pokemons[i].lifes = rand() % (99 - 70 + 1) + 70;
        pokemons[i].strengthLevel = 3;
		int x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
		int y = rand() % (file.NUM_COLS - 1 + 1) + 1;
		for (int j = NUM_LEVEL_2; j < i;) {
			if (pokemons[j].position.x != x && pokemons[j].position.y != y && x != NUM_COLS / 2 && y != NUM_ROWS / 2 && x != 0 && y != 0 && x != NUM_COLS && y != NUM_ROWS) {
				if (j == i - 1) {
					pokemons[i].position.x = x;
					pokemons[i].position.y = y;
				}
				j++;
			}
			else {
				x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
				y = rand() % (file.NUM_COLS - 1 + 1) + 1;
				j = NUM_LEVEL_2;
			}
		}
    }

    for (int i = NUM_LEVEL_3; i < NUM_LEVEL_4; i++) { //Vida Nivel 4 = 100->129
        pokemons[i].lifes = rand() % (129 - 100 + 1) + 100;
        pokemons[i].strengthLevel = 4;
		int x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
		int y = rand() % (file.NUM_COLS - 1 + 1) + 1;
		for (int j = NUM_LEVEL_3; j < i;) {
			if (pokemons[j].position.x != x && pokemons[j].position.y != y && x != NUM_COLS / 2 && y != NUM_ROWS / 2 && x != 0 && y != 0 && x != NUM_COLS && y != NUM_ROWS) {
				if (j == i - 1) {
					pokemons[i].position.x = x;
					pokemons[i].position.y = y;
				}
				j++;
			}
			else {
				x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
				y = rand() % (file.NUM_COLS - 1 + 1) + 1;
				j = NUM_LEVEL_3;
			}
		}
    }

    for (int i = NUM_LEVEL_4; i < NUM_LEVEL_5; i++) { //Vida Nivel 5 = 130->159
        pokemons[i].lifes = rand() % (159 - 130 + 1) + 130;
        pokemons[i].strengthLevel = 5;
		int x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
		int y = rand() % (file.NUM_COLS - 1 + 1) + 1;
		for (int j = NUM_LEVEL_4; j < i;) {
			if (pokemons[j].position.x != x && pokemons[j].position.y != y && x != NUM_COLS / 2 && y != NUM_ROWS / 2 && x != 0 && y != 0 && x != NUM_COLS && y != NUM_ROWS) {
				if (j == i - 1) {
					pokemons[i].position.x = x;
					pokemons[i].position.y = y;
				}
				j++;
			}
			else {
				x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
				y = rand() % (file.NUM_COLS - 1 + 1) + 1;
				j = NUM_LEVEL_4;
			}
		}
    }

    for (int i = NUM_LEVEL_5; i < NUM_LEVEL_6; i++) { //Vida Nivel 6 = 160->180
        pokemons[i].lifes = rand() % (180 - 160 + 1) + 160;
        pokemons[i].strengthLevel = 6;
		int x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
		int y = rand() % (file.NUM_COLS - 1 + 1) + 1;
		for (int j = NUM_LEVEL_5; j < i;) {
			if (pokemons[j].position.x != x && pokemons[j].position.y != y && x != NUM_COLS / 2 && y != NUM_ROWS / 2 && x != 0 && y != 0 && x != NUM_COLS && y != NUM_ROWS) {
				if (j == i - 1) {
					pokemons[i].position.x = x;
					pokemons[i].position.y = y;
				}
				j++;
			}
			else {
				x = rand() % (file.NUM_ROWS - 1 + 1) + 1;
				y = rand() % (file.NUM_COLS - 1 + 1) + 1;
				j = NUM_LEVEL_5;
			}
		}
    }
}
void Map::PrintMap() {
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
	for (int rows = 0; rows < NUM_COLS; rows++) {
		for (int cols = 0; cols < NUM_ROWS; cols++) {
			if (map[rows][cols] == Square::WALL) std::cout << 'X';
			else if (map[rows][cols] == Square::PLAYER) {
				if (player.movement == Movement::UP) std::cout << '^';
				else if (player.movement == Movement::DOWN) std::cout << 'v';
				else if (player.movement == Movement::RIGHT) std::cout << '>';
				else if (player.movement == Movement::LEFT) std::cout << '<';
			}
			else if (map[rows][cols] == Square::POKEMON) std::cout << "P";
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Captured Pokemons: " << player.capturedPokemons << std::endl;
}

bool Map::CheckMovement() {
	switch (player.movement) {
	case Movement::UP:
		if (map[player.position.x][player.position.y--] == Square::WALL) return false;
		else return true;

	case Movement::DOWN:
		if (map[player.position.x][player.position.y++] == Square::WALL) return false;
		else return true;

	case Movement::RIGHT:
		if (map[player.position.x++][player.position.y] == Square::WALL) return false;
		else return true;

	case Movement::LEFT:
		if (map[player.position.x--][player.position.y] == Square::WALL) return false;
		else return true;
	default:
		return false;
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

	switch (player.movement) {
	case Movement::UP:
		if (player.scene == Scene::PUEBLO_PALETA || player.scene == Scene::BOSQUE) {
			if (player.position.x != 0) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y--;
			}
		}
		else if (player.scene == Scene::CUEVA_CELESTE) {
			if (player.position.x > NUM_ROWS / 2) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y--;
			}
			else {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y--;
			}

		}
		else if (player.scene == Scene::LIGA_POKENTI) {
			if (player.position.x > NUM_ROWS / 2) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y--;
			}
			else {
				std::cout << "THERE'S A WALL, I DON'T THINK YOU CAN PASS THROUGH IT!" << std::endl;
			}
		}
		break;

	case Movement::DOWN:
		if (player.scene == Scene::PUEBLO_PALETA) {
			if (player.position.x != NUM_ROWS / 2) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y++;
			}
			else {
				std::cout << "THERE'S A WALL, I DON'T THINK YOU CAN PASS THROUGH IT!" << std::endl;
			}
		}
		else if (player.scene == Scene::BOSQUE) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.y++;
		}
		else if (player.scene == Scene::CUEVA_CELESTE || player.scene == Scene::LIGA_POKENTI) {
			if (player.position.x != NUM_ROWS - 1) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.y++;
			}
		}
		break;

	case Movement::RIGHT:
		if (player.scene == Scene::PUEBLO_PALETA || player.scene == Scene::LIGA_POKENTI) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.x++;
		}
		else if (player.scene == Scene::CUEVA_CELESTE || player.scene == Scene::BOSQUE) {
			if (player.position.y != NUM_COLS) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.x++;
			}
		}

		break;

	case Movement::LEFT:
		if (player.scene == Scene::PUEBLO_PALETA || player.scene == Scene::LIGA_POKENTI) {
			if (player.position.y != 0) {
				map[player.position.x][player.position.y] = Square::NOTHING;
				player.position.x--;
			}
			else {
				std::cout << "THERE'S A WALL, I DON'T THINK YOU CAN PASS THROUGH IT!" << std::endl;
			}
		}
		else if (player.scene == Scene::BOSQUE || player.scene == Scene::CUEVA_CELESTE) {
			map[player.position.x][player.position.y] = Square::NOTHING;
			player.position.x--;
		}
		break;
	default:
		break;
	}
	map[player.position.x][player.position.y] = Square::PLAYER;
}

void Map::UpdateScene(){
	if (player.position.x < NUM_ROWS / 2 && player.position.y < NUM_COLS / 2) player.scene = Scene::PUEBLO_PALETA;
	else if (player.position.x > NUM_ROWS / 2 && player.position.y < NUM_COLS / 2) player.scene = Scene::BOSQUE;
	else if (player.position.x < NUM_ROWS / 2 && player.position.y > NUM_COLS / 2) player.scene = Scene::CUEVA_CELESTE;
	else player.scene = Scene::LIGA_POKENTI;
}