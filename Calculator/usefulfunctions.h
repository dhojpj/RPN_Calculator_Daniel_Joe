#ifndef USEFULFUNCTIONS
#define USEFULFUNCTIONS

#include <iostream>

std::string extractFileName(string str)
{
    return str.substr(str.find_first_of("<")+1,str.find_last_of(">") - str.find_first_of("<")-1);
}

#endif // USEFULFUNCTIONS

