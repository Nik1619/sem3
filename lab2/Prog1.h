#ifndef _Prog1_H_
#define _Prog1_H_
//#include "gtest/gtest_proud.h"
#include <math.h>

namespace Prog2 {
    class chainline {
    private:
        double c;
        double m;
    public:
        //setters
        void setC(double c) {
            this->c = c;
        }
        void setM(double c) {
            this->c = c;
        }
        //getters
        double getC() const { return c; };
        double getM() const { return m; };
        chainline(double c = 3, double m = 1);//конструктор
        double type() const;
        double parametrs() const;
        double area() const;
        double distance() const;
        char* frm() const;
        bool correct_get_int(int& a);
        bool correct_get_double(double& a) noexcept;
        int get_int() noexcept;
        double get_double() noexcept;
        int create(chainline l);
        int change_parameters(chainline l);
    };
}

#endif
