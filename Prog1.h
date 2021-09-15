//
// Created by Никита on 13.09.2021.
//

#ifndef UNTITL_PROG1_H
#define UNTITL_PROG1_H
namespace Prog1{
    struct Line{
        int n;
        double *a;
    };

    template <class T>
    int getNum(T &a)
    {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    Line* input(int &);
    void output(const char *msg, Line a[], int m);
    Line *erase(Line *&a, int m);
    int minmax(struct Line *a, int m);
}
#endif //UNTITL_PROG1_H
