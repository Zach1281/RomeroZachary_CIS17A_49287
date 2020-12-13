#ifndef WELCOME_H
#define WELCOME_H
#include "Bank.h"
#include <iostream>
using namespace std;

class Welcome {
private:
    string name;
    class NameLength
    {
    public:
        void wrongName()
        {
            cout << "Your username is too long." << endl;
            cout << "Needs to be less than 16 characters." << endl;
            cout << "Please try again." << endl;
        }
    };
public:
    Welcome(string);
    void setName(string);
    template <class T>
    T getName() const;
};

#endif /* WELCOME_H */

