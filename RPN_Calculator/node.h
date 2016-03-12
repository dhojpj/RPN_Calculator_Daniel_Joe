#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "basenode.h"

using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::stringstream;
using std::string;
using std::getline;

template<typename KEY, typename VALUE>
class node : public baseNode
{
    public:
        node(KEY k = KEY(), VALUE v = VALUE());
        /*
         {
            first = new KEY(k);
            value = v;
         }
        */
        ~node()
        {
            delete (KEY*)getFirst();
            value = VALUE();
        }

        node(const node<KEY,VALUE> &other);
        node<KEY,VALUE>& operator=(const  baseNode &other);
        bool operator<(const   baseNode &x)  const;
        bool operator<=(const  baseNode &x)  const;
        bool operator>(const   baseNode &x)  const;
        bool operator>=(const  baseNode &x)  const;
        bool operator==(const  baseNode &x)  const;
        bool operator!=(const  baseNode &x)  const;

        inline VALUE& theValue()
        {
            return value;
        }

        inline KEY& theKey()
        {
            return *(KEY*)first;
        }

        template<typename T, typename U>
        friend
        ostream& operator<<(ostream& out, const node<T,U> &theNode);

        template<typename T, typename U>
        friend
        istream& operator>>(istream& in, node<T,U> &theNode);

    protected:

     private:
        VALUE value;

        void copy(const baseNode *other);

};

template<typename KEY, typename VALUE>
node<KEY,VALUE>::node(KEY k, VALUE v)
{

    setFirst(new KEY(k));
    value = v;
}

template<typename KEY, typename VALUE>
node<KEY,VALUE>::node(const node<KEY,VALUE> &other)
{
    copy(other);
}

template<typename KEY, typename VALUE>
void node<KEY,VALUE>::copy(const baseNode* other)
{
    value = ((node<KEY,VALUE>*)other)->value;
    *(KEY*)getFirst() = *(KEY*)(other->getFirst());
/*
    *static_cast<KEY*>(first) = *static_cast<KEY*>(other.getFirst());
*/
}

template<typename KEY, typename VALUE>
node<KEY,VALUE>& node<KEY,VALUE>::operator=(const baseNode &other)
{
    if(this != &other)
        copy(&other);
    return *this;
}

template<typename KEY, typename VALUE>
bool node<KEY,VALUE>::operator<(const  baseNode &x)  const
{
    return *(KEY*)getFirst() < *(KEY*)x.getFirst();
}

template<typename KEY, typename VALUE>
bool node<KEY,VALUE>::operator<=(const  baseNode &x) const
{
    return *(KEY*)getFirst() <= *(KEY*)x.getFirst();
}

template<typename KEY, typename VALUE>
bool node<KEY,VALUE>::operator>(const  baseNode &x)  const
{
    return *(KEY*)getFirst() > *(KEY*)x.getFirst();
}

template<typename KEY, typename VALUE>
bool node<KEY,VALUE>::operator>=(const  baseNode &x) const
{
    return *(KEY*)getFirst() >= *(KEY*)x.getFirst();
}

template<typename KEY, typename VALUE>
bool node<KEY,VALUE>::operator==(const  baseNode &x) const
{
    return *(KEY*)getFirst() == *(KEY*)x.getFirst();
}

template<typename KEY, typename VALUE>
bool node<KEY,VALUE>::operator!=(const  baseNode &x) const
{
    return *(KEY*)getFirst() != *(KEY*)x.getFirst();
}
\

template<typename T, typename U>
ostream& operator<<(ostream& out, const node<T,U> &theNode)
{
    if(out == cout)
        out<<"Key: "<<*(T*)theNode.first<<" Value: "<<theNode.value;
    else
        out<<"["<<*(T*)theNode.first<<" \007 "<<theNode.value<<"]";
    return out;
}

template<typename T, typename U>
istream& operator>>(istream& in, node<T,U> &theNode)
{
    if(!theNode.first)
        theNode.first = new T();
    if(in == cin)
    {
        cout<<"Key: ";
        in>>*(T*)theNode.first;
        cout<<"Value: ";
        in>>theNode.value;
     }
   else
   {
        stringstream ss;
        string line;
        getline(in,line,']');
        line.erase(0,1);
        line.erase(line.size()-1,1);
        getline(in,line,'\007');
        ss<<line;
        ss>>*(T*)theNode.first;
        ss.clear();
        getline(in,line);
        ss<<line;
        ss>>theNode.value;
    }
    return in;
}

#endif //NODE_H
