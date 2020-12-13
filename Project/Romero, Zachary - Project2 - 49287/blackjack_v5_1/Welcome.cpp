#include "Welcome.h"
#include <iostream>
using namespace std;

//constructor that also instantiates the bank class
Welcome::Welcome(string)
{
    //this should be aggregation right???
    try
    {
        if(name.length() > 16)
            throw NameLength();
        else if(name == "Mark Lehr")
        {
            cout << "Welcome Dr. Lehr, I hope the casino is to your satisfaction!" << endl;
            this->name = name;
        }
        else
            this->name = name;
    }
    catch(NameLength e)
    {
        e.wrongName();
    }
}

void Welcome::setName(string)
{
    try
    {
        if(name.length() > 16)
            throw NameLength();
        else
            this->name = name;
    }
    catch(NameLength e)
    {
        e.wrongName();
    }
}

template <class T>
T Welcome::getName() const
{
    return name;
}
