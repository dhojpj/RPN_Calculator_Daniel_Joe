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

//typedef mixed(mixed::*functPtr)(mixed,mixed);
//typedef void(mixed::*functPtr)(const mixed&);



class Parser
{
public:

//    typedef mixed& (mixed::*functPtr)(mixed,mixed) const;

    typedef void (mixed::*functPtr)(const mixed&);

    struct twin
    {
        string s;
        void* v;
    };

    Parser();
//    Parser(const Parser &p);
    ~Parser();

    Parser& operator=(const Parser &p);
    Parser& operator>>(Parser &p);
    Parser& operator<<(const Parser &p);

    void getInput();
    void printRPNQueue();
    void printTempQueue();

    void RPN();
    void poppingStackParentheses();
    void poppingStackAll();


    void testRun();

    friend istream& operator>>(istream &in, Parser &p);
    friend ostream& operator<<(ostream &out, const Parser &p);

private:
    char a[100]; // holds the c_string
    functPtr fp[100]; // holds the operations

    Stack<twin*> *s_numbers;
    Stack<twin*> *s_operators;
    Queue<twin*> *q;
    Queue<twin*> *q_temp;




    void createToken(char *t);

    void orderOfPrecedence();
    void copy(const Parser &p);
    void parse();
};


Parser::Parser()
{
    s_numbers = new Stack<twin*>;
    s_operators = new Stack<twin*>;
    q = new Queue<twin*>;
    q_temp = new Queue<twin*>;
//    fp = new functPtr[100];

    fp['+'] = &mixed::add;
    fp['-'] = &mixed::subtract;
    fp['*'] = &mixed::multiply;
    fp['/'] = &mixed::divide;
    fp['^'] = &mixed::raiseTo;

}

//Parser::Parser(const Parser &p)
//{
//    copy(p);
//}

Parser::~Parser(){	}

//Parser& Parser::operator=(const Parser &p)
//{
//    copy(p);
//}

//Parser& Parser::operator>>(Parser &p){	}
//Parser& Parser::operator<<(const Parser &p){	}


//void Parser::copy(const Parser &p)
//{

//}


//sets up the order of precedence
void Parser::RPN()
{
    while(!q_temp->empty())
    {
        if(q_temp->front()->s == typeid(string*).name())
        {
            if (*(string*)q_temp->front()->v == "(")
            {
                s_operators->push(q_temp->dequeue());
            }

            this->orderOfPrecedence(); // proceed to the rest of the code
            this->poppingStackParentheses();
        }
        else
        {
            this->orderOfPrecedence();
        }

        this->poppingStackAll();
    }

}

// also enqueues
void Parser::orderOfPrecedence()
{
    // it starts out with a number
    while(!q_temp->empty())
    {
        // if it's an operator, do this
        if (q_temp->front()->s == typeid(string*).name())
        {
            if (*(string*)q_temp->front()->v == ")")
            {
                q_temp->dequeue();
                this->poppingStackParentheses(); // pops stack until the (

                // stop loop
                break;
            }
            else if(*(string*)q_temp->front()->v == "(")
            {
                RPN();
                break;
            }

            // order precedence
            if (*(string*)q_temp->front()->v == "^")
            {
                s_operators->push(q_temp->dequeue());
                q->enqueue(q_temp->dequeue());
                q->enqueue(s_operators->pop());

            }
            // if there's a +, and the stack is a *, then pop stack and enqueue, then push
            // otherwise push

            // this need to fix left to right+++++++++++++++++++++++++++++++++++++
            else if (*(string*)q_temp->front()->v == "+" || *(string*)q_temp->front()->v == "-")
            {
                // if stack not empty, compare
                if (!s_operators->empty())
                {
                    if(*(string*)s_operators->peek()->v == "*" || *(string*)s_operators->peek()->v == "/")
                    {
                        q->enqueue(s_operators->pop());
                    }
                }

                s_operators->push(q_temp->dequeue());
            }
            else
            {
                s_operators->push(q_temp->dequeue());
            }
        }
        else// if (q_temp->front()->s == typeid(mixed*).name())
        {
//            cout << "q_temp front = " << *(mixed*)q_temp->front()->v << endl;
            q->enqueue(q_temp->dequeue());

//            cout << "q tail = " << *(mixed*)q->back()->v << endl;
        }

    }

}

