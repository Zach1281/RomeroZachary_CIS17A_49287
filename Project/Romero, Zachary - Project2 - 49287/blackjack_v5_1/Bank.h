#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Bank {
private:
    int money;
    int black;
    int orange;
    int green;
    int gray;
    int blue;
    int red;
    int yellow;
    int white;
    int totChips;
    class NegativeMoney
    {};
    class NotEnoughMoney
    {
    public:
        void exit()
        {
            cout << "You need to put in at least $100 to play the game." << endl;
            cout << "Please leave----->" << endl;
        }
    };
    class NotEnoughChips
    {
    public:
        void retry()
        {
            cout << "You need to enter in the correct amount of chips." << endl;
            cout << "Please retry the bet." << endl;
        }
    };
    class NegativeChips
    {
    public:
        void retry()
        {
            cout << "You need to enter the correct amount of chips." << endl;
        }
    };
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
    void betting();
    //mutators
    void chips();
    void addBet(int);
    void subBet(int);
    void setMoney(int);
    //accessors
    int getMoney() const;
    int getBlack() const;
    int getOrange() const;
    int getGreen() const;
    int getGray() const;
    int getBlue() const;
    int getRed() const;
    int getYellow() const;
    int getWhite() const;
    int getTotChips() const;
};

#endif /* BANK_H */

