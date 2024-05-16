#include "Game.h"


Game::Game() {
	std::cout << "How many players?" << std::endl;
	std::cin >> num_players;
	players = new Player[num_players];
	for (int i = 0; i < num_players; i++) {
		int randomName = rand() % (10);
		std::string newName;
		switch (randomName) {
		case 0:
			newName = "JUANJO";
			players[i].SetID(newName);
			break;
		case 1:
			newName = "MANOLO";
			players[i].SetID(newName);
			break;
		case 2:
			newName = "JUANA";
			players[i].SetID(newName);
			break;
		case 3:
			newName = "ROSANA";
			players[i].SetID(newName);
			break;
		case 4:
			newName = "MARCOS";
			players[i].SetID(newName);
			break;
		case 5:
			newName = "ANTONIO";
			players[i].SetID(newName);
			break;
		case 6:
			newName = "PEDRO";
			players[i].SetID(newName);
			break;
		case 7:
			newName = "LUCIA";
			players[i].SetID(newName);
			break;
		case 8:
			newName = "IRIS";
			players[i].SetID(newName);
			break;
		case 9:
			newName = "PATRICIA";
			players[i].SetID(newName);
			break;
		}
	}
	for (int i = 0; i < MAX_CARDS; i++) {
		Card card;
		deck.insert(deck.end(), card);
	}

	for (int i = 0; i < INITIAL_HAND_CARDS; i++) {
		for (int i = 0; i < num_players; i++) {
			Card randCard;
			players[i].InsertCard(randCard);
		}
	}
}