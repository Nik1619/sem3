#include <iostream>
#include "../libr/Deck.h"

void print(Deck *desk) {
    for (int i = 0; i < desk->get_size(); i++) {
        std::cout << desk->get_card(i).rang << " " << desk->get_card(i).suit << std::endl;
    }
}

template<class T>
int static get_num(T &a) {
    while (!(std::cin >> a)) {
        // if (!std::cin.eof()) return -1;
        std::cout << "Bad value!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 1;
}

int dialog(const char *msgs[], int n) {
    char *error = (char *) "";
    int choice;
    do {
        puts(error);
        error = (char *) "You're wrong. Try again!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        get_num(choice);
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

void start() {
    int c = 0;
    int a;
    //std::cout<<"Enter len-->";
    do {
        std::cout << "Enter len-->";
        get_num(a);
    } while (a < 0 || a > 52);
    Deck *deck=new Deck(a);
    srand(time(nullptr));

    const char *pr = " ";
    do {
        const char *MSGS[] = {"0. Quit", "1.Print deck ", "2. Set elem ", "3. Get rang", "4.Get suit ",
                              "5.Sort", "6.Select"};
        const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);
        c = dialog(MSGS, MSGS_SIZE);
        switch (c) {
            case 0: {
                break;
            }
            case 1: {
                print(deck);
               //std::cout<<deck;
                break;
            }
            case 2: {
                Card card;
                std::cin>>card;
                *(deck)+=card;
              ;
                break;
            }
            case 3: {
                int e;
                do {
                    std::cout << "Enter ind-->";
                    get_num(e);
                } while (e < 0 || e > deck->get_size());
                Card c = deck->get_card(e-1);
                std::cout << c.rang << std::endl;
                break;
            }
            case 4: {
                int e;
                do {
                    std::cout << "Enter ind-->";
                    get_num(e);
                } while (e < 0 || e > deck->get_size());

                std::cout << deck->get_card(e-1).suit << std::endl;
                break;
            }
            case 5: {
                deck->sort();
                break;
            }
            case 6: {
                int suit;
                do {
                    std::cout << "Enter suit-->";
                    get_num(suit);
                } while (suit < 0 || suit > 4);
                Suit suit2= static_cast<Suit>(suit);
                Deck a=deck->select(suit2);
                print(&a);
                break;
            }
        }
    } while (c != 0);
    delete deck;
}

int main() {
    Deck desk(5);
    Deck deck=std::move(desk);


   start();
    return 0;
}
