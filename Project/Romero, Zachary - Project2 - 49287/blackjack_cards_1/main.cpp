#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Card.h"
using namespace std;

void swap(int **, int **);
void shuffle(int *, int);
int *deal(int *, int ,int);
//so it took me a while to realize that i could just shuffle another array to shuffle the array of objects
/*
 * I think the biggest difference the versions will have is 
 * a more accurate simulation of the cards/deck
 * also implementing splitting and doubling-down
 * this will make it actual blackjack
 * not sure how to improve the UI
 * would need to implement GUIs for that to really be a thing but I have no idea how
 * I will try and take notes from your card and deck implementation and not copy too much
 */
int main()
{
    int cards = 52;
    int temp;
    int money = 100;
    int bet = 0;
    int *tracker = new int[cards];
    
    cout << "Everyone starts out with $100 dollars." << endl;
    cout << "How much would you like to bet?" << endl;
    cin >> bet;
    
    Card **deck;
    
    deck = new Card*[cards];
    for(int i = 0; i < cards; i++)
    {
        deck[i] = new Card(i);
        tracker[i] = i;
    }
    cout << "Before: " << endl;
    for(int i = 0; i < cards; i++)
    {
        cout << "Counter: " << tracker[i] << ' ' << deck[tracker[i]]->face() << deck[tracker[i]]->suit() << ' ' << static_cast<int>(deck[tracker[i]]->value()) << endl;
    }
    shuffle(tracker, cards);
    cout << "After: " << endl;
    for(int i = 0; i < cards; i++)
    {
        cout << "Counter: " << tracker[i] << ' ' << deck[tracker[i]]->face() << deck[tracker[i]]->suit() << ' ' << static_cast<int>(deck[tracker[i]]->value()) << endl;
    }
    int nDeal = 1;
    cout << "Now we deal: " << endl;
    int *dealer = deal(tracker, cards, nDeal);
    int *player = deal(tracker, cards, nDeal);
    cout << "Dealer: " << endl;
    int dealTot = 0;
    int playTot = 0;
    int change = 0;
    cout << "Dealer has one face side down card." << endl;// just trying to simulate the game at this point, just to see how it goes
    dealTot += static_cast<int>(deck[dealer[0]]->value());
    cout << "You have a " << deck[player[0]]->face() << " of " << deck[player[0]]->suit() <<  endl;
    playTot += static_cast<int>(deck[player[0]]->value());
    dealer = deal(tracker,cards,nDeal);
    cout << "The dealer has a " << deck[dealer[0]]->face() << " of " << deck[dealer[0]]->suit() << " with one facing down." << endl;
    dealTot += static_cast<int>(deck[dealer[0]]->value());
    player = deal(tracker,cards,nDeal);
    cout << "You now have a " << deck[player[0]]->face() << " of " << deck[player[0]]->suit() << endl;
    playTot += static_cast<int>(deck[player[0]]->value());
    cout << "Player Total: " << playTot << endl;
    cout << "Dealer Total: " << dealTot << endl;
    char choice = 0;
    do{
    if(playTot > 21)
    {
        cout << "Player has busted" << endl;
        exit(EXIT_FAILURE);
    }
    else if(playTot == 21)
    {
        cout << "Player got blackjack" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Would you like to hit?" << endl;
        cin >> choice;
        if(choice == 'h' || choice == 'H')
        {
            cout << "Player has hit" << endl;
            player = deal(tracker,cards,nDeal);
            cout << "Player has drawn a " << deck[player[0]]->face() << " of " << deck[player[0]]->suit() << endl;
            playTot += static_cast<int>(deck[player[0]]->value());
            cout << "Player Total: " << playTot << endl;
        }
    }
    }while(choice == 'h' || choice == 'H');
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
    static int delt = 0;
    cout << "DEALT: " << delt << endl;
    int *hand = new int[crdNHand];
    for(int i = 0; i < crdNHand; i++)
        hand[i] = tracker[delt++];
    return hand;
}

