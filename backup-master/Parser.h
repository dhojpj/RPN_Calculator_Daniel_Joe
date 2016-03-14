#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstring>
#include "Queue.h"
#include "Stack.h"
#include "mixed.h"

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
    void checkToken(char* t); // checks token, and returns where to push them
    void enqueueTokens(char *t);
    void pushToken(twin *tw);


    friend istream& operator>>(istream &in, Parser &p);
    friend ostream& operator<<(ostream &out, const Parser &p);

private:
    char a[100]; // holds the c_string
//    char *ptr; // points to the respective tokens separated by space " "
    Stack<twin*> *s_numbers;
    Stack<twin*> *s_operators;
    Queue<twin*> *q;

    void copy(const Parser &p);
    void parse();
};


Parser::Parser()
{
    s_numbers = new Stack<twin*>;
    s_operators = new Stack<twin*>;
    q = new Queue<twin*>;
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

    if(string(a).size() == 0)
    {
        exit(0);
    }

    this->parse();
}

// parses into tokens and enqueues into queue
void Parser::parse()
{
    char *ptr = strtok(a, " ");

    while (ptr != NULL)
    {
        enqueueTokens(ptr); // callback function to check and enqueue tokens
        ptr = strtok(NULL, " ");
    }
}


// check for int, double, fraction, mixed, and operators
// checks, then pushes struct with string,char*
void Parser::checkToken(char *t)
{


}

// checks the type of data, and enqueues the struct twin into the queue (there is only 1 queue)
void Parser::enqueueTokens(char *t)
{
    twin *tw = new twin;

    // checking for operation and/or letter memory
    if (ispunct(t[0]) && t[1] == '\0')
    {
        // need to create data and enqueue it
        string *s_d = new string;
        *s_d = (string)t;

        tw->s = typeid(string).name();
        tw->v = s_d;

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        cout << "twin\t" << tw->s << "\t" << *(string*)tw->v << endl;

        cout << endl;
    }
    else // it's a number
    {
        bool isInt = true;
        for (unsigned int i = 0; t[i] != '\0'; ++i)
        {
            if (isdigit(t[i]) && t[i+1] == '.')
            {
                // checking if double
                stringstream ss(t);
                double *d = new double;
                ss >> *d;
                tw->s = typeid(mixed).name();
                tw->v = d;


                //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                cout << "twin = " << tw->s << "\t" << *(double*)tw->v << endl;

            }
            else if (isdigit(t[i]) && t[i+1] == '/')
            {
                // check if fraction
                string fract(t);
                string fractNum = fract.substr(0,i+1);
                string fractDenom = fract.substr(i+2, fract.length());

                cout << "num = " << fractNum << endl;
                cout << "denom = " << fractDenom << endl;

                mixed *m = new mixed(0, atoi(fractNum.c_str()), atoi(fractDenom.c_str()));
                tw->s = typeid(mixed).name();
                tw->v = m;

                //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                cout << "twin = " << tw->s << "\t" << *(mixed*)tw->v << endl;
            }
            else if (!isdigit(t[i]))
            {
                isInt = false;
            }

        }
        // if it traversed through, then it's an integer
        if (isInt)
        {
            int i = atoi(t);

            mixed *m = new mixed(i,0,1);

            tw->s = typeid(mixed).name();
            tw->v = m;

            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            cout << "twin = " << tw->s << "\t" << *(mixed*)tw->v << endl;

        }

    }

    q->enqueue(tw);
}

void Parser::pushToken(twin *tw)
{
    if(tw->s == typeid(string).name())
    {
        s_operators->push(tw);
    }
    else if(tw->s == typeid(mixed).name())
    {
        s_numbers->push(tw);
    }
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
//        out << "ptr = " << p.ptr << endl;
    }


}




#endif // PARSER_H
