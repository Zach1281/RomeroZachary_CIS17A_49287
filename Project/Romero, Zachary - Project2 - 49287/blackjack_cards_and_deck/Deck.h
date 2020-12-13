#ifndef DECK_H
#define DECK_H
#include "Card.h"
class Deck {
private:
    //attempting to import all of the important variables from main to make the deck class
    Card **card;
    int *tracker;
    int nDeal;
    int cards;
public:
    Deck();
    Deck(int);
    ~Deck()       //inline destructor
    {
        for(int i = 0; i < cards; i++)
            delete card[i];
        delete [] card;
        delete [] tracker;
    }
    void swap(int *, int *);
    void shuffle();
    int *deal(int);
};

#endif /* DECK_H */

