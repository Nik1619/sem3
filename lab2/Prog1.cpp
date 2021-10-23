#include <strstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include "Prog1.h"

using namespace std;

namespace Prog2 {
    double equation(double a, double x, double e) {
            double y = a/2(e^(x/a) + e^(-x/a));
            cout << "a = " << y << endl;
        }
        else if (type(c, m) == 1) {
            double a22 = 2 * m * m + c;
            double b22 = 2 * m * m - c;
            cout << "a = " << a22 << endl;
            cout << "b = " << b22 << endl;
        }
    }


    char* chainline  {
            char* s1 = "y = a/2(e^(x/a) + e^(-x/a))\n";
            int l1 = strlen(s1) + 1;
            size_t Size = 20;
            char num[20];
            sprintf_s(num, 20, "%.2f", c);
            l1 += strlen(num);
            sprintf_s(num, 20, "%.2f", m);
            l1 += strlen(num);
            char* s1 = new char[l1];
            sprintf_s(s1, l1, "y = a/2(e^(x/a) + e^(-x/a))\n", c, c);
            int k = strlen(s1);
            sprintf_s(s1 + k, l1 - k, "y = a/2(e^(%.2f/a) + e^(-%.2f/a))\n", m, m);
            k = strlen(s1);
            return s1;
    }

    bool correct_get_int(int& a) noexcept {
    cin >> a;
    if (!cin.good()) {
    cin.clear();
    cin.ignore();
    return false;
}
return true;
}

bool correct_get_double(double& a) noexcept {
cin >> a;
if (!cin.good()) {
cin.clear();
cin.ignore();
return false;
}
return true;
}

int get_int() noexcept {
int num;
while (true) {
if (correct_get_int(num))
break;
cout << "Wrong number" << endl;
}
return num;
}

double get_double() noexcept {
double num;
while (true) {
if (correct_get_double(num))
break;
cout << "Wrong number" << endl;
}
return num;
}

int create(Buth_Lemn& l) {
    double c, m;

    cout << "Enter c" << endl;
    c = get_double();

    cout << "Enter m" << endl;
    m = get_double();

    try {
        l.setC(c);
    }
    catch (const char* msg) {
        cerr << msg << endl;
        return 1;
    }

    try {
        l.setM(m);
    }
    catch (const char* msg2) {
        cerr << msg2 << endl;
        return 1;
    }

    return 0;
}

int change_parameters(chainline& l) {
    int h;
    double c, m;
    do {
        cout << "0. Exit" << endl;
        cout << "1. Change c" << endl;
        cout << "2. Change m" << endl;
        h = get_int();
        switch (h) {
            case 0:
                cout << "***Exit***" << endl;
                break;

            case 1:
                cout << "***Change c***" << endl;
                c = get_double();
                try {
                    l.setC(c);
                }
                catch (const char* msg) {
                    cerr << msg << endl;
                    return 1;
                }
                break;

            case 2:
                cout << "***Change m***" << endl;
                m = get_double();
                try {
                    l.setM(m);
                }
                catch (const char* msg) {
                    cerr << msg << endl;
                    return 1;
                }
                break;

            default:
                cout << "You are wrong! Try again" << endl;
                break;
        }
    } while (h != 0);
    return 0;
}

}
