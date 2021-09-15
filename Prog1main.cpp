#include <iostream>
#include "Prog1.h"
using namespace Prog1;

int main()
{
    Line *arr = nullptr;
    int m;
    double res;
    arr = input(m);
    if (!arr) {
        std::cout << "incorrect data" << std::endl;
        return 1;
    }
    output("Sourced matrix", arr, m);
    std::cout << std::endl;
    std::cout << "Result: " << minmax(arr, m) << std::endl;
    erase(arr, m);
    return 0;
}
