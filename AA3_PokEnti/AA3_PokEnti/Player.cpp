#include "Player.h"
#include <iostream>
Player::Player() {
	position.x = 5;
	position.y = 5;
	capturedPokemons = new Pokemon[numCapturedPokemons];
}

Player::~Player() {
	if (capturedPokemons != nullptr) {
		delete[] capturedPokemons;
		capturedPokemons = nullptr;
	}
}

void Player::PrintScene() {
	switch (scene) {
	case Scene::PUEBLO_PALETA:
		std::cout << "PUEBLO PALETA" << std::endl;
		break;
	case Scene::BOSQUE:
		std::cout << "BOSQUE" << std::endl;
		break;
	case Scene::CUEVA_CELESTE:
		std::cout << "CUEVA CELESTE" << std::endl;
		break;
	case Scene::LIGA_POKENTI:
		std::cout << "LIGA POKENTI" << std::endl;
		break;
	}
}