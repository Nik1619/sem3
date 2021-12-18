#include <iostream>
#include "prog.h"

using namespace prog;

int main () {
    Line *arr = nullptr;
    int m;
    double *res = nullptr;
    arr = input(m);
    if (!arr) {
        std::cout << "Incorrect data" << std::endl;
        erase(arr, m);
        return 1;
    }
    if(minmax(arr, m, res)) {
        std::cout << "Error allocate" << std::endl;
        erase(arr, m);
        return 1;
    }
    output("Sourced matrix : ", arr, m);
    output("Sourced vector : ", res, m);
    erase(arr, m);
    delete [] res;
    return 0;
}
