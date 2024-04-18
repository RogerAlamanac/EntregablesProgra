#include "Panel.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Para los colores de las pelotas
int amountBalls;

void Panel::init() {
	std::cout << "ENTER THE AMOUNT OF BALLS: ";
	std::cin >> amountBalls;
	size = amountBalls;
	panel = new Ball[size];
	for (int i = 0; i < size; ++i) {
		Ball randomBall;
		panel[i] = randomBall;
		panel[i].position = i;
		if (i >= 2) { //Para que no se generen 3 bolas juntan
			for (bool hasDifferentColor = false; !hasDifferentColor;) {
				if (panel[i].color == panel[i - 1].color && panel[i].color == panel[i - 2].color) {
					panel[i].color = rand() % (6 - 2 + 1) + 2;
				}
				else hasDifferentColor = true;
			}
		}
	}
}

void Panel::insert(int position, Ball& ball) {
	size += 1;
	Ball* auxBalls = new Ball[size];
	for (int i = 0; i < size - 1; i++) {
		auxBalls[i] = panel[i];
	}
	for (int i = size - 1; i > position; --i) {
		auxBalls[i] = auxBalls[i - 1];
		auxBalls[i].position = i;
	}
	auxBalls[position] = ball;
	ball.position = position;
	delete[] panel;
	panel = auxBalls;
}

int Panel::verifier(int position, Ball ball) {
	int sameColor = 1;
	if (panel[position].color == panel[position - 1].color && position >= 2) {
		sameColor++;
		if (panel[position - 2].color == panel[position - 1].color) {
			position -= 2;
			sameColor++;
		}
		else if (panel[position + 1].color == panel[position].color) {
			sameColor++;
		}
	}
	else if (panel[position].color == panel[position + 1].color && position <= size - 3) {
		sameColor++;
		if (panel[position + 1].color == panel[position + 2].color) {
			position += 2;
			sameColor++;
		}
		else if (panel[position - 1].color == panel[position].color) {
			sameColor++;
		}
	}
	if (sameColor == 3) return position;
	else return -1;
}

void Panel::deleteThree(int position) {
	if (position != -1) {
		size -= 3;
		Ball* auxPanel = new Ball[size];
		for (int i = position; i < position + maxConsecutiveBalls; i++) {
			panel[i].isDestroyed = true;
		}
		bool afterDestroyedPlayer = false;
		for (int i = 0; i < size; i++) {
			if (panel[i].isDestroyed) afterDestroyedPlayer = true;
			if (afterDestroyedPlayer) {
				auxPanel[i] = panel[i + 3];
			}
			else auxPanel[i] = panel[i];
		}
		delete[] panel;
		panel = auxPanel;
	}
}

void Panel::insertThree() {
	Ball* auxBalls = new Ball[size + 3];
	for (int i = 0; i < size; i++) {
		auxBalls[i] = panel[i];
	}
	int lastBallBefore = size - 1;
	size += 3;
	for (int i = size - 1; i > lastBallBefore; i--) {
		Ball randomBall;
		auxBalls[i] = randomBall;
	}
	delete[] panel;
	panel = auxBalls;
}

void Panel::printPanel(Player player) {
	std::cout << "NAME: " << player.name << "\t" << "SCORE:" << player.points << "\n\n";
	for (int i = 0; i < size; i++) {
		if (panel[i].color == 2) SetConsoleTextAttribute(hConsole, 2);       //2 Verde, 3 Azul cielo, 4 Rojo, 5 Lila, 6 Naranja, 7 Blanco
		else if (panel[i].color == 3) SetConsoleTextAttribute(hConsole, 3);
		else if (panel[i].color == 4) SetConsoleTextAttribute(hConsole, 4);
		else if (panel[i].color == 5) SetConsoleTextAttribute(hConsole, 5);
		else if (panel[i].color == 6) SetConsoleTextAttribute(hConsole, 6);
		std::cout << ball << " ";
	}
	SetConsoleTextAttribute(hConsole, 7);
}

void Panel::printPlayer(Player player) {
	std::cout << "\n\n";//\n\n\n\n\n\n\n\n";
	for (int i = 0; i < size; i++) {
		if (i == player.position) std::cout << static_cast<char> (202);
		else std::cout << "  ";
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		if (i == player.position) {
			SetConsoleTextAttribute(hConsole, player.bulletsPistol[AMOUNT_PISTOL_BALLS - player.numBalls].color);
			std::cout << ball;
		}
		else std::cout << "  ";
	}
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << std::endl;
}

Panel::~Panel() {
	if (panel != nullptr) {
		delete[] panel;
		panel = nullptr;
	}
}

void playerMovement(Player& player, Panel& panel) {
	char movement = _getch();
	int rightBorder = panel.size - 1, leftBorder = 0;
	if ((movement == 'd' || movement == 'D') && player.position < rightBorder) player.position++;
	else if ((movement == 'a' || movement == 'A') && player.position > leftBorder) player.position--;
	if (movement == 'j' || movement == 'J') {
		Ball auxBall = player.shoot();
		auxBall.position = player.position;
		panel.insert(player.position, auxBall);
		player.bulletsPistol[AMOUNT_PISTOL_BALLS - player.numBalls];
		if (panel.verifier(player.position, panel.panel[player.position]) != -1) {
			panel.deleteThree(panel.verifier(player.position, panel.panel[player.position]));
			player.addScore();
			panel.insertThree();
		}
	}
}
