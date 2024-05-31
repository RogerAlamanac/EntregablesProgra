#include "Pokeballs.h"

Pokeballs::Pokeballs() {
	position.x = 0;
	position.y = 0;
}

int Pokeballs::GetPositionX() const{
	return position.x;
}

int Pokeballs::GetPositionY() const {
	return position.y;
}

void Pokeballs::ChangePosition(int x, int y) {

	position.x = x;
	position.y = y;
}