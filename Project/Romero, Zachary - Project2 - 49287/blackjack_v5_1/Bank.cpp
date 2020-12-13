#include "Bank.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Bank::Bank(int money)
{
    try
    {
        if(money < 0)
            throw NegativeMoney();
        else if(money < 100)
            throw NotEnoughMoney();
        else
            this->money = money;
    }
    catch(NegativeMoney e)
    {
        cout << "You need money to enter the blackjack game, sorry" << endl;
        exit(EXIT_FAILURE);
    }
    catch(NotEnoughMoney e)
    {
        e.exit();
        exit(EXIT_FAILURE);
    }
}

void Bank::setMoney(int money)
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
        cout << "You are going to have to leave the casino." << endl;
        exit(EXIT_FAILURE);
    }
}

int Bank::getMoney() const
{
    return money;
}

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

void Bank::chips()
{
    while(money >= 100)
    {
        black += 1;
        money -= 100;
        totChips++;
        if(black == 5)
            break;
    }
    while(money >= 50)
    {
        orange += 1;
        money -= 50;
        totChips++;
        if(orange == 10)
            break;
    }
    while(money >= 25)
    {
        green += 1;
        money -= 25;
        totChips++;
        if(green == 8)
            break;
    }
    while(money >= 20)
    {
        gray += 1;
        money -= 20;
        totChips++;
        if(gray == 10)
            break;
    }
    while(money >= 10)
    {
        blue += 1;
        money -= 10;
        totChips++;
        if(blue == 10)
            break;
    }
    while(money >= 5)
    {
        red += 1;
        money -= 5;
        totChips++;
        if(red == 5)
            break;
    }
    while(money >= 2)
    {
        yellow += 1;
        money -= 2;
        totChips++;
    }
    while(money >= 1)
    {
        white += 1;
        money -= 1;
        totChips++;
    }
}

void Bank::betting()
{
    int betBlack;
    int betOrange;
    int betGreen;
    int betGray;
    int betBlue;
    int betRed;
    int betYellow;
    int betWhite;
    if(black > 0)
    {
        do
        {
            cout << "Number of black chips($100):" << black << endl;
            cin >> betBlack;
            try
            {
                if(betBlack > black)
                    throw NotEnoughChips();
                if(betBlack < 0)
                    throw NegativeChips();
                else
                {
                    black -= betBlack;    
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betBlack > black || betBlack < 0);
    }
    if(orange > 0)
    {
        do
        {
            cout << "Number of orange chips($50):" << orange << endl;
            cin >> betOrange;
            try
            {
                if(betOrange > orange)
                    throw NotEnoughChips();
                if(betOrange < 0)
                    throw NegativeChips();
                else 
                {
                    orange -= betOrange;
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betOrange > orange || betOrange < 0);
    }
    if(green > 0)
    {
        do
        {
            cout << "Number of green chips($25):" << green << endl;
            cin >> betGreen;
            try
            {
                if(betGreen > green)
                    throw NotEnoughChips();
                if(betGreen < 0)
                    throw NegativeChips();
                else
                {
                    green -= betGreen;
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betGreen > green || betGreen < 0);
    }
    if(gray > 0)
    {
        do
        {
            cout << "Number of gray chips($20):" << gray << endl;
            cin >> betGray;
            try
            {
                if(betGray > gray)
                    throw NotEnoughChips();
                if(betGray < 0)
                    throw NegativeChips();
                else 
                {
                    gray -= betGray;
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betGray > gray || betGray < 0);
    }
    if(blue > 0)
    {
        do
        {
            cout << "Number of blue chips($15):" << blue << endl;
            cin >> betBlue;
            try
            {
                if(betBlue > blue)
                    throw NotEnoughChips();
                if(betBlue < 0)
                    throw NegativeChips();
                else
                {
                    blue -= betBlue;
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betBlue > blue || betBlue < 0);
    }
    if(red > 0)
    {
        do
        {
            cout << "Number of red chips($10):" << red << endl;
            cin >> betRed;
            try
            {
                if(betRed > red)
                    throw NotEnoughChips();
                if(betRed < 0)
                    throw NegativeChips();
                else
                {
                    red -= betRed;
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betRed > red || betRed < 0);
    }
    if(yellow > 0)
    {
        do
        {
            cout << "Number of yellow chips($5):" << yellow << endl;
            cin >> betYellow;
            try
            {
                if(betYellow > yellow)
                    throw NotEnoughChips();
                if(betYellow < 0)
                    throw NegativeChips();
                else
                {
                    yellow -= betYellow;
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betYellow > yellow || betYellow < 0);
    }
    if(white > 0)
    {
        do
        {
            cout << "Number of white chips($1):" << white << endl;
            cin >> betWhite;
            try
            {
                if(betWhite > white)
                    throw NotEnoughChips();
                if(betWhite < 0)
                    throw NegativeChips();
                else
                {
                    white -= betWhite;
                    break;
                }
            }
            catch(NotEnoughChips e)
            {
                e.retry();
            }
            catch(NegativeChips e)
            {
                e.retry();
            }
        }while(betWhite > white || betWhite < 0);
    }
}

int Bank::getBlack() const
{
    return black;
}

int Bank::getOrange() const
{
    return orange;
}

int Bank::getGreen() const
{
    return green;
}

int Bank::getGray() const
{
    return gray;
}

int Bank::getBlue() const
{
    return blue;
}

int Bank::getRed() const
{
    return red;
}

int Bank::getYellow() const
{
    return yellow;
}

int Bank::getWhite() const
{
    return white;
}

int Bank::getTotChips() const
{
    return totChips;
}



