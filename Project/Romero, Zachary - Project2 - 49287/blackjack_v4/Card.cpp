#include "Card.h"

Card::Card(char value, char suit)
{
    this->value = value;
    this->suit = suit;
    face += value + suit;
}

Card::value()
{
    
}
