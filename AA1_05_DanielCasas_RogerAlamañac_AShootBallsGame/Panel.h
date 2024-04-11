#pragma once
#include "Player.h"

int amountBalls;

struct Panel {
	Ball* panel;
	int size;
	void init() {
		std::cout << "ENTER THE AMOUNT OF BALLS: ";
		std::cin >> amountBalls;
	}
	void insert(int position, Ball ball, Player player) {
		panel = new Ball[size + 1];
		for (int i = player.position; i < amountBalls - player.position; i++) {
			Ball aux;
			aux = panel[i + 1];
			panel[i + 1] = panel[i];

		}
		panel[player.position] = ball;
	}

	int verifier(int position, Ball ball){
		if (panel[ball.position].color == panel[ball.position + 1].color && panel[ball.position].color == panel[ball.position - 1].color) {
			insert(position, ball);
		}
		return position;
	}

	void deleteThree(int position){

	}

	void insertThree(){
		
	}
};