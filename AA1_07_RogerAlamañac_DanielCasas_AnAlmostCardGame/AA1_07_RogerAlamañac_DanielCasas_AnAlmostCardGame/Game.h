#pragma once
#include "Player.h"
class Game
{
private:
	Player* players;
	std::list<Card> deck;
	std::list<Card> discarded;
public:
	Game();
	Card GetNewCard();
	void DiscardedCard(Card c);
	void PrintDiscarded();
};