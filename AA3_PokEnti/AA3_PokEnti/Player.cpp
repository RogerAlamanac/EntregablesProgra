#include "Player.h"
#include <iostream>

Player::Player() {
	position.x = 5;
	position.y = 5;
	capturedPokemons = new Pokemon[numCapturedPokemons];
}

void Player::PrintScene() {
	switch (scene) {
	case Scene::PUEBLO_PALETA:
		std::cout << "\tPUEBLO PALETA" << std::endl;
		break;
	case Scene::BOSQUE:
		std::cout << "\tBOSQUE" << std::endl;
		break;
	case Scene::CUEVA_CELESTE:
		std::cout << "\tCUEVA CELESTE" << std::endl;
		break;
	case Scene::LIGA_POKENTI:
		std::cout << "\tLIGA POKENTI" << std::endl;
		break;
	}
}


Scene Player::GetScene() const {
	return scene;
}
Position Player::GetPosition() const {
	return position;
}
Action Player::GetAction() const {
	return action;
}
Movement Player::GetMovement() const {
	return movement;
}
Movement Player::GetLastMovement() const {
	return lastMovement;
}
int Player::GetNumCapturedPokemons() const {
	return numCapturedPokemons;
}
int Player::GetPokeballs() const {
	return numPokeballs;
}
bool Player::GetCapturedMewtwo() const{
	return capturedMewtwo;
}


void Player::ChangeScene(Scene s) {
	scene = s;
}
void Player::ChangeAction(Action a) {
	action = a;
}
void Player::ChangePosition(Position p) {
	position = p;
}
void Player::ChangePositionX(int x) {
	position.x = x;
}
void Player::ChangePositionY(int y) {
	position.y = y;
}
void Player::ChangeMovement(Movement m) {
	movement = m;
}
void Player::ChangeLastMovement(Movement m) {
	lastMovement = m;
}
void Player::ChangeNumCapturedPokemons(int n) {
	numCapturedPokemons = n;
}
void Player::ChangeNumPokeballs(int p) {
	numPokeballs = p;
}
void Player::ChangeCapturedMewtwo(bool c) {
	capturedMewtwo = c;
}


Player::~Player() {
	if (capturedPokemons != nullptr) {
		delete[] capturedPokemons;
		capturedPokemons = nullptr;
	}
}