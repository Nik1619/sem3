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
    
    Card(Suit s = Suit::Hearts,Rang r = Rang::Two):suit(s),rang(r){}

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
    Card *cards;
    int csize;
    int len;
    int Unique();
public:
    void set(Card card);
    Card get_card(int i);
    [[nodiscard]] int get_size() const;
    Deck() : cards{},csize(0),len(0){};
    explicit Deck(int len);
    explicit Deck(Card card);
    Deck(std::initializer_list<Card>);
   // void push_back(Card card);
    Deck select(Suit suit);
    Deck(Deck &deck);
    Deck(Deck &&deck) noexcept ;
    Deck &operator=(const Deck &se);
    Deck &operator=(Deck &se) noexcept;
    void sort();
    friend std::ostream& operator<< (std::ostream &out, const Deck &deck){
        for (int i=0;i<deck.csize;i++){
            out<<deck.cards[i]<<std::endl;
        }
        return out;
    };
    friend std::istream& operator>> (std::istream& in,  Deck& deck) {
        int len;
        std::cout << "Enter num of cards:\n";
        in >> len;
        for (int i = 0; i < len; i++) {
            std::cout << "Enter Suit of card:\n";
            Suit suit;
            int num;
            in >> num;
            suit = Suit(num);
            std::cout << "Enter Rank of card:\n";
            in >> num;
            Rang rang = Rang(num);
            deck.set((Card(suit,rang)));
        }
        return in;
    };
   friend Deck& operator +=(Deck &deck,const Card card){
       try {

           deck.set(card);
       }
       catch (std::runtime_error &err) {
           std::cout << err.what() << std::endl;
       }
       return deck;
   };
   ~Deck(){
       delete[] cards;
   }
   Card& operator[](int index) {
       if (index<0 || index>csize)
           throw std::invalid_argument("out of range");
       return cards[index];
   }
};


#endif //MSC_DECK_H
