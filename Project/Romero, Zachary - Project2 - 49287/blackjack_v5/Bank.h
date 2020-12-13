#ifndef BANK_H
#define BANK_H
#include <iostream>
using namespace std;

class Bank {
private:
    int money;
    class NegativeMoney
    {};
    class EndGame
    {
    public:
        EndGame()
        {
            cout << "You have lost the game." << endl;
            cout << "You have either been here too long or bet too much." << endl;
        }
    };
public:
    Bank(int);
    void addBet(int);
    void subBet(int);
    void setMoney(int);
    int getMoney() const;
};

#endif /* BANK_H */

