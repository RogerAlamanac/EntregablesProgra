#pragma once
#include <iostream>
#define AMOUNT_PISTOL_BALLS 20

struct Ball {
	int position, color;
	bool isDestroyed = false;
	Ball() {
		color = rand() % (6 - 2 + 1) + 1; //2 Verd, 3 Blau fluix, 4 Vermell, 5 Lila, 6 Taronja
	}
};