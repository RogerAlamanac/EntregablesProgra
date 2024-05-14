#pragma once
#include <iostream>
#include <list>
#include "Card.h"
class Player
{
private:
	std::string id;
	std::list<Card> hand;
public:
	void OrderCards();
	void InsertCard(Card c);
	Card GetCard();
	Card GetCard(Suit s);
	void PrintHand();
};