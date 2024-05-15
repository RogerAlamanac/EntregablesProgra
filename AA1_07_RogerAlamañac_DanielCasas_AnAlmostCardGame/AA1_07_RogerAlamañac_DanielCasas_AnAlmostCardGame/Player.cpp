#include "Player.h"

void Player::SetID(std::string newName) {
    id = newName;
}


void Player::OrderCards() {
    for (size_t i = 1; i < hand.size(); ++i) {
        Card auxCard = hand[i];
        int j = i - 1;

        // Movemos los elementos mayores hacia adelante
        while (j >= 0 && (hand[j].GetSuit() > auxCard.GetSuit() || (hand[j].GetSuit() == auxCard.GetSuit() && hand[j].GetValue() > auxCard.GetValue()))) {
            hand[j + 1] = hand[j];
            --j;
        }

        // Insertamos la carta en la posición correcta
        hand[j + 1] = auxCard;
    }
}

void Player::InsertCard(Card c) {
	
}

Card Player::GetCard() {
    int randomNum = rand() % hand.size();
    Card randomCard = hand[randomNum];
    hand.erase(hand.begin() + randomNum);
    return randomCard;
}

Card Player::GetCard(Suit s) {
    Card maxCard(0);
    std::vector<Card>::iterator it = hand.begin();
    do {
        if (it->GetSuit() == s && it->GetValue() > maxCard.GetValue()) {
            maxCard = *it;
        }
        it++;
    } while (it != hand.end());
    return maxCard;
}

void Player::PrintHand() {

}