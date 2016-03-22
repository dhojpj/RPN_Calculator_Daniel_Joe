#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include "fraction.h"
#include "mixed.h"
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Parser.h"
#include "memory.h"

using std::cin;
using std::cout;

enum letters {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

class calculator
{
public:
    calculator();
    ~calculator();
    void commands();
    string trimBoth(string str);
        string replaceLetter(string str);

private:
    memory *m;
    Parser *p;
    string expression;
    //Parser *p;
    bool saved;
    bool isRunning;
    string extractFileName(string str);
    bool isSaved(string str);
    void exitCalculator();


};

#endif // CALCULATOR_H
