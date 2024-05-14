#include "Player.h"


void Player::OrderCards() {
    hand.sort();
}

void Player::InsertCard(Card c) {
	
}

Card Player::GetCard(){
    int randomNum = rand() % hand.size();
    Card randomCard = hand[randomNum];
    std::list<Card>::iterator it;
    it = hand.begin();
    for(; it != hand.end(); it++){
        if (it==hand[randomNum]){
            hand.pop(randomNum);
        } else if(it>hand[randomNum]){
            it-1=it;
        } 
    }
	return randomCard;
}

Card Player::GetCard(Suit s) {
    Card maxCard(0);
    std::list<Card>::iterator it = hand.begin();
    do {
        if (it->GetSuit() == s && it->GetValue() > maxCard.GetValue()) {
            maxCard = *it;
        }
        it++;
    } while (it != hand.end());
    return maxCard;
}