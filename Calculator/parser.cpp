
#include "parser.h"
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

Parser::Parser()
{
    s_numbers = new Stack<twin*>;
    s_operators = new Stack<twin*>;
    q = new Queue<twin*>;
    q_temp = new Queue<twin*>;

    pp[0] = &Parser::twin_false;
    pp[1] = &Parser::twin_true;
    mp['+'] = &mixed::add;
    mp['-'] = &mixed::subtract;
    mp['*'] = &mixed::multiply;
    mp['/'] = &mixed::divide;
    mp['^'] = &mixed::raiseTo;


    pedmas[0] = &Parser::enqMixed;
    pedmas[1] = &Parser::opSwap; // check its operator
    pedmas['('] = &Parser::firstParanthesis;
    pedmas[')'] = &Parser::secondParanthesis;
    pedmas['^'] = &Parser::exponent;
    pedmas['*'] = pedmas['/'] = &Parser::md;
    pedmas['+'] = pedmas['-'] = &Parser::as;

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


//sets up the order of precedence for the queue
void Parser::RPN()
{
    // the q_temp contains the algebraic expression
    while(!q_temp->empty())
    {

        this->orderOfPrecedence(); // proceed to the rest of the code
    }
    this->poppingStackAll(); // gets the last operator
}


void Parser::enqMixed()
{
    q->enqueue(q_temp->dequeue());
}

void Parser::opSwap()
{
    (this->*pedmas[(*(string*)q_temp->front()->v)[0]])();
}

void Parser::firstParanthesis()
{
    s_operators->push(q_temp->dequeue());
    orderOfPrecedence(); // recursive
//    break;
}

void Parser::secondParanthesis()
{
    q_temp->dequeue();
    this->poppingStackParentheses(); // pops stack until the (
}

void Parser::exponent()
{
    s_operators->push(q_temp->dequeue());
    q->enqueue(q_temp->dequeue());
    q->enqueue(s_operators->pop());
}

void Parser::md()
{
    // swap
    if (!s_operators->empty() &&
            (*(string*)s_operators->peek()->v == "*"
             || *(string*)s_operators->peek()->v == "/"))
    {
        q->enqueue(s_operators->pop());
    }

    s_operators->push(q_temp->dequeue());
}

void Parser::as()
{
    // needs to be a while loop otherwise errors
    while( !s_operators->empty() &&
          (*(string*)s_operators->peek()->v == "*" ||
           *(string*)s_operators->peek()->v == "/" ||
           *(string*)s_operators->peek()->v == "+" ||
           *(string*)s_operators->peek()->v == "-") )
    {
        q->enqueue(s_operators->pop());
    }
    s_operators->push(q_temp->dequeue());

}



// PEMDAS
void Parser::orderOfPrecedence()
{
    // it starts out with a number
    while(!q_temp->empty())
    {
        (this->*pedmas[q_temp->front()->b])();

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

}

void Parser::poppingStackAll()
{
    while(!s_operators->empty())
    {
        q->enqueue(s_operators->pop());
    }
}

void Parser::nukem()
{

    memset(a, 0, 100);

    q->clear();
    q_temp->clear();
    s_numbers->clear();
    s_operators->clear();
}

// first function called
void Parser::getInput(string userInput)
{
////    cout << "Expression: ";
////    cin.getline(a, 100);
//    string a = userInput;

//    if(string(a).size() == 0 ||
//            string(a) == "QUIT" || string(a)== "quit" ||
//            string(a) == "EXIT" || string(a) == "exit")
//    {
//        cout << endl;
//        exit(1);
//    }
    strcpy(a, userInput.c_str());

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

        tw->b = true;
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

                tw->b = false;

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

                // making a mixed number
                if (!q_temp->empty() && q_temp->back()->b == false)
                {
                    fraction f_temp;
                    f_temp.setValue(atoi(fractNum.c_str()), atoi(fractDenom.c_str()));

                    delete tw;
                    tw = NULL;

                    tw = q_temp->dequeue_behind();

                    (*(mixed*)tw->v) += f_temp;

                }
                else
                {
                    mixed *m = new mixed(0, atoi(fractNum.c_str()), atoi(fractDenom.c_str()));
                    tw->b = false;
                    tw->v = m;
                }

                isInt = false;
                done = true;

            }
        }
        // if it traversed through, then it's an integer
        if (isInt)
        {
            int i = atoi(t);

            mixed *m = new mixed(i,0,1);

            tw->b = false;
            tw->v = m;
        }

    }

    q_temp->enqueue(tw);

}

void Parser::printRPNQueue()
{
    Node<twin*> *ptr = q->getHead();

    for(; ptr; ptr = ptr->nextNode())
    {
//        cout << "printing\n";
        // calling a function pointer depending if it's bool false/true (i.e. mixed/operator)
        (this->*pp[ptr->getData()->b])(ptr);
    }

    cout << "\t";

    // printing in double
    if ((*(mixed*)s_numbers->peek()->v).get_denom() > 1)
    {
        cout << " = " << (double)(*(mixed*)s_numbers->peek()->v).get_num()
                /(double)(*(mixed*)s_numbers->peek()->v).get_denom();
    }

    cout << " = " << *(mixed*)s_numbers->pop()->v << endl; // insert stack answer
    answer = *(mixed*)s_numbers->pop()->v;
    cout << " = " << answer << endl; // insert stack answer
    this->nukem(); // to clear memory for the next set
}

void Parser::twin_false(Node<twin*> *ptr)
{
    cout << *(mixed*)ptr->getData()->v << " ";

    // push onto stack
    s_numbers->push((twin*)ptr->getData());
}

void Parser::twin_true(Node<twin*> *ptr)
{
    cout << (*(string*)ptr->getData()->v)[0] << " ";

    twin *temp2 = s_numbers->pop();
    twin *temp1 = s_numbers->pop();

    // call the function pointer
    ((*(mixed*)temp1->v).*mp[(*(string*)ptr->getData()->v)[0]])(*(mixed*)temp2->v);

    s_numbers->push(temp1);
}

istream& operator>>(istream &in, Parser &p)
{
    if(in == cin)
    {
        //p.getInput();
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

mixed Parser::getAnswer()
{
    return answer;
}
