#pragma once
#include <iostream>
#include "Ball.h"

struct Player {
	std::string name;
	int position;
	int points;
	bool shoot;
	int numBalls = AMOUNT_PISTOL_BALLS;
	bool pistolEmpty;
	Ball bulletsPistol[AMOUNT_PISTOL_BALLS];

	void init(std::string name, int position2) {
		std::cout << "ENTER YOUR NAME:  ";
	    std::cin >> name;
		position = position2;
		points = 0;
		for (int i = 0; i < AMOUNT_PISTOL_BALLS; ++i) {
			Ball auxiliarBall;
			bulletsPistol[i] = auxiliarBall;
		}
	}

	Ball shoot() {
		bulletsPistol[AMOUNT_PISTOL_BALLS - numBalls].isDestroyed = true;
		numBalls--;
		return bulletsPistol[AMOUNT_PISTOL_BALLS - numBalls];
	}
};