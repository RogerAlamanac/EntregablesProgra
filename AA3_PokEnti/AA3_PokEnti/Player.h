#pragma once
#include "Position.h"
#include "Pokemon.h"
enum class Movement {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	INVALID
};

enum class Action {
	CAPTURE,
	MOVE,
	INVALID
};

enum class Scene {
	PUEBLO_PALETA,
	BOSQUE,
	CUEVA_CELESTE,
	LIGA_POKENTI,
	INVALID
};

struct Player{
	Scene scene = Scene::PUEBLO_PALETA;
	Position position;
	Action action = Action::INVALID;
	Movement movement = Movement::DOWN;
	Movement lastMovement = Movement::DOWN;
	Pokemon* capturedPokemons = nullptr;
	int numCapturedPokemons = 0;
	Player();
	~Player();
	void PrintScene();
};