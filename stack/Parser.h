#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstring>
#include "Queue.h" // need to rewrite this to be void pointers
#include "Stack.h"


// use an array of functions = assign by funct[0] = &add(a,b), funct[1] = &sub(a,b), etc.


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class Parser
{
public:
    Parser();
    Parser(const Parser &p);
    ~Parser();

    Parser& operator=(const Parser &p);
    Parser& operator>>(Parser &p);
    Parser& operator<<(const Parser &p);

    friend istream& operator>>(istream &in, Parser &p);
    friend ostream& operator<<(ostream &out, const Parser &p);

private:
    char a[100];
    char *ptr;
//    Stack *s;
//    Queue *q;

    void copy(const Parser &p);
    void parse();
};


Parser::Parser()
{
    // initialize stack and queue <- need void pointers

}

Parser::Parser(const Parser &p)
{
    copy(p);
}

Parser::~Parser(){	}

Parser& Parser::operator=(const Parser &p)
{
    copy(p);
}

Parser& Parser::operator>>(Parser &p){	}
Parser& Parser::operator<<(const Parser &p){	}


void Parser::copy(const Parser &p)
{

}

// parses into tokens and pushes onto stack and queue
void Parser::parse()
{
    cout << "parsing\n";
    ptr = strtok(a, " ");

    int i = 1;
    while (ptr != NULL)
    {
        cout << i << "ptr = \"" << ptr << "\"" << endl;
        ptr = strtok(NULL, " ");

        ++i;
    }

    ptr = NULL;
}


istream& operator>>(istream &in, Parser &p)
{
    if(in == cin)
    {
        cout << "Enter: ";
        cin.getline(p.a, 100);
    }

    p.parse();
}

//++++++++++++++whole definition needs some work+++++++++++++++++++++++++++++++++++
ostream& operator<<(ostream &out, const Parser &p)
{
    //
    if (out == cout)
    {
        out << "array = " << p.a <<endl;
        out << "ptr = " << p.ptr << endl;
    }


}




#endif // PARSER_H
