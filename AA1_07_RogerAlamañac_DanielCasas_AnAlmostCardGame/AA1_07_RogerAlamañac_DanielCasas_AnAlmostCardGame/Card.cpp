#include "Card.h"
#include <ctime>
#include <iostream>

Card::Card(){
    int initCard = rand() % 4;
    m_value = rand() % (12 - 1 + 1) + 1;
    switch(initCard){
        case 0: m_suit = Suit::SPADES;
            break;
        case 1: m_suit = Suit::COINS;
            break;
        case 2: m_suit = Suit::CUPS;
            break;
        case 3: m_suit = Suit::CLUBS;
            break;
        default: m_suit == Suit::INVALID;
            break;
    }    
}

Card::Card(int value) {
    int initCard = rand() % 4;
    m_value = value;
    switch (initCard) {
    case 0: m_suit = Suit::SPADES;
        break;
    case 1: m_suit = Suit::COINS;
        break;
    case 2: m_suit = Suit::CUPS;
        break;
    case 3: m_suit = Suit::CLUBS;
        break;
    default: m_suit == Suit::INVALID;
        break;
    }
}

Suit Card::GetSuit() const {
    return m_suit;
}
int Card::GetValue() const {
    return m_value;
}