void Parser::poppingStackParentheses()
{

    while(!s_operators->empty())
    {
        if (*(string*)s_operators->peek()->v != "(")
        {
            q->enqueue(s_operators->pop());
        }
        else
        {
            s_operators->pop();
            break;
        }
    }

//    while (*(string*)s_operators->peek()->v != "(")
//    {
//        q->enqueue(s_operators->pop());
//    }

//    s_operators->pop();
}

void Parser::poppingStackAll()
{
    while(!s_operators->empty())
    {
//        cout << "pop all\t" << *(string*)s_operators->peek()->v << endl;
        q->enqueue(s_operators->pop());

    }
}

// first function called
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

// checks the type of data
//enqueues the struct twin into the temp queue to be read from
void Parser::createToken(char *t)
{
    twin *tw = new twin;

    // checking for operator that's a char (really a string because better to work with)
    if (ispunct(t[0]) && t[1] == '\0')
    {

        // need to create data and enqueue it
        string *s_d = new string;
        *s_d = (string)t;

//        tw = new twin;
        tw->s = typeid(string*).name();
        tw->v = s_d;



    }
    else // it's a number
    {
        bool isInt = true, done = false;
        for (unsigned int i = 0; t[i] != '\0' && !done; ++i)
        {
            // double
            if (isdigit(t[i]) && t[i+1] == '.')
            {
                stringstream ss(t);
                double d;// = new double;
                ss >> d;

//                tw = new twin;
                tw->s = typeid(mixed*).name();

                mixed *m = new mixed;

                *m = d;

                tw->v = m;

                isInt = false;
                done = true;
            }
            // fraction
            else if (isdigit(t[i]) && t[i+1] == '/')
            {
                // check if fraction
                string fract(t);
                string fractNum = fract.substr(0,i+1);
                string fractDenom = fract.substr(i+2, fract.length());

//                cout << "num = " << fractNum << "\tdenom = " << fractDenom << endl;

                // making a mixed number
                if (q_temp->back()->s == typeid(mixed*).name())
                {
//                    cout << "if whole #\n";// << q_temp->back()->s << "\n";
//                    cout << "q front 7= " << *(mixed*)q_temp->front()->v << endl;
                    fraction f_temp;
                    f_temp.setValue(atoi(fractNum.c_str()), atoi(fractDenom.c_str()));

                    delete tw;
                    tw = NULL;

                    tw = q_temp->dequeue_behind();

//                    cout << "temp deq'ed\n";
                    (*(mixed*)tw->v) += f_temp;
//                    cout << "mix incr'ed\n";

//                    cout << "mixed = " << *(mixed*)tw->v << endl;

                }
                else
                {
//                    cout << "just pure fract\n";

                    mixed *m = new mixed(0, atoi(fractNum.c_str()), atoi(fractDenom.c_str()));

//                    cout << "m = " << *m << endl;
//                    tw = new twin;
                    tw->s = typeid(mixed*).name();
                    tw->v = m;
                }

                isInt = false;
                done = true;

            }
            // otherwise nothing ?
//            else if (!isdigit(t[i]))
//            {
//                isInt = false;
//                done = true;
//            }
//            cout << "mixed = " << *(mixed*)q_temp->front()->v << endl;

        }
        // if it traversed through, then it's an integer
        if (isInt)
        {
//            cout << "int\n";
            int i = atoi(t);

            mixed *m = new mixed(i,0,1);

//            tw = new twin;
            tw->s = typeid(mixed*).name();
            tw->v = m;

//            cout << "mixed = " << *(mixed*)q_temp->front()->v << endl;
        }

    }


//    cout << "before enq\t";
    q_temp->enqueue(tw);

//    if (tw->s == typeid(string*).name())
//    {
//        cout << "post enq'ed = " << *(string*)q_temp->back()->v << endl;
//    }
//    else
//        cout << "post enq'ed = " << *(mixed*)q_temp->back()->v << endl;




//    cout << "temp queueue = ";
//    this->printTempQueue();
}


