#include "gtest/gtest.h"
#include "Deck.h"

TEST(first,first){
EXPECT_EQ(1,1);
}

TEST(constructor,first){
    Card res;
    res.suit= static_cast<Suit>(3);
    res.rang= static_cast<Rang>(13);
    Deck desk(res);
    EXPECT_EQ(desk.get_card(0).rang,13);
    EXPECT_EQ(desk.get_card(0).suit,3);
    EXPECT_NE(desk.get_card(0).rang,11);
    EXPECT_NE(desk.get_card(0).suit,8);
    EXPECT_EQ(desk.get_size(),1);
    EXPECT_NE(desk.get_size(),12);
}
TEST(constructor1,first){
    Card res;
    res.suit= static_cast<Suit>(2);
    res.rang= static_cast<Rang>(8);
    Deck desk(res);
    Card rec;
    rec.suit= static_cast<Suit>(3);
    rec.rang= static_cast<Rang>(13);
    desk.set(rec);
    EXPECT_EQ(desk.get_card(0).rang,8);
    EXPECT_EQ(desk.get_card(0).suit,2);
    EXPECT_NE(desk.get_card(0).rang,11);
    EXPECT_NE(desk.get_card(0).suit,8);
    EXPECT_EQ(desk.get_size(),2);
    EXPECT_NE(desk.get_size(),12);

    EXPECT_EQ(desk.get_card(1).rang,13);
    EXPECT_EQ(desk.get_card(1).suit,3);
    EXPECT_NE(desk.get_card(1).rang,11);
    EXPECT_NE(desk.get_card(1).suit,8);
    EXPECT_EQ(desk.get_size(),2);
    EXPECT_NE(desk.get_size(),12);
}
TEST(sort,first){
    Card res;
    res.suit= static_cast<Suit>(3);
    res.rang= static_cast<Rang>(8);
    Deck desk(res);
    Card rec;
    rec.suit= static_cast<Suit>(2);
    rec.rang= static_cast<Rang>(13);
    desk.set(rec);
    EXPECT_EQ(desk.get_card(0).rang,8);
    EXPECT_EQ(desk.get_card(0).suit,3);
    EXPECT_NE(desk.get_card(0).rang,11);
    EXPECT_NE(desk.get_card(0).suit,8);
    EXPECT_EQ(desk.get_size(),2);
    EXPECT_NE(desk.get_size(),12);

    EXPECT_EQ(desk.get_card(1).rang,13);
    EXPECT_EQ(desk.get_card(1).suit,2);
    EXPECT_NE(desk.get_card(1).rang,11);
    EXPECT_NE(desk.get_card(1).suit,8);
    EXPECT_EQ(desk.get_size(),2);
    EXPECT_NE(desk.get_size(),12);
    desk.sort();
    EXPECT_EQ(desk.get_card(0).suit,2);
}
TEST(constructor3,first){
    Card res;
    res.suit= static_cast<Suit>(3);
    res.rang= static_cast<Rang>(13);
    Deck desk(res);
    Deck deck(desk);
    EXPECT_EQ(desk.get_card(0).rang,deck.get_card(0).rang);
    EXPECT_EQ(desk.get_card(0).suit,deck.get_card(0).suit);
    EXPECT_EQ(desk.get_size(),deck.get_size());
    EXPECT_NE(desk.get_size(),12);
}
