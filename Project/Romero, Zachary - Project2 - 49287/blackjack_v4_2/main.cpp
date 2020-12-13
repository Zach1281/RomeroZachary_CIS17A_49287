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
//i have realized that not everything needs to be object-oriented
    //despite my best efforts i'm still not quite at the level to understand how to make everything without just completely copying you
    //instead i am just going to implement as many concepts as i can not with the game logic but rather the betting system
    //i think i can flesh it out more and have it be nice, still unsure how to meet the 1000 line minimum
    // just trying to simulate the game at this point, just to see how it goes
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
    int nDeal = 1;
    cout << "Now we deal: " << endl;
    int *dealer = deal(tracker, cards, nDeal);
    int *player = deal(tracker, cards, nDeal);
    cout << "Dealer: " << endl;
    int dealTot = 0;
    int playTot = 0;
    int change = 0;
    
    cout << "Dealer has one face side down card." << endl;
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
            break;
        }
        else if(playTot == 21)
        {
            cout << "Player got blackjack" << endl;
            break;
        }
        else
        {
            try
            {
                cout << "Would you like to hit, double down, or stay?" << endl;
                cout << "To HIT: 'h' or 'H'" << endl;
                cout << "To DOUBLE DOWN: 'd' or 'D'" << endl;
                cout << "To STAY: 's' or 'S'" << endl;
                cin >> choice;
                if(choice == 'h' || choice == 'H')
                {
                    cout << "Player has hit" << endl;
                    player = deal(tracker,cards,nDeal);
                    cout << "Player has drawn a " << deck[player[0]]->face() << " of " << deck[player[0]]->suit() << endl;
                    playTot += static_cast<int>(deck[player[0]]->value());
                    cout << "Player Total: " << playTot << endl;
                }
                else if(choice == 'd' || choice == 'D')
                {
                    cout << "Player would like to double down." << endl;
                    cout << "Double bet and give one last card." << endl;
                    player = deal(tracker,cards,nDeal);
                    playTot += static_cast<int>(deck[player[0]]->value());
                    cout << "Player Total: " << playTot << endl;
                    //double the bet
                }
                else if(choice == 's' || choice == 'S')
                {
                    cout << "Player has chosen stay." << endl;
                    cout << "No more cards will be given, the dealer will now draw." << endl;
                }
                else
                {
                    throw "Invalid input, please try again.";
                }
            }
            catch(const char* exp)
            {
                cout << "You need to press: " << endl;
                cout << "To hit: 'h' or 'H'" << endl;
                cout << "To double down: 'd' or 'D'" << endl;
                cout << "To stay: 's' or 'S'" << endl;
                cout << exp << endl;
            }
        }
    }while(choice == 'h' || choice == 'H');
    while(dealTot < 17)
    {
        dealer = deal(tracker,cards,nDeal);
        cout << "The dealer drew a " << deck[dealer[0]]->face() << " of " << deck[dealer[0]]->suit() << endl;
        dealTot += static_cast<int>(deck[dealer[0]]->value());
        cout << "The dealer's hand total: " << dealTot << endl;
    }
    if(dealTot > 21)
    {
        cout << "Congratulations! The dealer has busted! Your bet will be matched!" << endl;
        //match bet
        //add bank
    }
    else if(playTot > dealTot)
    {
        cout << "Congratulations, your bet will be matched!" << endl;
        //this would be where the bet is matched
    }
    else if(playTot == dealTot)
    {
        cout << "That is a push." << endl;
        //display their bank
    }
    else
    {
        cout << "That's unfortunate, the dealer won. Your bet will taken." << endl;
        //subtract the bet
        //display the bank
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
    static int delt = 0;
    int *hand = new int[crdNHand];
    for(int i = 0; i < crdNHand; i++)
        hand[i] = tracker[delt++];
    return hand;
}

