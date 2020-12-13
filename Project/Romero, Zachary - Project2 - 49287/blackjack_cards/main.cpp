#include <iostream>
#include <ctime>
#include "Card.h"
using namespace std;

void swap(int **, int **);
void shuffle(int *, int);
int *deal(int *, int ,int);
//so it took me a while to realize that i could just shuffle another array to shuffle the array of objects
//
int main()
{
    int cards = 52;
    int temp;
    int *tracker = new int[cards];

    Card **deck;
    
    deck = new Card*[cards];
    for(int i = 0; i < cards; i++)
    {
        deck[i] = new Card(i);
        tracker[i] = i;
    }
    /*cout << "Before: " << endl;
    for(int i = 0; i < cards; i++)
    {
        cout << "Counter: " << tracker[i] << ' ' << deck[tracker[i]]->face() << deck[tracker[i]]->suit() << ' ' << static_cast<int>(deck[tracker[i]]->value()) << endl;
    }*/
    shuffle(tracker, cards);
    /*cout << "After: " << endl;
    for(int i = 0; i < cards; i++)
    {
        cout << "Counter: " << tracker[i] << ' ' << deck[tracker[i]]->face() << deck[tracker[i]]->suit() << ' ' << static_cast<int>(deck[tracker[i]]->value()) << endl;
    }*/
    int nDeal = 2;
    cout << "Now we deal: " << endl;
    int *dealer = deal(tracker, cards, nDeal);
    int *player = deal(tracker, cards, nDeal);
    cout << "Dealer: " << endl;
    int dealTot = 0;
    int playTot = 0;
    int change = 0;
    for(int i = 0; i < nDeal; i++)
    {
        dealTot += static_cast<int>(deck[dealer[i]]->value());
        cout << dealer[i] << ' ' << deck[dealer[i]]->face() << deck[dealer[i]]->suit() << ' ' << static_cast<int>(deck[dealer[i]]->value()) << endl;
        if(dealTot == 21)
            cout << "BLACKJACK" << endl;
    }
    cout << "Player: " << endl;
    for(int i = 0; i < nDeal; i++)
    {
        playTot += static_cast<int>(deck[player[i]]->value());
        cout << player[i] << ' ' << deck[player[i]]->face() << deck[player[i]]->suit() << ' ' << static_cast<int>(deck[player[i]]->value()) << endl;
        if(playTot == 21)
            cout << "BLACKJACK" << endl;
        cout << "Total Value: " << playTot << endl;
    }
    for(int i = 0; i < cards; i++)
        delete deck[i];
    delete [] deck;
    delete [] tracker;
    delete [] player;
    delete [] dealer;
    
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int *tracker, int num)
{
    srand(static_cast<unsigned int>(time(0)));
    for(int i = num - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&tracker[i], &tracker[j]);
    }
}

int *deal(int *tracker, int num, int crdNHand)
{
    static char delt = 0;
    int *hand = new int[crdNHand];
    for(int i = 0; i < crdNHand; i++)
        hand[i] = tracker[delt++];
    return hand;
}

