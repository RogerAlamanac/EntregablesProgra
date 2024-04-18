#pragma once
#include <iostream>
#include <conio.h>
#include "Ball.h"
const int AMOUNT_PISTOL_BALLS = 20;
struct Player {
	std::string name;
	int position, points, numBalls = AMOUNT_PISTOL_BALLS;
	bool hasShoot, pistolEmpty = false, gameOver = false;
	Ball bulletsPistol[AMOUNT_PISTOL_BALLS];

	void init(std::string name2, int position2);

	Ball shoot();

	void AddScore();
};