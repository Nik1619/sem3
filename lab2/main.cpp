#include <iostream>
#include "Prog1.h"

using namespace std;
using namespace Prog2;

int main() {
    int h;
    double t;
    chainline l;
    char s = NULL;
    do {
        cout << "0. Exit" << endl;
        cout << "1. Create" << endl;
        cout << "2. Change parameters chainline" << endl;
        cout << "3. Get area of chainline" << endl;
        cout << "4. Get type of chainline" << endl;
        cout << "5. Get parameters of chainline in polar coordinates" << endl;
        cout << "6. Get distance" << endl;
        cout << "7. Get text form of chainline" << endl;

        h = get_int();
        switch (h) {
            case 0:
                cout << "***Exit***" << endl;
                break;

            case 1:
                cout << "***Create chainline***" << endl;
                if (create(l) == 1) return 1;
                break;

            case 2:
                std::cout << "***Change parameters of chainline***" << endl;
                if (change_parameters(l) == 1) return 1;
                break;

            case 3:
                cout << "***Get area of chainline***" << endl;
                double area = l.area(c, m);
                cout << "Your area is :" << area << endl;
                break;

            case 4:
                cout << "***Get parameters of lemniskate in polar coordinates***" << endl;
                l.parametrs(c, m);
                break;

            case 5:
                cout << "***Get distance***" << endl;
                double dist = l.distance(l.c, l.m);
                cout <<"Your distnace is :" << dist << endl;
                break;

            case 6:
                cout << "***Get text form of chainline***" << endl;
                s* = l.frm();
                cout << "Text version of your chainline" << endl;
                cout << s << endl;
                break;

            default:
                cout << "You are wrong! Try again" << endl;
                break;
        }
    } while (h != 0);
    return 0;
}
