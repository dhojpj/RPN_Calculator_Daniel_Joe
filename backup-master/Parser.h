#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstring>
#include "Queue.h"
#include "Stack.h"
#include "mixed.h"

// tokenize input
// label and insert into queue

// determine the RPN algorithm and insert into stacks and do operations

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
        string s;
        void* v;
    };

    Parser();
    Parser(const Parser &p);
    ~Parser();

    Parser& operator=(const Parser &p);
    Parser& operator>>(Parser &p);
    Parser& operator<<(const Parser &p);

    void getInput();
    string checkToken(char* t); // checks token, char by char, to determine its type and address
    void pushToken(string s, char *t);

    friend istream& operator>>(istream &in, Parser &p);
    friend ostream& operator<<(ostream &out, const Parser &p);

private:
    char a[100]; // holds the c_string
    char *ptr; // points to the respective tokens separated by space " "
    Stack<twin> *s_numbers;
    Stack<twin> *s_operators;
    Queue<twin> *q;

    void copy(const Parser &p);
    void parse();
};


Parser::Parser()
{
    s_numbers = new Stack<twin>;
    s_operators = new Stack<twin>;
    q = new Queue<twin>;
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






void Parser::getInput()
{
    cout << "Expression: ";
    cin.getline(a, 100);

    this->parse();
}


// check for int, double, fraction, mixed, and operators
// checks, then pushes with string,char*
string Parser::checkToken(char *t)
{
    cout << "checking = \"" << t << "\"" << endl;

    string s;

    if (ispunct(t[0]) && t[1] == '\0')
    {
        // need to create data and enqueue it

        s = typeid(char).name();
        cout << "s = " << s << endl;
        char c = t[0];

        cout << c << endl;
        return s;
    }

    else
    {
        bool isInt = true;
        for (unsigned int i = 0; t[i] != '\0'; ++i)
        {
            cout << "t[" << i << "] = " << t[i] << endl;

            if (isdigit(t[i]) && t[i+1] == '.')
            {
                // checking if double
                cout << "is double\n";

                // check if fraction
                s = typeid(mixed).name();

                return s;

            }
            else if (isdigit(t[i]) && t[i+1] == '/')
            {
                // check if fraction
                s = typeid(mixed).name();
                return s;
            }
            else if (!isdigit(t[i]))
            {
                isInt = false;
            }

        }

        // if it traverse through through
        if (isInt)
        {
            s = typeid(int).name();
            cout << "is an integer\n";

            return s;
        }




    }




    return s;
}

void Parser::pushToken(string s, char *t)
{
    if(s == typeid(char).name())
    {

    }
    else if(s == typeid(int).name())
    {

    }
}

// parses into tokens and pushes onto stack and queue
void Parser::parse()
{
    cout << "parsing\n";
    ptr = strtok(a, " ");

    while (ptr != NULL)
    {
        cout << "ptr = " << checkToken(ptr);
        ptr = strtok(NULL, " ");
    }

    ptr = NULL;
}


istream& operator>>(istream &in, Parser &p)
{
    if(in == cin)
    {
        p.getInput();
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
