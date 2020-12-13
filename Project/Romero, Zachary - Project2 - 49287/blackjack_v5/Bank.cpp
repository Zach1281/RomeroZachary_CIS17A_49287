#include "Bank.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//constructor
Bank::Bank(int money)
{
    try
    {
        if(money < 0)
            throw NegativeMoney();
        else
            this->money = money;
    }
    catch(NegativeMoney e)
    {
        cout << "You need money to enter the blackjack game, sorry";
    }
    
}

//mutator
void Bank::setMoney(int money)
{
    try
    {
        if(money < 0)
            throw "You need money to enter the blackjack game, sorry.";
        else 
            this->money = money;
    }
    catch(NegativeMoney e)
    {
        cout << "You need money to enter the blackjack game, sorry.";
    }
}

//accessor
int Bank::getMoney() const
{
    return money;
}

//add the money amount after win
void Bank::addBet(int bet)
{
    try
    {
        if(bet < 0)
            throw NegativeMoney();
        else
            money += bet;
    }
    catch(NegativeMoney e)
    {
        cout << "Error: Invalid bet." << endl;
    }
}

//subtract the money after loss
void Bank::subBet(int bet)
{
    try
    {
        if(bet < 0)
            throw NegativeMoney();
        else money -= bet;
        try
        {
            if(money < 0)
                throw EndGame();
        }
        catch(EndGame e)
        {
            cout << "Invalid input." << endl;
        }
    }
    catch(NegativeMoney e)
    {
        cout << "Error: Invalid bet." << endl;
    }
}


