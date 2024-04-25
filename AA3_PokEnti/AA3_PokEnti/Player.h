#pragma once
#include "Position.h"
enum class Movement {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class Player{
public:
	Position position;
};