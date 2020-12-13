#include <iostream>
#include "Deck.h"
using namespace std;

int main()
{
    int cards = 52;
    Deck deck(cards);
    
    deck.shuffle();
    int nDeal = 1;
    int zero = 0;
    int *player0;
    int *player1;
    int playTot, dealTot;
    player0 = deck.deal(nDeal);
    player1 = deck.deal(nDeal);
    Card dealer(player0[zero]);
    Card player(player1[zero]);
    cout << "Dealer: " << dealer.face() << " of " << dealer.suit() << " with a value of " << static_cast<int>(dealer.value()) << endl;
    cout << "You get your first card, it is a " << player.face() << " of " << player.suit() << " with a value of " << static_cast<int>(player.value()) << endl;
    dealer(player0[1]);
    cout << "Dealer: " << dealer.face() << " of " << dealer.suit() << " with a value of " << static_cast<int>(dealer.value()) << endl;
    
    delete [] player0;
    delete [] player1;
    
    return 0;
}