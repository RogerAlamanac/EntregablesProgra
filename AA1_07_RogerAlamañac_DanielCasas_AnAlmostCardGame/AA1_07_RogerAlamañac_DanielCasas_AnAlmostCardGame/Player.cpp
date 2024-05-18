#include "Player.h"

void Player::SetID(std::string newName) {
    id = newName;
}


void Player::OrderCards() {
    for (size_t i = 1; i < hand.size(); ++i) {
        Card auxCard = hand[i];
        int j = i - 1;

        while (j >= 0 && (hand[j].GetSuit() > auxCard.GetSuit() || (hand[j].GetSuit() == auxCard.GetSuit() && hand[j].GetValue() > auxCard.GetValue()))) {
            hand[j + 1] = hand[j];
            --j;
        }

        hand[j + 1] = auxCard;
    }
}

void Player::InsertCard(Card c) {
    hand.push_back(c);
    OrderCards();
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

void Player::PrintHand() const{
    std::cout << id << ": ";
    for (int i = 0; i < hand.size(); i++) {
        std::cout << hand[i].GetValue();
        switch (hand[i].GetSuit()) {
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

std::string Player::GetID() const{
    return id;
}