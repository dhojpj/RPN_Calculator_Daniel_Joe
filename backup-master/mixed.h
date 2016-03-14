#ifndef MIXED_H
#define MIXED_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

#include "fraction.h"

using namespace std;

class mixed : public fraction
{
    public:
        mixed(int w = 0, int n = 0, int d = 1);
        mixed(const fraction& x);
        mixed(long x);
        mixed(double x);
        mixed(const mixed &x);
        mixed(int x, const fraction &f);
        mixed& operator=(const mixed &other);
        mixed& operator=(int x);
        mixed& operator=(double x);
        mixed& operator=(const fraction &x);

        void add(const mixed &y);
        void minus(const mixed &y);
        void multiply(const mixed &y);
        void divide(const mixed &y);
        void power(const mixed &y);

        ~mixed();
        void value(int w = 0, int n = 0, int d = 1);
        void value(double x);
        void value(const fraction &x);
        friend
        ostream& operator<<(ostream& out, const mixed &number);

        friend
        istream& operator>>(istream& in, mixed &number);

//        friend mixed add(const mixed &x, const mixed &y);
//        friend mixed minus(const mixed &x, const mixed &y);
//        friend mixed multiply(const mixed &x, const mixed &y);
//        friend mixed divide(const mixed &x, const mixed &y);
//        friend mixed power(const mixed &x, const mixed &y);

    private:


};

#endif // MIXED_H
