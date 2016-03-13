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
    void enqueueToken(twin *tw);
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

    this->parse();
}


// check for int, double, fraction, mixed, and operators
// checks, then pushes with string,char*
string Parser::checkToken(char *t)
{
    twin *tw = new twin;
    string s_t; // don't really need this

    cout << "checking = \"" << t << "\"" << endl;


    if (ispunct(t[0]) && t[1] == '\0')
    {
        // need to create data and enqueue it
        string *s_d = new string;
        *s_d = (string)t;

        tw->s = typeid(string).name();
        tw->v = s_d;

        cout << "twin\t" << tw->s << "\t" << *(string*)tw->v << endl;



//        cout << "enqueued\t" << q->front()->s << "\t" << *(string*)(q->front()->v) << endl;

        cout << endl;
//        return s_t;
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
                cout << t << " is double\n";

                // check if fraction

                stringstream ss(t);
                double *d = new double;
                ss >> *d;
                tw->s = typeid(mixed).name();
                tw->v = d;

                cout << "twin = " << tw->s << "\t" << *(double*)tw->v << endl;

                return "";

//                return s_t;

            }
            else if (isdigit(t[i]) && t[i+1] == '/')
            {
                // check if fraction
                // checking if double
                cout << t << " is fraction \n";

// fraction needs to be separated by numerator and denominator
                // need to check parsing sequence for mixed number
                    // if mixed + mixed, then it's probably a mixed number?

                string fract(t);
                string fractNum = fract.substr(0,i+1);
                string fractDenom = fract.substr(i+2, fract.length());

                cout << "num = " << fractNum << endl;
                cout << "denom = " << fractDenom << endl;

//                stringstream ss(t);
//                double *d = new double;
//                ss >> *d;
                mixed *m = new mixed(0, atoi(fractNum.c_str()), atoi(fractDenom.c_str()));
                tw->s = typeid(mixed).name();
                tw->v = m;

                cout << "twin = " << tw->s << "\t" << *(mixed*)tw->v << endl;

                return "";



            }
            else if (!isdigit(t[i]))
            {
                isInt = false;
                cout << t << " is not an int\n";
            }

        }

        // if it traverse through through
        if (isInt)
        {
//            s_t = typeid(mixed).name();

            cout << t << " is an integer\n";

            int i = atoi(t);

//            cout << "i = " << i << endl;

            mixed *m = new mixed(i,0,1);

//            cout << "*m = " << *m << endl;

            tw->s = typeid(mixed).name();
            tw->v = m;

            cout << "twin = " << tw->s << "\t" << *(mixed*)tw->v << endl;

//            return s_t;
        }




    }


    q->enqueue(tw);


//    cout << *q << endl;
    return s_t;
}


void Parser::enqueueToken(twin *tw)
{
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

// parses into tokens and pushes onto stack and queue
void Parser::parse()
{
    cout << "parsing\n";
    char *ptr = strtok(a, " ");

    checkToken(ptr);

    while (ptr != NULL)
    {
        ptr = strtok(NULL, " ");
        checkToken(ptr);
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
//        out << "ptr = " << p.ptr << endl;
    }


}




#endif // PARSER_H
