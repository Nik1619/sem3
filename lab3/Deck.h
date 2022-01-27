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
    friend std::ostream& operator<< (std::ostream &out, const Card &card){
        out<<card.rang<<" "<< card.suit;
        return out;
    };
    friend std::istream& operator>> (std::istream &in, Card &point){
        int sui;
        int ran;
        do {
            std::cout << "Enter suit-->";
            in>>sui;
        } while (sui < 0 || sui > 4);
        do {
            std::cout << "Enter rang-->";
            in>>ran;
        } while (ran < 2 || ran > 14);
        point.rang = static_cast<Rang>(ran);
        point.suit = static_cast<Suit>(sui);
        return in;
    };
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
   // void push_back(Card card);
    Deck select(Suit suit);
    void sort();
    friend std::ostream& operator<< (std::ostream &out, const Deck &deck){
        for (int i=0;i<deck.csize;i++){
            std::cout<<deck.cards[i]<<std::endl;
        }
        return out;
    };
   friend Deck& operator +=(Deck &deck,const Card card){
       try {
           //Card card;
           //std::cin>>card;
           deck.set(card);
       }
       catch (std::runtime_error &err) {
           std::cout << err.what() << std::endl;
       }
       return deck;
   };
};


#endif //MSC_DECK_H
