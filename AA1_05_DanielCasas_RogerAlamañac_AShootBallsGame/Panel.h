#pragma once
#include <iostream>
#include <windows.h>
#include "Player.h"

int amountBalls;
const int maxConsecutiveBalls = 3;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Para los colores de las pelotas

struct Panel {
	Ball* panel;
	int size;

	void init() {
		std::cout << "ENTER THE AMOUNT OF BALLS: ";
		std::cin >> amountBalls;
		panel = new Ball[amountBalls];
	}
	void insert(int position, Ball ball) {
		panel = new Ball[size + 1];
		for (int i = size; i < ball.position; i--) {
			panel[i - 1] = panel[i];
		}
		panel[ball.position] = ball;
	}

	int verifier(int position, Ball ball){
		int counter = 1;
		if (panel[position].color == panel[position - 1].color && position > 1) {
			counter++;
			if (panel[position - 2].color == panel[position - 1].color) {
				position -= 2;
				counter++;
			}
			else if (panel[position + 1].color == panel[position].color) {
				position -= 1;
				counter++;
			}
		}
		else if (panel[position].color == panel[position + 1].color && position < size - 3) {
			counter++;
			if (panel[position + 1].color == panel[position + 2].color) {
				position += 2;
				counter++;
			}
			else if(panel[position - 1].color == panel[position].color){
				position += 1;
				counter++;
			}
		}
		if (counter == 3) return position;
		else return -1;
	}

	void deleteThree(int position){
		for (int i = position; i < position + maxConsecutiveBalls; i++) {
			panel[i].isDestroyed = true;
		}
	}

	void insertThree(){
		const int ballsToInsert = 3;
		panel = new Ball[size + ballsToInsert];
		for(int i = size - ballsToInsert; i <= size; i++){
			Ball ball;
			panel[i] = ball;
		}
	}

	void printPanel() {
		const char ball = static_cast<char> (254);
		for (int i = 0; i < size; i++) {
			if (panel[i].color == 2) SetConsoleTextAttribute(hConsole, 2);       //2 Verde, 3 Azul cielo, 4 Rojo, 5 Lila, 6 Naranja, 7 Blanco
			else if (panel[i].color == 3) SetConsoleTextAttribute(hConsole, 3);
			else if (panel[i].color == 4) SetConsoleTextAttribute(hConsole, 4);
			else if (panel[i].color == 5) SetConsoleTextAttribute(hConsole, 5);
			else if(panel[i].color == 6) SetConsoleTextAttribute(hConsole, 6);
			std::cout << ball;
		}
		SetConsoleTextAttribute(hConsole, 7);
	}

	void printPlayer(Player player) {
		for (int i = 0; i < size; i++) {
			if (i == player.position) std::cout << static_cast<char> (202);
			else std::cout << " ";
		}
	}
};

void playerMovement(Player player, Panel panel) {
	char movement = _getch();
	int rightBorder = panel.size - 1, leftBorder = 0;
	if (movement == 'd' && player.position < rightBorder) player.position++;
	else if (movement == 'a' && player.position > leftBorder) player.position--;
}