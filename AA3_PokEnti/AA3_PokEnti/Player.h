#pragma once
#include "Position.h"
enum class Movement {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	INVALID
};

enum class PokeBallsType {
	POKEBALL,
	SUPERBALL,
	ULTRABALL,
	INVALID
};

struct Player{
	Position position;
	Movement movement = Movement::INVALID;
	PokeBallsType pokeBall = PokeBallsType::INVALID;
	Player();
};