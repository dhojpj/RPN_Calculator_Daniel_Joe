#ifndef PARSER_H
#define PARSER_H

// parses the string input using stacks and queues
// does the reverse polish notation, prints and returns the answer

#include <iostream>
#include <cstring>
#include "Queue.h"
#include "Stack.h"
#include "mixed.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class Parser
{
public:
    struct twin
    {
        bool b; // 0 is mixed, 1 is operator
        void* v;
    };

    typedef void (mixed::*MixedPtr)(const mixed&);
    typedef void (Parser::*ParserPtr)(Node<twin*>*);
    typedef void (Parser::*PEDMASPtr)();


    Parser();
//    Parser(const Parser &p);
    ~Parser();

    Parser& operator=(const Parser &p);
    Parser& operator>>(Parser &p);
    Parser& operator<<(const Parser &p);

    void getInput(std::string userInput);
    mixed getAnswer();
    void printRPNQueue();

    void RPN();
    void poppingStackParentheses();
    void poppingStackAll();

    friend istream& operator>>(istream &in, Parser &p);
    friend ostream& operator<<(ostream &out, const Parser &p);

private:
    char a[100]; // holds the c_string

    PEDMASPtr pedmas[100];
    ParserPtr pp[2]; // function pointers for the printing of the RPN queue
    MixedPtr mp[100]; // function pointers holds the operations -- seems excessive memory

    Stack<twin*> *s_numbers;
    Stack<twin*> *s_operators;
    Queue<twin*> *q;
    Queue<twin*> *q_temp;
    mixed answer;


    void twin_true(Node<twin*> *ptr);
    void twin_false(Node<twin*> *ptr);
    void createToken(char *t);
    void orderOfPrecedence(); // PEMDAS
    void copy(const Parser &p);
    void parse();
    void nukem();

    void enqMixed();
    void opSwap();
    void firstParanthesis();
    void secondParanthesis();
    void exponent();
    void md();
    void as();
};

 // PARSER_H
#endif
