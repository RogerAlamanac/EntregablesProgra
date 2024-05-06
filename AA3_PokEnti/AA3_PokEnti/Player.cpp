#include "Player.h"

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