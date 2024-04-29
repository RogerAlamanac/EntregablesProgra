#include <iostream>
#include "Player.h"
#include "Windows.h"
#include <conio.h>
int main()
{
	while (true) {
		// INPUT 
		if (GetAsyncKeyState(VK_UP)) {
			std::cout << "UP";
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			std::cout << "DOWN";
		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			std::cout << "LEFT";
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			std::cout << "RIGHT";
		}
	}
}