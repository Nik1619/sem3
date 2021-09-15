
#include <iostream>
#include "Prog1.h"
namespace Prog1 {
    Line *input(int &rm) {
        const char *pr = "";
        Line *lines = nullptr;
        int m;
        do {
            std::cout << pr << std::endl;
            std::cout << "Enter number of lines: --> ";
            pr = "You are wrong; repeat please!";
            if (getNum(m) < 0)
                return nullptr;
        } while (m < 1);
        try {
            lines = new Line[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            return nullptr;
        }
        for (int i = 0; i < m; i++) {
            pr = "";
            do {
                std::cout << pr << std::endl;
                std::cout << "Enter number of items in line #" << (i + 1) << " --> ";
                pr = "You are wrong; repeat please!";
                if (getNum(lines[i].n) < 0) {
                    erase(lines, i);
                    return nullptr;
                }
            } while (lines[i].n < 1);
            try {
                lines[i].a = new double[lines[i].n];
            }
            catch (std::bad_alloc &ba) {
                std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
                erase(lines, i);
                return nullptr;
            }
            std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
            for (int j = 0; j < lines[i].n; j++) {
                if (getNum(lines[i].a[j]) < 0) {
                    erase(lines, i + 1);
                    return nullptr;
                }
            }
        }
        rm = m;
        return lines;
    }

    void output(const char *msg, Line *a, int m) {
        int i, j;
        std::cout << msg << ":\n";
        for (i = 0; i < m; ++i) {
            for (j = 0; j < a[i].n; ++j)
                std::cout << a[i].a[j] << " ";
            std::cout << std::endl;
        }
    }

    Line *erase(Line *&lines, int m) {
        int i;
        for (i = 0; i < m; i++)
            delete[] lines[i].a;
        delete[] lines;
        return nullptr;
    }

    int minmax(struct Line *a, int m) {
        double *b = nullptr;
        try {
            b = new double[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << ba.what() << std::endl;
            return 1;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < a[i].n; ++j) {
                if (a[i].a[j] > 10) {
                    b[i] = b[i] + a[i].a[j];
                } else {
                    b[i] = b[i] - a[i].a[j];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            std::cout << b[i] << " ";
            std::cout << std::endl;
        }
            delete[] b;
            return 0;

    }
}
