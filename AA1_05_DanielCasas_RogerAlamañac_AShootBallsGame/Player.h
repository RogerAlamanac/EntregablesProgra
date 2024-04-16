#pragma once
#include <iostream>
#include <conio.h>
#include "Ball.h"
const int AMOUNT_PISTOL_BALLS = 20;
bool gameOver = false;

struct Player {
	std::string name;
	int position, points, numBalls = AMOUNT_PISTOL_BALLS;
	bool hasShoot, pistolEmpty = false;
	Ball bulletsPistol[AMOUNT_PISTOL_BALLS];

	void init(std::string name2, int position2) {
		name = name2;
		position = position2;
		points = 0;
		for (int i = 0; i < AMOUNT_PISTOL_BALLS; ++i) {
			Ball auxiliarBall;
			bulletsPistol[i] = auxiliarBall;
		}
	}

	Ball shoot() {
		if (numBalls > 0) {
			int ballsBefore = numBalls;
			bulletsPistol[AMOUNT_PISTOL_BALLS - numBalls].isDestroyed = true;
			numBalls--;
			return bulletsPistol[AMOUNT_PISTOL_BALLS - ballsBefore];
		}
		else {
			gameOver = true;
			return bulletsPistol[AMOUNT_PISTOL_BALLS - numBalls];
		}
	}

	void AddScore(){
		points++;
	}
};