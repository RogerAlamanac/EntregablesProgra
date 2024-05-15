#pragma once
#include "Player.h"
class Game 
{
private:
	const int NUM_PLAYERS = 2;
	const int MAX_CARDS = 52;
	const int INITIAL_HAND_CARDS = 7;
	Player* players;
	std::vector<Card> deck;
	std::vector<Card> discarded;
public:
	Game();
	Card GetNewCard();
	void DiscardedCard(Card c);
	void PrintDiscarded();
};