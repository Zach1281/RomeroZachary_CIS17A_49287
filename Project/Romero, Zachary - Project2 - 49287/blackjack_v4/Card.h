#ifndef CARD_H
#define CARD_H
using namespace std;
/*
 * I think the biggest difference the versions will have is 
 * a more accurate simulation of the cards/deck
 * also implementing spltting and doubling-down
 * this will make it actual blackjack
 * not sure how to improve the UI
 * would need to implement GUIs for that to really be a thing but I have no idea how
 * I will try and take notes from your card and deck implementation and not copy too much
 */

class Card
{
private:
    char value;
    string face;
    char suit;    
public:
    Card()
    {char cValue = 0; char cSuit = 0;}
    Card(char, char);
    char suit();
    char face();
    char value();
    char getValue()
    { return value; }
};

#endif /* CARD_H */

