#pragma once
#include "Position.h"
#include "Map.h"
enum class Movement {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	INVALID
};

class Player{
private:
	Position position;
public:
	void PlayerMovement(Map map);
	void UpdateScene(Map map);
	Player();
};