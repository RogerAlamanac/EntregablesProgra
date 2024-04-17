#pragma once
#include <iostream>
#include <windows.h>
#include "Player.h"

int amountBalls;
const int maxConsecutiveBalls = 3;
const char ball = static_cast<char> (254);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Para los colores de las pelotas

struct Panel {
	Ball* panel = nullptr;
	int size;

	void init();

	void insert(int position, Ball& ball);

	int verifier(int position, Ball ball);

	void deleteThree(int position);

	void insertThree();

	void printPanel(Player player);

	void printPlayer(Player player);

	~Panel();
};

void playerMovement(Player& player, Panel& panel);