#include "Player.h"
#include "Windows.h"
#include <conio.h>
#include <iostream>

Player::Player() {
	position.x = 0;
	position.y = 0;
}

void Player::PlayerMovement(Map map) {
	UpdateScene(map);
	char Tecla = _getch();
	int size;
	Movement movement;
	if (GetAsyncKeyState(VK_UP)) {
		movement = Movement::UP;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		movement = Movement::DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		movement = Movement::LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		movement = Movement::RIGHT;
	}

	switch (movement) {
	case Movement::UP: 
		if (map.scene == Scene::PUEBLO_PALETA || map.scene == Scene::BOSQUE) {
			if (position.x != 0) position.x--;
		}
		else if (map.scene == Scene::CUEVA_CELESTE) position.x--;
		else if(map.scene == Scene::LIGA_POKENTI) {
			if (position.x > map.NUM_ROWS / 2) position.x--;
		}
		break;

	case Movement::DOWN: 
		if (map.scene == Scene::PUEBLO_PALETA) {
			if (position.x != map.NUM_ROWS / 2) position.x++;
		}
		else if (map.scene == Scene::BOSQUE) position.x++;
		else if (map.scene == Scene::CUEVA_CELESTE || map.scene == Scene::LIGA_POKENTI) {
			if (position.x != map.NUM_ROWS - 1) position.x++;
		}
		break;

	case Movement::RIGHT: 
		if (map.scene == Scene::PUEBLO_PALETA || map.scene == Scene::LIGA_POKENTI)  position.y++;
		
		else if (map.scene == Scene::CUEVA_CELESTE || map.scene == Scene::BOSQUE){
			if (position.y != map.NUM_COLS) position.y++;
		}
		
		break;

	case Movement::LEFT:
		if (map.scene == Scene::PUEBLO_PALETA || map.scene == Scene::LIGA_POKENTI) {
			if (position.y != 0) position.y--;
		}
		else if (map.scene == Scene::BOSQUE || map.scene == Scene::CUEVA_CELESTE) position.y--;
		break;
	}
}

void Player::UpdateScene(Map map) {
	if (position.x < map.NUM_ROWS / 2 && position.y < map.NUM_COLS / 2) map.scene = Scene::PUEBLO_PALETA;
	else if (position.x > map.NUM_ROWS / 2 && position.y < map.NUM_COLS / 2) map.scene = Scene::BOSQUE;
	else if (position.x < map.NUM_ROWS / 2 && position.y > map.NUM_COLS / 2) map.scene = Scene::CUEVA_CELESTE;
	else map.scene = Scene::LIGA_POKENTI;
}