#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>
#include "basenode.h"

enum LINKEDLISTERRORS {NOT_FOUND};

class linkedList
{
    public:
        linkedList();
        virtual ~linkedList();

        bool empty();
        bool full();
        unsigned int size();
        unsigned int max_size();

    protected:
        baseNode *anchor;
        unsigned int qty, maxQty;

        void insert(baseNode *whom);
        void erase(void *whom);

    private:
};

#endif
