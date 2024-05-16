#include "Game.h"


Game::Game() {
	bool correct = false;
	while (!correct) {
		std::cout << "How many players? (2-4)" << std::endl;
		std::cin >> num_players;
		if (num_players > 4 || num_players < 2) {
			std::cout << "Not valid amount of players!" << std::endl;
		}
		else {
			system("cls");
		}
	}
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
		deck.push_back(card);
	}

	for (int i = 0; i < INITIAL_HAND_CARDS; i++) {
		for (int i = 0; i < num_players; i++) {
			Card randCard;
			players[i].InsertCard(randCard);
		}
	}
}

Card Game::GetNewCard(){
	Card auxCard = deck.back();
	deck.pop_back();
	return auxCard;
}

void Game::DiscardedCard(Card c) {
	discarded.push_back(c);
}

void Game::PrintDiscarded() {
	if (discarded.size() != 0) {
		std::cout << discarded.back().GetValue();
		switch (discarded.back().GetSuit()) {
		case Suit::SPADES:
			std::cout << "SPD";
			break;
		case Suit::COINS:
			std::cout << "COI";
			break;
		case Suit::CUPS:
			std::cout << "CPS";
			break;
		case Suit::CLUBS:
			std::cout << "CLB";
			break;
		default:
			break;
		}
		std::cout << " - ";
	}
}