void Parser::printTempQueue()
{
    cout << "printing temp q\t";
    Node<twin*> *ptr = q_temp->getHead();

    for(; ptr; ptr = ptr->nextNode())
    {
        if (ptr->getData()->s == typeid(mixed*).name())
        {
            cout << *(mixed*)ptr->getData()->v << " ";

        }
        else if(ptr->getData()->s == typeid(string*).name())
        {
            cout << (*(string*)ptr->getData()->v)[0] << " ";
        }


    }

//    cout << "printing temp queue\n";
//    while(!q_temp->empty())
//    {
//        if(q_temp->front()->s == typeid(string*).name())
//        {
//            cout << (*(string*)q_temp->dequeue()->v)[0] << " ";
//        }
//        else if (q_temp->front()->s == typeid(mixed*).name())
//        {
//            cout << *(mixed*)q_temp->dequeue()->v << " ";
//        }
//    }
//    cout << endl;
}

void Parser::printRPNQueue()
{





/*    while(!q->empty())
    {
        if(q->front()->s == typeid(string*).name())
        {
            cout << (*(string*)q->dequeue()->v)[0] << " ";
//            cout << (*(string*)q->front()->v)[0] << " ";
//            twin *tw_temp = s_numbers->pop(); // to store it
//            (*(mixed*)s_numbers->pop()->v).(fp[(*(string*)q->dequeue()->v)[0]](*(mixed*)tw_temp->v));
//                    << " ";
        }
        else if (q->front()->s == typeid(mixed*).name())
        {
            cout << *(mixed*)q->dequeue()->v << " ";
        }
    }

    // print stack's answer

    cout << "= " << endl; // insert stack answer
*/
//    cout << "before\n";


    /* get the function pointers working

      -first make sure it's being called and popped
      - switch to bools afterward

    */

//    cout << "printing Q\n";
    Node<twin*> *ptr = q->getHead();

    for(; ptr; ptr = ptr->nextNode())
    {
        if (ptr->getData()->s == typeid(mixed*).name())
        {
            cout << *(mixed*)ptr->getData()->v << " ";

            // push onto stack
            s_numbers->push((twin*)ptr->getData());
        }
        else// if(ptr->getData()->s == typeid(string*).name())
        {
            cout << (*(string*)ptr->getData()->v)[0] << " ";

            twin *temp2 = s_numbers->pop();
            twin *temp1 = s_numbers->pop();

//            cout << "\ntemp1 = " << *(mixed*)temp1->v << endl;
//            cout << "temp2 = " << *(mixed*)temp2->v << endl;
                                    // call the function pointer
            ((*(mixed*)temp1->v).*fp[(*(string*)ptr->getData()->v)[0]])(*(mixed*)temp2->v);

//                        cout << "temp1(2) = " << *(mixed*)temp1->v << endl;
            s_numbers->push(temp1);

        }


    }

    cout << "\t";

    // printing in double
    if ((*(mixed*)s_numbers->peek()->v).get_denom() > 1)
    {
        cout << " = " << (double)(*(mixed*)s_numbers->peek()->v).get_num()
                /(double)(*(mixed*)s_numbers->peek()->v).get_denom();
    }

    cout << " = " << *(mixed*)s_numbers->pop()->v << endl; // insert stack answer


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

void Parser::testRun()
{

}


#endif // PARSER_H
