#include "Card.h"
//i don't want to be using much of your code
//i think i understand how it works though
Card::Card(char n)
{
    cardNum = n%52;
}
char Card::value()
{
    char n = cardNum%13;
    n++;
    if(n == 1)
        n = 11;
    return n>10?10:n;
}

char Card::face()
{
    char faces[] ={'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char n = cardNum%13;
    return faces[n%13];
}

char Card::suit()
{
    char suits[] = {'S', 'D', 'C', 'H'};
    char n = cardNum/13;
    return suits[n];
}