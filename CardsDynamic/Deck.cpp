#include "Deck.h"
Deck::Deck(int len):Deck() {
    cards= new Card[len];
    this->len=len;
    for (int i=0;i<len;i++){
      //  do {
        cards[i].suit = static_cast<Suit>(rand() % 4);
        cards[i].rang = static_cast<Rang>( rand() % 13+2);
       //  } while (Unique()==-1);
        csize++;
    }
}
Card Deck::get_card(int i) {
    if (i<len){
        return cards[i];
    }
    throw std::runtime_error("Error");
}
Deck::Deck(Card card):Deck() {
    cards=new Card[1];
    cards[0]=card;
    csize++;
    len++;
}

Deck::Deck(std::initializer_list<Card> cards):Deck() {
    for (auto c : cards) {
        set(c);
    }
}

void Deck::set(Card card) {
    if (csize<len){
        cards[csize]=card;
        csize++;
        return;}
    len++;
    Card *buff=new Card[len];
    for (int i=0;i<len-1;i++){
        buff[i].rang=cards[i].rang;
        buff[i].suit=cards[i].suit;
    }
    delete[]cards;
    cards = buff;
    buff = nullptr;
    cards[len-1]=card;
    csize++;
}

int Deck::Unique() {
    {
        for (int i=0;i<csize-1;i++){
            for (int j=i+1;j<csize;j++){
                if (cards[i].rang==cards[j].rang) 
                    return -1;
            }
        }
        return 1;
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
        if (cards[i].suit==suit) 
            dec.set(cards[i]);
    }
    return dec;
}

Deck::Deck(Deck &deck) {
    std::cout<<"Copy constr";
    cards=new Card[deck.len];
    len=deck.len;
    csize=deck.csize;
    for (int i=0;i<csize;i++){
        cards[i].rang=deck.cards[i].rang;
        cards[i].suit=deck.cards[i].suit;
    }
}

Deck::Deck(Deck &&deck) noexcept {
    std::cout<<"Move constr";
    cards=deck.cards;
    len=deck.len;
    csize=deck.csize;
    deck.cards= nullptr;
}
Deck &Deck::operator=(const Deck &se) {
    std::cout<<"Copy =";
    if (this == &se)
        return *this;
    delete[] cards;
    len = se.len;
    csize = se.csize;
    cards = new Card[len];
    for (int i = 0; i < csize; i++) {
        cards[i].rang=se.cards[i].rang;
        cards[i].suit=se.cards[i].suit;
    }
    return *this;
}

Deck &Deck::operator=(Deck &se) noexcept {
    std::cout<<"Move =";
    if (this == &se)
        return *this;
    delete[] cards;
    len = se.len;
    csize = se.csize;
    cards = se.cards;
    se.cards = nullptr;
    return *this;
}

