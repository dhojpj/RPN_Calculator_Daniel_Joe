#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <typeinfo.h>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::string;

template<typename T>
class Node
{
public:
    Node(T uData = T()); // constructor
    Node(const Node& other); // copy constructor
    Node& operator=(const Node& other); // assignment operator

    std::string getType() const;
    T getData( ) const;
    void setData(T value);
    Node*& nextNode(); // lhs and rhs
    void setNext(Node* nNode);

    Node& operator<<(T d);
    Node& operator>>(T& d);

    // const at the end prevents changes to *this
    bool operator<(const Node &x) const;
    bool operator<=(const Node &x) const;
    bool operator>(const Node &x) const;
    bool operator>=(const Node &x) const;
    bool operator==(const Node &x) const;
    bool operator!=(const Node &x) const;

    template<typename R>
    friend ostream& operator<<(ostream& out, const Node<R>& whom);

    template<typename R>
    friend istream& operator>>(istream& in, Node<R>& whom);

protected:
    string type;
    T data;
    Node* next; // link
private:
    void copy(const Node& other);

};

// constructor
template<typename T>
Node<T>::Node(T uData)
{
    //this->type = typeid(*(T*)uData).name();
    data = uData;
    next = NULL;
}


template<typename T>
string Node<T>::getType() const
{
    return type;
}

template<typename T>
T Node<T>::getData() const
{
    return data;
}

template<typename T>
void Node<T>::setData(T value)
{
    data = value;
}

template<typename T>
Node<T>*& Node<T>::nextNode()
{
    return next;
}

template<typename T>
void Node<T>::setNext(Node<T>* nextNode)
{
    next = nextNode;
}

template<typename T>
Node<T>::Node(const Node<T>& other)
{
    copy(other);
}

template<typename T>
Node<T>& Node<T>::operator = (const Node<T>& other)
{
    if(this != &other)
    {
        copy(other);
    }

    return this;
}

template<typename T>
void Node<T>::copy(const Node<T>& other)
{
    type = other.type;
    data = other.data;
    next = other.next;
}


template<typename T>
bool Node<T>::operator<(const Node<T> &x) const
{
    return data < x.data;
}

template<typename T>
bool Node<T>::operator<=(const Node<T> &x) const
{
    return data <= x.data;
}

template<typename T>
bool Node<T>::operator>(const Node<T> &x) const
{
    return data > x.data;
}

template<typename T>
bool Node<T>::operator>=(const Node<T> &x) const
{
    return data >= x.data;
}

template<typename T>
bool Node<T>::operator==(const Node<T> &x) const
{
    return data == x.data;
}

template<typename T>
bool Node<T>::operator!=(const Node<T> &x) const
{
    return data != x.data;
}

//need file write data ++++++++++++++++++++++++++++++++++++++++++++++++++
template<typename R>
ostream& operator<<(ostream& out, const Node<R>& whom)
{
    if (out == cout)
    {
        out << "Data: " << whom.getData();
    }
    else // writing to a file
    {

    }

    return out;
}

template<typename T>
Node<T>& Node<T>::operator<<(T d)
{
    this->data = d;

    return *this;
}

// this is more straightforward writing
// got rid of the menu; let the children take care of the file writing
//need file read data ++++++++++++++++++++++++++++++++++++++++++++++++++
template<typename R>
istream& operator>>(istream& in, Node<R>& whom)
{
    cout << "Node istream\n";
    in >> whom.data;

    return in;
}

template<typename T>
Node<T>& Node<T>::operator>>(T& d)
{
        cout << "Node ostream\n";
    d = this->data;

    return *this;
}


#endif // NODE_H
