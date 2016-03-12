#ifndef BASENODE_H
#define BASENODE_H

#include <cstdlib>

class baseNode
{
public:
    baseNode();
    virtual ~baseNode();
    virtual baseNode& operator=(const baseNode &other) ;

    virtual bool operator<(const baseNode &x) const ;
    virtual bool operator<=(const baseNode &x) const ;
    virtual bool operator>(const baseNode &x)const ;
    virtual bool operator>=(const baseNode &x)const ;
    virtual bool operator==(const baseNode &x) const ;
    virtual bool operator!=(const baseNode &x) const ;
    baseNode*& nextNode();
    void * getFirst() const;
    void setFirst(void *ptr);

protected:

private:
    void *first;
    baseNode *next;

};

#endif // BASENODE_H
