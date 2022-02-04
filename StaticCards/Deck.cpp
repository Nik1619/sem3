#include "Deck.h"
Deck::Deck(int len):Deck() {
    for (int i=0;i<len;i++){
       // do {
        cards[i].suit = static_cast<Suit>(rand() % 4);
        cards[i].rang = static_cast<Rang>( rand() % 13+2);
        csize++;
       //  } while (prov(cards[i]));
    }
}
Card Deck::get_card(int i) {
    if (i<52){
        return cards[i];
    }
    throw std::runtime_error("Error");
}
Deck::Deck(Card card):Deck() {
    cards[0]=card;
    csize++;
}

void Deck::set(Card card) {
    if (csize<52){
        cards[csize]=card;
        csize++;}
}

int Deck::Unique() {
    {
        for (int i=0;i<csize-1;i++){
            for (int j=i+1;j<csize;j++){
                if (cards[i]==cards[j]) return 1;
            }
        }
        return -1;
    }
}

void Deck::sort() {
    for (int i=0;i<csize-1;i++){
        for (int j=i+1;j<csize;j++){
                if (cards[i].rang>cards[j].rang&&cards[i].suit==cards[j].suit){
                Card tmp;
                tmp.rang=cards[i].rang;
               // tmp.suit=cards[i].suit;
                cards[i].rang= cards[j].rang;
                //cards[i].suit= cards[j].suit;
                cards[j].rang=tmp.rang;
                //cards[j].suit=tmp.suit;
                }
            if (cards[i].suit>cards[j].suit) {
                Card tmp;
                tmp.rang=cards[i].rang;
                tmp.suit=cards[i].suit;
                cards[i].rang= cards[j].rang;
                cards[i].suit= cards[j].suit;
                cards[j].rang=tmp.rang;
                cards[j].suit=tmp.suit;
            }
        }
    }
}
int Deck::get_size() const {
    return csize;
}
Deck Deck::select(Suit suit) {
    Deck dec;
    for (int i=0;i<csize;i++){
        if (cards[i].suit==suit) dec.set(cards[i]);
    }
    return dec;
}
