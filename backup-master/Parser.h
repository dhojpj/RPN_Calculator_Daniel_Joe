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
    void printRPNQueue();
    void printTempQueue();

    void RPN();

    friend istream& operator>>(istream &in, Parser &p);
    friend ostream& operator<<(ostream &out, const Parser &p);

private:
    char a[100]; // holds the c_string

    Stack<twin*> *s_numbers;
    Stack<twin*> *s_operators;
    Queue<twin*> *q;
    Queue<twin*> *q_temp;

//    void checkToken(char *t); // checks token, and returns where to push them
    void createToken(char *t);

    void orderOfPrecedence(twin* tw);
    void copy(const Parser &p);
    void parse();
};


Parser::Parser()
{
    s_numbers = new Stack<twin*>;
    s_operators = new Stack<twin*>;
    q = new Queue<twin*>;
    q_temp = new Queue<twin*>;
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




void Parser::RPN()
{
//    if(this =='(')
//    {
//        while (next != ')')
//        {
//            // push and pop; order of operations
//            orderOfPrecedence(tw);

//        }
//    }
//    else
//    {
//        orderOfPrecedence(tw);
//    }
}

// also enqueues
void Parser::orderOfPrecedence(twin *tw)
{
    cout << "checking order\n";

    if(tw->s == typeid(string).name())
    {
//        cout << tw->s << endl;
//        if(tw->v) // if order of precedes, then pop and push
//            // also need my function pointer array
        s_operators->push(tw);
        // then enqueue
    }
    else if(tw->s == typeid(mixed*).name())
    {
//        cout << tw->s << endl;
        s_numbers->push(tw);
    }

//    q->enqueue(tw);
}


// print queue

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
        createToken(ptr); // callback function to check and enqueue tokens
        ptr = strtok(NULL, " ");
    }
}

// checks the type of data, and enqueues the struct twin into the queue (there is only 1 queue)
void Parser::createToken(char *t)
{
    twin *tw = new twin;

//    cout << "t = \"" << t << "\"" << endl;

    // checking for operation and/or letter memory
    if (ispunct(t[0]) && t[1] == '\0')
    {
        // need to create data and enqueue it
        string *s_d = new string;
        *s_d = (string)t;

        tw->s = typeid(string*).name();
        tw->v = s_d;

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
                double d;// = new double;
                ss >> d;

                tw->s = typeid(mixed*).name();

                mixed *m = new mixed;

                *m = d;

                tw->v = m;
            }
            else if (isdigit(t[i]) && t[i+1] == '/')
            {
                // check if fraction
                string fract(t);
                string fractNum = fract.substr(0,i+1);
                string fractDenom = fract.substr(i+2, fract.length());

                mixed *m = new mixed(0, atoi(fractNum.c_str()), atoi(fractDenom.c_str()));
                tw->s = typeid(mixed*).name();
                tw->v = m;

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

            tw->s = typeid(mixed*).name();
            tw->v = m;
        }

    }


    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//    if(tw->s == typeid(string*).name())
//    {
//        cout << "twin = " << tw->s << "\t\"" << *(string*)tw->v << "\"" << endl;
//    }
//    else if (tw->s == typeid(mixed*).name())
//    {
//        cout << "twin = " << tw->s << "\t\"" << *(mixed*)tw->v << "\"" << endl;
//    }

    // initially the temporary queue stores the expressio
    // and from there the calculations are done
    q_temp->enqueue(tw);
//    orderOfPrecedence(tw);
}


void Parser::printTempQueue()
{
    while(!q_temp->empty())
    {
        if(q_temp->front()->s == typeid(string*).name())
        {
            cout << (*(string*)q_temp->dequeue()->v)[0] << " ";
        }
        else if (q_temp->front()->s == typeid(mixed*).name())
        {
            cout << *(mixed*)q_temp->dequeue()->v << " ";
        }
    }
    cout << endl;
}

void Parser::printRPNQueue()
{
    while(!q->empty())
    {
        if(q->front()->s == typeid(string*).name())
        {
            cout << (*(string*)q->dequeue()->v)[0] << " ";
        }
        else if (q->front()->s == typeid(mixed*).name())
        {
            cout << *(mixed*)q->dequeue()->v << " ";
        }
    }

    // print stack's answer

    cout << "= " << endl; // insert stack answer
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
