#pragma once
enum class Suit{
    SPADES,
    COINS,
    CUPS,
    CLUBS,
    INVALID
};

class Card
{
private:
    Suit m_suit = Suit::INVALID;
    int m_value;
public:
    bool operator==(const Card& card) const{
        return (m_suit == card.m_suit && m_value == card.m_value);
    }
    Card();
    Card(int value);
    Suit GetSuit() const;
    int GetValue() const;
};