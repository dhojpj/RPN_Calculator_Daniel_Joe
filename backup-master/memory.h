#ifndef MEMORY_H
#define MEMORY_H
#include "mixed.h"
#include <iostream>

enum OUTOFRANGEERROR {INDEXOUTOFRANGE};
class memory
{
    public:
        memory();
        memory(unsigned int s);
        ~memory();
        memory(memory &other);
        memory& operator=(const memory &other);
        void clearMemory();
        void clearMemoryPos(unsigned int pos);
        mixed getMemory(unsigned int pos);
        void setMemory(unsigned int pos, mixed data);

        friend
        ostream& operator<<(ostream& out, const memory &m);

    private:
        mixed *mem;
        unsigned int size;
        void clearPrivate();
        void checkRange(unsigned int pos);
        void copy(const memory &other);

};

#endif // MEMORY_H
