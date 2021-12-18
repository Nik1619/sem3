#include <iostream>
#include "prog.h"

namespace prog {
    Line* input (int &rm) {
        int m;
        const char *err = "";
        Line *lines = nullptr;
        using std::cout;
        do {
            cout << err << std::endl;
            cout << "Enter the number of lines : " ;
            err = "You are wrong, try again!";
            if (getnum(m) < 0)
                return nullptr;
        } while (m < 1);

        try {
            lines = new Line [m];
        }
        catch (std::bad_alloc &ba) {
            cout << "To many lines" << ba.what() << std::endl;
            return nullptr;
        }
        for (int i = 0; i < m; ++i) {
            err = "";
            do {
                cout << err << std::endl;
                cout << "Enter the number of items in line" << std::endl;
                err = "You are wrong, try again!";
                if (getnum(lines[i].lot) < 0) {
                    erase(lines, i);
                    return nullptr;
                }
            } while (lines[i].lot < 1);
            try {
                lines[i].data = new double [lines[i].lot];
            }
            catch (std::bad_alloc &ba) {
                cout << "To many items" << ba.what() << std::endl;
                erase(lines, i);
                return nullptr;
            }
            cout << "Enter the elements of line : " << (i + 1) << std::endl;
            for (int j = 0; j < lines[i].lot; j++) {
                if (getnum(lines[i].data[j]) < 0) {
                    erase(lines, i + 1);
                    return nullptr;
                }
            }
        }
        rm = m;
        return lines;
    }

    void erase (Line *&lines, int m) {
        for (int i = 0; i < m; ++i)
            delete [] lines[i].data;
        delete [] lines;
    }

    void output (const char *msg, Line *lines, int m) {
        int i, j;
        std::cout << msg << std::endl;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < lines[i].lot; ++j)
                std::cout << lines[i].data[j] << "  ";
            std::cout << std::endl;
        }
    }

    void output (const char *msg, double *a, int m) {
        int i;
        std::cout << msg << std::endl;
        for (i = 0; i < m; ++i)
            std::cout << a[i] << "  ";
        std::cout << std::endl;
    }

    double findres(double *a, int m) { //sum -сумма эл-ов для нахождения среднего арифметического
        double s1 = 0, s2 = 0, sum = 0;
        int i, check;
        // критерий 1 - четные числа
        // критерий 2 - нечетные числа
        for (i = 0; i < m; ++i) {
            if ((static_cast<int>(a[i]) % 2) == 0)
                s1 = s1 + a[i];
            if ((static_cast<int>(a[i]) % 2) == 1)
                s2 = s2 + a[i];
            }
        return (s1 - s2);
    }
    int minmax (Line *lines, int m, double *&res) {
        try {
            res = new double [m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << ba.what() << std::endl;
            return 1;
        }
        int i;
        for (i = 0; i < m; ++i)
            res[i] = findres(lines[i].data, lines[i].lot);
        return 0;
    }
}
