#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

enum STACK_ERRORS {STACK_EMPTY, STACK_FULL, INVALID_MAXSIZE};

template<typename T>
class Stack
{
public:
    Stack(int maxSize = 10);
    virtual ~Stack();
    Stack(const Stack &other);
    Stack operator=(const Stack &other);

    bool empty();
    bool full();

    unsigned int size();
    unsigned int max_size();

    T pop();
    T peek();
    void resize(unsigned int s);

    Stack& operator<<(T d);
    Stack& operator>>(T& d);

    template<typename R>
    friend ostream& operator<<(ostream& out, const Stack<R> &s);

    template<typename R>
    friend istream& operator>>(istream& in, Stack<R> &s);

    // should be protected?
    void push(T data);
//    void erase(void *whom);

private:
    Node<T> *header;
    unsigned int qty, maxQty;

    void copy(const Stack &other);
    void nukem();
};

// CHECKED
template<typename T>
Stack<T>::Stack(int maxSize)
{
    qty = 0;
    maxQty = maxSize;
    header = NULL;
}

template<typename T>
Stack<T>::~Stack()
{
    nukem();
}

// CHECKED, works not for lhs pointer
template<typename T>
Stack<T>::Stack(const Stack &other)
{
    copy(other);
}

// CHECKED
template<typename T>
Stack<T> Stack<T>::operator=(const Stack<T> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

// CHECKED
template<typename T>
bool Stack<T>::empty()
{
    return !qty;
}

// CHECKED
template<typename T>
bool Stack<T>::full()
{
    return qty == maxQty;
}

// CHECKED
template<typename T>
unsigned int Stack<T>::size()
{
    return qty;
}

// CHECKED
template<typename T>
unsigned int Stack<T>::max_size()
{
    return maxQty;
}

// CHECKED
template<typename T>
void Stack<T>::push(T data)
{
    if(qty == maxQty)
            throw STACK_FULL;

        Node<T> *newNode = new Node<T> (data);


        //when it's empty
        if(!header)
        {
            header = newNode;
        }
        // when it's not empty add data to the tail
        else
        {
            //link the tail's next node to the newNode
            // set the newNode to be the last node in the list
            newNode->nextNode() = header;
            header = newNode;
        }
        ++qty;
}

// CHECKED
template<typename T>
T Stack<T>::peek()
{
    if(!header)
        throw STACK_EMPTY;

    // get data and move header to the next node
    T d = header->getData();

    return d;
}


// CHECKED
template<typename T>
T Stack<T>::pop()
{
    if(!header)
        throw STACK_EMPTY;

    // get data and move header to the next node
    T d = header->getData();

    Node<T> *temp = header;
    header = header->nextNode();

    // if the list is empty set header and tail to be empty
    if(!header)
        header = NULL;

    //pop and return
    delete temp;
    --qty;
    return d;
}

// CHECKED
template<typename T>
void Stack<T>::resize(unsigned int s)
{
    nukem();
    maxQty = s;
}


// CHECKED
template<typename T>
void Stack<T>::copy(const Stack &other)
{
    this->maxQty = other.maxQty;

    // increments automatically
    for(Node<T> *ptr = other.header; ptr; ptr = ptr->nextNode())
    {
        this->push(ptr->getData());
    }

}

//CHECKED
template<typename T>
void Stack<T>::nukem()
{
    for(Node<T> *ptr = header; ptr; ptr = header)
    {
        header = header->nextNode();
        ptr->setData(T());
        delete ptr;
    }

    qty = 0;
    maxQty = 0;
    header = NULL;
}


template<typename T>
Stack<T>& Stack<T>::operator<<(T d)
{
    this->push(d);

    return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator>>(T& d)
{
    d = this->peek();

    return *this;
}



//+++++++++FIX THE OUTPUT TO THE PREVIOUS //
// NEED FILE WRITE
template<typename R>
ostream& operator<<(ostream& out, const Stack<R> &s)
{
    Node<R> *ptr = s.header;

        for(; ptr; ptr = ptr->nextNode())
    //        out<<"Data: "<<ptr->getData()<<endl;
            out<< ptr << "    " << ptr->getData()<<endl;

    return out;
}

// need to handle strings
//==================NEED TO CHECK THIS================
// NEED FILE READ
template<typename R>
istream& operator>>(istream& in, Stack<R> &s)
{
    Node<R> newNode;

    if (in == cin)
    {
        cout <<"Data: ";
        in >> newNode;
        s << newNode.getData();
    }
    else // for file reading
    {
        while(in>>newNode)
            s << newNode.getData();
    }

    return in;
}

#endif // STACK_H
