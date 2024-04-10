#pragma once
#include "Ball.h"
struct Panel {
	Ball* panel;
	int rows, cols, amountBalls;
	void init() {
		std::cout << "ENTER THE AMOUNT OF BALLS: ";
		std::cin >> amountBalls;
	}
	void insert(int position, Ball ball) {
		//Falta acabar
	}

	void verifier(int position, Ball ball){
		
	}

	void deleteThree(int position){

	}

	void insertThree(){
		
	}
};