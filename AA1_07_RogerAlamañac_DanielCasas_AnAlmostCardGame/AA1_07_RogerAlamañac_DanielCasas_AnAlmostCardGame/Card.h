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
    Card();
    Card(int value);
    bool IsCardRepeated(Card card1, Card card2) const;
    Suit GetSuit() const;
    int GetValue() const;
};