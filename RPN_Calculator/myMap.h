#ifndef MYMAP_H
#define MYMAP_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "linkedlink.h"
#include "node.h"

template<typename K, typename V>
class myMap : public linkedList
{
    public:
        myMap(unsigned int size = 500)
        {
            maxQty = size;
            anchor = new baseNode;
        }
        ~myMap();
        myMap(const myMap<K,V> &other);
        myMap<K,V>& operator=(const myMap<K,V> &other);

        V& operator[](const K& index);
        const V& operator[](const K& index) const;
        void insert(const K& key, const V& value);
        void erase(const K& key);
        void clear();

        template<typename k, typename v>
        friend
        ostream& operator<<(ostream &out, const myMap<k,v> &other);

        template<typename k, typename v>
        friend
        istream& operator>>(istream &in, myMap<k,v> &other);

    private:

        void copy(const myMap<K,V> &other);
        void nukem();
        baseNode * find(const K& index);
};

template<typename K, typename V>
myMap<K,V>::~myMap()
{
    delete anchor;
    nukem();
}

template<typename K, typename V>
myMap<K,V>::myMap(const myMap<K,V> &other)
{
    copy(other);
}

template<typename K, typename V>
myMap<K,V>& myMap<K,V>::operator=(const myMap<K,V> &other)
{
    if(this != *other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

template<typename K, typename V>
baseNode* myMap<K,V>::find(const K& index)
{
    baseNode *ptr = anchor->nextNode();
    for(;ptr && *(K*)(ptr->getFirst()) != index; ptr = ptr->nextNode());
    if(!ptr)
        throw NOT_FOUND;
    return ptr;
}


template<typename K, typename V>
const V& myMap<K,V>::operator[](const K& index) const
{
   baseNode *ptr = find(index);
   if(!ptr)
       throw NOT_FOUND;
   return ((node<K,V>*)ptr)->theValue();
}

template<typename K, typename V>
V& myMap<K,V>::operator[](const K& index)
{
   V value;
   baseNode *ptr = find(index);
   if(!ptr)
       return value & insert(index,value);
   else
       return ((node<K,V>*)ptr)->theValue();

}

template<typename K, typename V>
void myMap<K,V>::insert(const K& key, const V& value)
{
    node<K,V> *ptr = new node<K,V>(key,value);
    insert(ptr);
}

template<typename K, typename V>
void myMap<K,V>::erase(const K& key)
{
    void *whom = &key; //HINT: Here is an "issue"
    erase(whom);

}

template<typename K, typename V>
void myMap<K,V>::clear()
{
    nukem();
}

template<typename K, typename V>
void myMap<K,V>::copy(const myMap<K,V> &other)
{
    baseNode *ptr = other.anchor.nextNode();
    for(; ptr; ptr = ptr->nextNode())
       insert(((node<K,V>*)ptr)->getFirst(),
              ((node<K,V>*)ptr)->theKey());
}

template<typename K, typename V>
void myMap<K,V>::nukem()
{
    baseNode *ptr = anchor, *bye;
    while(ptr->nextNode())
    {
        bye = ptr->nextNode();
        ptr = ptr->nextNode();
        delete bye;
    }
    anchor->nextNode() = NULL;
    qty = 0;
}

template<typename k, typename v>
ostream& operator<<(ostream &out, const myMap<k,v> &other)
{
    baseNode *ptr = other.anchor->nextNode();
    for(; ptr; ptr=ptr->nextNode())
        out<<*(node<k,v>*)ptr;
    return out;
}

template<typename k, typename v>
istream& operator>>(istream &in, myMap<k,v> &other)
{
   node<k,v> newNode;
   while(in>>newNode)
       insert(newNode.theKey(), newNode.theValue());
   return in;
}

#endif // MYMAP_H
