#pragma once
#include "Ball.h"
struct Panel {
	Ball* panel;
	int rows, cols, amountBalls;
	void init() {
		std::cout << "ENTER THE AMOUNT OF BALLS: ";
		std::cin >> amountBalls;
	}
	void insert(Position position, Ball ball) {
		//Falta acabar
	}

	void verifier(Position position, Ball ball){
		
	}

	void deleteThree(Position position){

	}

	void insertThree(){
		
	}
};