#include "memory.h"
memory::memory()
{
    size = 30;
    mem = new mixed[size];
    clearPrivate();
}

memory::memory(unsigned int s)
{
    size = s;
    mem = new mixed[size];
    clearPrivate();
}



memory::~memory()
{
    size = 0;
    delete [] mem;
}

memory::memory(memory &other)
{

    copy(other);
}

//memory& memory::operator =(memory &other)
//{
//    if (this != &other)
//    {
//        clearPrivate();
//        copy(other);
//    }
//    return *this;
//}

memory& memory::operator=(const memory &other)
{
    if (this != &other)
    {
        clearPrivate();
        copy(other);
    }

    return *this;
}

void memory::clearMemory()
{
    clearPrivate();
}

void memory::clearMemoryPos(unsigned int pos)
{
    checkRange(pos);
    mem[pos] = mixed(0);
}

mixed memory::getMemory(unsigned int pos)
{
    checkRange(pos);
    return mem[pos];
}

void memory::setMemory(unsigned int pos, mixed data)
{
    checkRange(pos);
    mem[pos] = data;
}

void memory::clearPrivate()
{
    for(unsigned int i=0; i<size-1;i++)
    {
        mem[i] = mixed(0);
    }
}

void memory::checkRange(unsigned int pos)
{
    if(pos >size -1)
        throw INDEXOUTOFRANGE;
}

void memory::copy(const memory &other)
{

    size = other.size;
    for(unsigned i =0; i < size-1; i++)
    {
        mem[i] = other.mem[i];
    }
}


ostream& operator<<(ostream& out, const memory &m)
{
    for(unsigned int i=0; i<m.size;i++)
    {
        out<<m.mem[i];
    }
    return out;
}
