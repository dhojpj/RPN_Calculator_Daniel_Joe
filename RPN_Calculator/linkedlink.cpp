#include "linkedlink.h"

linkedList::linkedList()
{
    qty = 0;
    maxQty = 50;
}


linkedList::~linkedList()
{
    qty = 0;
    maxQty = 0;
}

bool linkedList::empty()
{
  return !qty;
}

bool linkedList::full()
{
  return !(maxQty - qty);
}

unsigned int linkedList::size()
{
    return qty;
}

unsigned int linkedList::max_size()
{
    return maxQty;
}

void linkedList::insert(baseNode *whom)
{
    baseNode *ptr = anchor;
    qty++;
    for(; ptr->nextNode() && ptr->nextNode()->getFirst() < whom->getFirst(); ptr = ptr->nextNode());
    if(!ptr)
    {
        ptr->nextNode() = whom;
        return;
    }
    whom->nextNode() = ptr->nextNode();
    ptr->nextNode() = whom;
}

void linkedList::erase(void *whom)
{
    baseNode *ptr = anchor, *bye;
    for(; ptr->nextNode() && ptr->nextNode() < whom; ptr = ptr->nextNode());
    if(!ptr->nextNode() || ptr->nextNode()->getFirst() != whom)
        throw NOT_FOUND;
    bye = ptr->nextNode();
    ptr->nextNode() = bye->nextNode();
    delete bye;
    qty--;
}
