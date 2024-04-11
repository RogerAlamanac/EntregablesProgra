#pragma once
#include "Player.h"

int amountBalls;
const int maxConsecutiveBalls = 3;
struct Panel {
	Ball* panel;
	int size;
	void init() {
		std::cout << "ENTER THE AMOUNT OF BALLS: ";
		std::cin >> amountBalls;
	}
	void insert(int position, Ball ball) {
		panel = new Ball[size + 1];
		for (int i = size; i < ball.position; i--) {
			panel[i - 1] = panel[i];
		}
		panel[ball.position] = ball;
	}

	int verifier(int position, Ball ball){
		if (panel[position].color == panel[position - 1].color) {
			if (panel[position - 2].color == panel[position - 1].color) position -= 2;
			else position -= 1;
		}
		else if (panel[position].color == panel[position + 1].color) {
			if (panel[position + 1].color == panel[position + 2].color) position += 2;
			else position += 1;
		}
		return position;
	}

	void deleteThree(int position){
		for (int i = position; i < position + maxConsecutiveBalls; i++) {
			panel[i].isDestroyed = true;
		}
	}

	void insertThree(){
		int ballsToInsert = 3;
		for(int i = size; i < ballsToInsert; i++){
			
		}
	}
};