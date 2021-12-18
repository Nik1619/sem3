#pragma once

namespace prog {
    struct Line {
        int lot;
        double *data;

    };

    template <typename T>

    int getnum (T &x) {
        std::cin >> x;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    inline int isbigger (double a, double b) {
        return a > b;
    }

    Line* input (int &rm);
    void erase (Line *&lines, int m);
    void output (const char *msg, Line *lines, int m);
    void output (const char *msg, double *a, int m);
    double findres(double *a, int m);
    int minmax (Line *lines, int m, double *&res);
};
