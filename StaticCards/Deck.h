//
// Created by Kirill on 13.01.2022.
//

#ifndef MSC_DECK_H
#define MSC_DECK_H

#include <iostream>
#include "ctime"
enum Suit{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};
enum  Rang{
    Two=2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};
struct Card{
    Suit suit;
    Rang rang;

    friend bool operator== (const Card &c1, const Card &c2)
    {
        return (c1.suit == c2.suit &&
                c1.rang== c2.rang);
    }
};
class Deck{
private:
    Card cards[52];
    int csize;
    int Unique();
public:
    void set(Card card);
    Card get_card(int i);
    [[nodiscard]] int get_size() const;
    Deck() : cards{},csize(0){};
    explicit Deck(int len);
    explicit Deck(Card card);
    void push_back(Card card);
    Deck select(Suit suit);
    void sort();
    int get_rang (int ind){
        return cards[ind].rang;
    }
};


#endif //MSC_DECK_H
