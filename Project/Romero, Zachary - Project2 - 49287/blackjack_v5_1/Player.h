#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "AbstractPlayer.h"
using namespace std;
//this player class should hold their name from the welcome screen and 
//how much money they have (maybe updated with each cycle of the game)
//would also like to implement functions to for win and loss
//the abstract player will also be the base class for the dealer
//polymorphic functions will be with win and loss for dealer and player (ideally)
class Player : public AbstractPlayer
{
public:
    virtual void win();
    virtual void loss();
};

#endif /* PLAYER_H */

