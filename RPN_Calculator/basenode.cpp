#include "basenode.h"

baseNode::baseNode()
{
    first = next = NULL;
}

baseNode::~baseNode()
{
    first = next = NULL;
}

baseNode*& baseNode::nextNode()
{
    return next;
}

void* baseNode::getFirst() const
{
    return first;
}

void baseNode::setFirst(void *ptr)
{
    first = ptr;
}

baseNode& baseNode::operator=(const baseNode &other)
{
    return *this;
}

bool baseNode::operator<(const baseNode &x) const
{}

bool baseNode::operator<=(const baseNode &x) const
{}

bool baseNode::operator>(const baseNode &x) const
{}

bool baseNode::operator>=(const baseNode &x)const
{}

bool baseNode::operator==(const baseNode &x) const
{}

bool baseNode::operator!=(const baseNode &x) const
{}
