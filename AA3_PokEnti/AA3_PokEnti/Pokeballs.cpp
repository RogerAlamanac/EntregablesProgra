#include "Pokeballs.h"

Pokeballs::Pokeballs() {
	position.x = 0;
	position.y = 0;
}

int Pokeballs::GetPositionX() {
	return position.x;
}

int Pokeballs::GetPositionY() {
	return position.y;
}

void Pokeballs::ChangePosition(int x, int y) {

	position.x = x;
	position.y = y;
}