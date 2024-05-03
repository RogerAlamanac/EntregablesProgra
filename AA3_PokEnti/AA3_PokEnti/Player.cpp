#include "Player.h"

Player::Player() {
	position.x = 2;
	position.y = 2;
	capturedPokemons = new Pokemon[numCapturedPokemons];
}