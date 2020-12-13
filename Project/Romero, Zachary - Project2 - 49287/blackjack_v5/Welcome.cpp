#include "Welcome.h"
#include <iostream>
using namespace std;

//constructor that also instantiates the bank class
Welcome::Welcome(string name, int money)
{
    //this should be aggregation right???
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
 
    cout << "Hello " << name << endl;
    cout << "Money will now be added to your account " << name << '.' << endl;
    Bank user(money);
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
