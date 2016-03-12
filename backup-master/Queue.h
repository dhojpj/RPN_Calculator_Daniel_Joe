#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
//#include <cstdlib>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include <string>
#include "Node.h"
// use void pointers?
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
//using std::string;

enum QUEUE_ERRORS {QUEUE_EMPTY, QUEUE_FULL, BAD_QUEUE_SIZE};

template<typename T>
class Queue
{
public:
    Queue(unsigned int s = 10);
    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator=(const Queue<T>& other);

    bool full();
    bool empty();

    void setMaxSize(unsigned int m);
    unsigned int getMaxSize() const;
    unsigned int getSize() const;
    std::string getType() const;
    void clear();
    void resize(unsigned int s);
    Queue<T>& operator<<(const T& data);
    Queue<T>& operator>>(T& data); // return a queue to chain it
    void enqueue(const T& data); // starting at the tail
    T dequeue();
    T front() const; // so can't change it and won't fire a copy constructor // how??
    T back() const;

    // friends for when two objects are interacting with each other
    template<typename R>
    friend ostream& operator<<(ostream& out, const Queue<R>& q);

    template<typename R>
    friend istream& operator>>(istream& in, Queue<R>& q);


private:
    Node<T> *head, *tail;

    unsigned int qty, max_qty;
    void copy(const Queue<T>& other);
    void nukem();
};

template<typename T>
Queue<T>::Queue(unsigned int s)
{
    qty = 0;
    max_qty = s;
    head = tail = NULL;
}

template<typename T>
Queue<T>::~Queue()
{
    nukem();
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    copy(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    copy(other);

    return *this;
}

template<typename T>
bool Queue<T>::full()
{
    return qty == max_qty;
}

template<typename T>
bool Queue<T>::empty()
{
    return !qty; // !0 means not false, which is true
}

template<typename T>
void Queue<T>::setMaxSize(unsigned int m)
{
    if (max_qty > m)
    {
        nukem();
    }

    max_qty = m;
}

template<typename T>
unsigned int Queue<T>::getMaxSize() const
{
    return max_qty;
}

template<typename T>
unsigned int Queue<T>::getSize() const
{
    return qty;
}


template<typename T>
std::string Queue<T>::getType() const
{
    return head->getType();
}

template<typename T>
void Queue<T>::clear()
{
    nukem();
}

template<typename T>
void Queue<T>::resize(unsigned int s)
{
    if (max_qty <= s)
    {
        max_qty = s;
    }
    else
    {
        nukem();
        max_qty = s;
    }
}

template<typename T>
Queue<T>& Queue<T>::operator<<(const T& data)
{
    this->enqueue(data);
    return this;
}

// how can this can't be a chain if we're not dequing?
template<typename T>
Queue<T>& Queue<T>::operator>>(T& data)
{
    data = this->front();
    return this;
}

// starting at the tail
// return a queue to chain it such as in the <<>> operators
template<typename T>
void Queue<T>::enqueue(const T& data)
{
    if(this->full())
    {
        throw QUEUE_FULL;
    }

    if(this->empty())
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T>* n = new Node<T>(data);
        tail->nextNode() = n;
        tail = n;
    }
    ++qty;
}

// starting at the head
template<typename T>
T Queue<T>::dequeue()
{
    if(this->empty())
    {
        throw QUEUE_EMPTY;
    }

    T d = head->getData();

    head = head->nextNode();

    --qty;

    return d;
}



template<typename T>
T Queue<T>::front() const
{
    T d = head->getData();
    return d;
} // so can't change it and won't fire a copy constructor // how??

template<typename T>
T Queue<T>::back() const
{
//    T d = tail->getData();
    return tail->getData();
} // so can't change it and won't fire a copy constructor // how??


template<typename T>
void Queue<T>::copy(const Queue<T>& other)
{
    if (&other != this)
    {
        nukem();
        this->setMaxSize(other.getMaxSize());

        Node<T> *ptr = other.head;

        for(;ptr;ptr = ptr->nextNode())
        {

            this->enqueue(ptr->getData());
        }
    }
    else
    {
        cout << "Cannot copy itself\n";
    }
}


template<typename T>
void Queue<T>::nukem()
{
    Node<T> *ptr = this->head;

    for(; ptr; ptr = ptr->nextNode())
    {
        head->setData(T());
    }

    head = tail = NULL;
    qty = max_qty = 0;
}


// friends for when two objects are interacting with each other
template<typename R>
ostream& operator<<(ostream& out, const Queue<R> &q)
{
    Node<R> *ptr = q.head;

    for(; ptr; ptr = ptr->nextNode())
    {
//        out << ptr->getData() << endl;
        out << ptr << "\t" << ptr->getData() << endl;
    }

    return out;
}


template<typename R>
istream& operator>>(istream& in, Queue<R>& q)
{

}






#endif // QUEUE_H
