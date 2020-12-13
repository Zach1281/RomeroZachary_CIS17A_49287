#include "Deck.h"
#include <ctime>
#include <cstdlib>
using namespace std;
Deck::Deck(int cards)
{
    this->cards = cards;
    tracker = new int[cards];
    card = new Card *[cards];
    for(int i = 0; i < cards; i++)
    {
        card[i] = new Card(i);
        tracker[i] = i;
    }
}

void Deck::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Deck::shuffle()
{
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i < cards; i++)
    {
        int j = rand() % (i + 1);
        swap(&tracker[i], &tracker[j]);
    }
}
//well in my version of dealing i only need to deal one card at a time
//i'm hoping i can change things a bit
int *Deck::deal(int nDeal)
{
    static char delt = 0;
    int *hand = new int[nDeal];
    for(int i = 0; i < nDeal; i++)
        hand[i] = tracker[delt++];
    return hand;
}
