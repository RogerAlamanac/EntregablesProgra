#include "Player.h"
#include <iostream>

void Player::init(std::string name2, int position2) {
	name = name2;
	position = position2;
	points = 0;
	for (int i = 0; i < AMOUNT_PISTOL_BALLS; ++i) {
		Ball auxiliarBall;
		bulletsPistol[i] = auxiliarBall;
	}
}

Ball Player::shoot() {
	if (numBalls > 0) {
		int ballsBefore = numBalls;
		bulletsPistol[AMOUNT_PISTOL_BALLS - numBalls].isDestroyed = true;
		numBalls--;
		return bulletsPistol[AMOUNT_PISTOL_BALLS - ballsBefore];
	}
	else {
		gameOver = true;
		Ball lastBall;// = bulletsPistol[AMOUNT_PISTOL_BALLS - numBalls];
		return lastBall;
	}
}

void Player::AddScore() {
	points++;
}