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
	}
}

void Panel::insert(int position, Ball& ball) {
	size += 1;
	Ball* auxBalls = new Ball[size];
	auxBalls = panel;
	panel = auxBalls;
	for (int i = size - 1; i > position; --i) {
		panel[i] = panel[i - 1];
		panel[i].position = i;
	}
	panel[position] = ball;
	ball.position = position;
}

int Panel::verifier(int position, Ball ball) {
	int sameColor = 1;
	if (panel[position].color == panel[position - 1].color && position > 1) {
		sameColor++;
		if (panel[position - 2].color == panel[position - 1].color) {
			position -= 2;
			sameColor++;
		}
		else if (panel[position + 1].color == panel[position].color) {
			position -= 1;
			sameColor++;
		}
	}
	else if (panel[position].color == panel[position + 1].color && position < size - 3) {
		sameColor++;
		if (panel[position + 1].color == panel[position + 2].color) {
			position += 2;
			sameColor++;
		}
		else if (panel[position - 1].color == panel[position].color) {
			position += 1;
			sameColor++;
		}
	}
	if (sameColor == 3) return position;
	else return -1;
}

void Panel::deleteThree(int position) {
	if (position != -1) {
		for (int i = position; i < position + maxConsecutiveBalls; i++) {
			panel[i].isDestroyed = true;
		}
		size -= 3;
		Ball* auxPanel = new Ball[size];
		for (int i = 0; i < size; i++) {
			if (!panel[i].isDestroyed) auxPanel[i] = panel[i];
		}
		panel = new Ball[size];
		for (int i = 0; i < size; i++) {
			panel[i] = auxPanel[i];
		}
	}
}

void Panel::insertThree() {
	const int ballsToInsert = 3;
	size += ballsToInsert;
	panel = new Ball[size];
	for (int i = size - ballsToInsert - 1; i <= size; i++) {
		Ball ball;
		panel[i] = ball;
	}
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
	if (panel != nullptr) delete panel;
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
		panel.deleteThree(panel.verifier(player.position, panel.panel[player.position]));
		if (panel.verifier(player.position, panel.panel[player.position]) != -1) player.AddScore();
	}
}