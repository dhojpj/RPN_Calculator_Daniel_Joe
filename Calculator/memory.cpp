#include "memory.h"
#include <iostream>
using namespace std;


memory::memory()
{
    size = 27;
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

bool memory::saveMemory(string fileName)
{
    try
    {
    ofstream ofile;
    ofile.open(fileName);
    ofile<<*this;
    ofile.close();
    return true;
    }
    catch(...)
    {
        return false;
    }
}

bool memory::readMemory(string fileName)
{
    ifstream inf;
    int n, d, w, spaceIndex, slashIndex, periodIndex, counter =0, sign = 1;
    double dou;
    string line, nstr, dstr, wstr;

    try
    {
        inf.open(fileName);
    }
    catch(...)
    {
        cout<<"can't not open file: "<< fileName<<endl;
        return false;
    }


    while(getline(inf,line))
    {
        spaceIndex = line.find_first_of(" ");
        slashIndex = line.find_first_of("/");
        periodIndex = line.find_first_of(".");

        if(spaceIndex != -1) // if there's a space in the string
        {
           //mixed fraction
           //get each part of the mixed fraction
           wstr =  line.substr(0,spaceIndex);
           nstr = line.substr(spaceIndex+1,slashIndex-spaceIndex-1);
           dstr = line.substr(slashIndex+1,line.length()-slashIndex);

           // convert each part to integer
           try
           {
               w = stoi(wstr);
               n = stoi(nstr);
               d = stoi(dstr);
           }
           catch(...)
           {
               cout<<"Error can't not load file to memory(mixed)"<<endl;
               return false;
           }

           //save it to memory
           mem[counter] = mixed(w,n,d);
        }
        else if(slashIndex != -1) // if there's a / in the string
        {
            nstr = line.substr(0,slashIndex);
            dstr = line.substr(slashIndex+1,line.length()-slashIndex);

            try
            {
                n = stoi(nstr);
                d = stoi(dstr);
            }
            catch(...)
            {
                cout<<"Error can't not load file to memory(fraction)"<<endl;
                return false;
            }

            mem[counter] = mixed(0,n,d);

        }
        else if(periodIndex != -1) // if there's a . in the string
        {
            //does not work with negative
            sign = (line.find_first_of("-") == -1)? 1:-1;
            //double
            try
            {
                dou = (stod(line)*(double)sign);

            }
            catch(...)
            {
                cout<<"Error can't not load file to memory(double)"<<endl;
                return false;
            }

            mem[counter]=mixed(dou);
        }
        else // for integer and failed conversion
        {
            try
            {
                n = stoi(line);
            }
            catch(...)
            {
                cout<<"Error can't not load file to memory(int)"<<endl;
                return false;
            }
            mem[counter] = mixed(n);
        }

        counter++;
    }

    inf.close();
    cout<<"memory loaded from: "<<fileName<<endl;
    return true;
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
    if(pos > size -1)
        throw INDEXOUTOFRANGE;
}

int memory::getSize()
{
    return size;
}

string memory::toString(unsigned int pos)
{
    stringstream ss;
    checkRange(pos);
    int n = mem[pos].get_num();
    int d = mem[pos].get_denom();

    if(n == 0)
    {
        ss << 0;
    }
    else if(d == 1)
    {
        ss<< n;
    }
    else
    {
        ss<<n<<"/"<<d;
    }
    string str = ss.str();
    ss.str("");
    ss.clear();
    return str;
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
    if(out == cout)
    {
        for(unsigned int i=0; i<m.size;i++)
        {
            out<<m.mem[i]<<" ";
        }
    }
    else
    {
        for(unsigned int i=0; i<m.size;i++)
        {
            out<<m.mem[i]<<"\n";
        }
    }
    return out;
}
