#pragma once
#include <iostream>
#include "Card.h"
#include <vector>
class Player
{
private:
	std::string id;
	std::vector<Card> hand;
public:
	void SetID(std::string newName);
	void OrderCards();
	void InsertCard(Card c);
	Card GetCard();
	Card GetCard(Suit s);
	void PrintHand() const;
	std::string GetID() const;
};