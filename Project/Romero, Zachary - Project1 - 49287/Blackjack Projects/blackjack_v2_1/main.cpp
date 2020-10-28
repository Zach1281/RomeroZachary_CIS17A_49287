#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Chips
{
    int black{};
    int orange{};
    int green{};
    int gray{};
    int blue{};
    int red{};
    int yellow{};
    int white{};
};

const int SIZE = 52;

void swap(int *, int *);
void shuffle(int [], int);
void display(int [], int);
void display(Chips *);
void money(Chips *);
Chips betting(Chips *);
void subtract(Chips *, Chips*);
void add(Chips *, Chips *);
Chips result(Chips *,Chips *);


int main()
{
    int Ace = 1;
    int J = 10;
    int Q = 10;
    int K = 10;
    int hand = 0;
    int dealer = 0;
    int counter = 4;
    int choice;
    Chips player1;
    Chips bet1;
    int deck[SIZE] = {Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};
    shuffle(deck, SIZE);
    money(&player1);
    bet1 = betting(&player1);
    
    for(int i = 0; i < 4; i++)
    {
        if(i % 2 == 0)
        {
            if(deck[i] == 1)
            {
                do{
                    cout << "Would you like your ace to be a 1 or 11?(1/11)" << endl;
                    cin >> choice;
                    if(choice != 11 || choice != 1)
                        cout << "The ace can only be a 1 or 11." << endl;
                }while(choice != 11 || choice != 1);
                if(choice == 11)
                    Ace = 11;
                else
                    Ace = 1;
            }
            hand += deck[i];
            counter++;
        }
        else
        {
            dealer += deck[i];
            counter++;
        }
        if(i == 0 || i == 2)
        cout << "Your Hand: " << hand << endl;
        if(i == 1)
            cout << "Dealer's Hand: " << deck[1] << endl;
    }
    char choice1;
    cout << "This is your hand: " << hand << endl;
    cout << "Do you wish to hit or to stay?(h/H)" << endl;
    cin >> choice;
    if((choice1 == 'h') || (choice1 == 'H'))
    {
        do
        {
            hand += deck[counter];                  //my thought process for this was to have the counter be the individual cards in the array
            counter++;
            cout << hand << endl;
            if(hand > 21)
            {
                cout << "You busted, better luck next time!" << endl;
                return 0;
            }
            cout << "Do you wish to hit or stay?(h/H)" << endl;
            cin >> choice1;
            if(hand >= 17)
                cout << "I'm not sure that is the best course of action but okay." << endl;
        }while(choice1 == 'h' || choice1 == 'H');
    }
    else
        cout << "You have chosen to stay." << endl;
    cout << "This is your hand: " << hand << endl;        //this is to simulate the player looking at their hand
    cout << "This is the dealer's hand: " << dealer << endl;  //this is to simulate the dealer revealing the second card
    while(dealer < 17)                  //if the dealer has a hand less than 17 they must hit until they have 17 or more
    {
        dealer += deck[counter];
        counter++;
        cout << "Dealer's Hand: " << dealer << endl;
    }
    if(hand > dealer)
    {
        cout << "Congratulations, your bet will be doubled!" << endl;
        add(&player1,&bet1);
        display(&player1);
    }
    else if(hand == dealer)
    {
        cout << "That is a push." << endl;
        display(&player1);
    }
    else
    {
        cout << "That's unfortunate, the dealer won. Your bet will be taken." << endl;
        subtract(&player1,&bet1);
        display(&player1);
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int array[], int num)
{
    for(int i = 0; i < num; i++)
        cout << array[i] << " ";
    cout << endl;
}

void shuffle(int array[], int num)
{
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    for(int i = num - 1; i > 0; i--)        //goes from the end of the array to the beginning
    {
        int j = rand() % (i + 1);           //j becomes a random element in the array from 0 to i
        swap(&array[i], &array[j]);         //this calls the swap function
    }
}

void money(Chips *player)
{
    int totChips{};                 //maybe make different colors different chips with different values
    int bet{};
    cout << "Welcome to the Blackjack Casino" << endl;
    cout << "You can play blackjack, blackjack or blackjack" << endl;
    cout << "We have different chips for you to buy: " << endl;
    cout << "Black  = $100" << endl;
    cout << "Orange = $50" << endl;
    cout << "Green  = $25" << endl;
    cout << "Gray   = $20" << endl;
    cout << "Blue   = $10" << endl;
    cout << "Red    = $5" << endl;
    cout << "Yellow = $2" << endl;
    cout << "White  = $1" << endl;
    cout << "How much money would you like to convert into gaming chips?" << endl;
    cin >> totChips;
    while(totChips >= 100)          //this section gives the amount of chips per category and stores them in the structure above
    {
        player->black += 1;
        totChips -= 100;
        if(player->black == 5)
            break;
    }
    while(totChips >= 50)
    {
        player->orange += 1;
        totChips -= 50;
        if(player->orange == 10)
            break;
    }
    while(totChips >= 25)
    {
        player->green += 1;
        totChips -= 25;
        if(player->green == 8)
            break;
    }
    while(totChips >= 20)
    {
        player->gray += 1;
        totChips -= 20;
        if(player->gray == 10)
            break;
    }
    while(totChips >= 10)
    {
        player->blue += 1;
        totChips -= 10;
        if(player->blue == 10)
            break;
    }
    while(totChips >= 5)
    {
        player->red += 1;
        totChips -= 5;
    }
    while(totChips >= 2)
    {
        player->yellow += 1;
        totChips -= 2;
    }
    while(totChips >= 1)
    {
        player->white += 1;
        totChips -= 1;
    }
    display(player);
}

Chips betting(Chips *player)                      //this function is going to take in the number of chips per type for each round of the game
{                                                           //it will also verify that the player has enough chips to bet 
    Chips bet;                                              //it will then subtract the amount from the player's struct    
    cout << "Place your bets by number of chip type: " << endl;
    if(player->black > 0)
    {
        do{
            cout << "Number of black chips($100): " << endl;
            cin >> bet.black;
            if(bet.black > player->black)
                cout << "You lack sufficient black chips to bet that much, enter the amount again." << endl;
            if(bet.black < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.black > player->black || bet.black < 0);
    }
    if(player->orange >0)
    {
        do{
            cout << "Number of orange chips($50): " << endl;
            cin >> bet.orange;
            if(bet.orange > player->orange)
                cout << "You lack sufficient orange chips to bet that much, enter the amount again." << endl;
            if(bet.orange < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.orange > player->orange || bet.orange < 0);
    }
    if(player->green > 0)
    {
        do{
            cout << "Number of green chips($25): " << endl;
            cin >> bet.green;
            if(bet.green > player->green)
                cout << "You lack sufficient green chips to bet that much, enter the amount again." << endl;
            if(bet.green < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.green > player->green || bet.green < 0);
    }
    if(player->gray > 0)
    {
        do{
            cout << "Number of gray chips($20): " << endl;
            cin >> bet.gray;
            if(bet.gray > player->gray)
                cout << "You lack sufficient gray chips to bet that much enter the amount again." << endl;
            if(bet.gray < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.gray > player->gray || bet.gray < 0);
    }
    if(player->blue > 0)
    {
        do{
            cout << "Number of blue chips($15): " << endl;
            cin >> bet.blue;
            if(bet.blue > player->blue)
                cout << "You lack sufficient blue chips to bet that much enter the amount again." << endl;
            if(bet.gray < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.blue > player->blue || bet.blue < 0);
    }
    if(player->red > 0)
    {
        do{
            cout << "Number of red chips($10): " << endl;
            cin >> bet.red;
            if(bet.red > player->red)
                cout << "You lack sufficient red chips to bet that much, enter the amount again." << endl;
            if(bet.red < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.red > player->red || bet.red < 0);
    }
    if(player->yellow > 0)
    {
        do{
            cout << "Number of yellow chips($5): " << endl;
            cin >> bet.yellow;
            if(bet.yellow > player->yellow)
                cout << "You lack sufficient yellow chips to bet that much, enter the amount again." << endl;
            if(bet.yellow < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.yellow > player->yellow || bet.yellow < 0);
    }
    if(player->white > 0)
    {
        do{
            cout << "Number of white chips($1): " << endl;
            cin >> bet.white;
            if(bet.white > player->white)
                cout << "You lack sufficient white chips to bet that much, enter the amount again." << endl;
            if(bet.white < 0)
                cout << "Negative value, try again." << endl;
        }while(bet.white > player->white || bet.white < 0);
    }
    //subtracting the betting amounts from the player struct
    return bet;
}

void subtract(Chips *player,Chips *bet)
{   
    if(bet->black != 0)
        player->black -= bet->black;
    if(bet->orange != 0)
        player->orange -= bet->orange;
    if(bet->green != 0)
        player->green -= bet->green;
    if(bet->gray != 0)
        player->gray -= bet->gray;
    if(bet->blue != 0)
        player->blue -= bet->blue;
    if(bet->red != 0)
        player->red -= bet->red;
    if(bet->yellow != 0)
        player->yellow -= bet->yellow;
    if(bet->white != 0)
        player->white -= bet->white;
}

void add(Chips *player,Chips *bet)
{
    if(bet->black != 0)
        player->black += bet->black;
    if(bet->orange != 0)
        player->orange += bet->orange;
    if(bet->green != 0)
        player->green += bet->green;
    if(bet->gray != 0)
        player->gray += bet->gray;
    if(bet->blue != 0)
        player->blue += bet->blue;
    if(bet->red != 0)
        player->blue += bet->blue;
    if(bet->yellow != 0)
        player->yellow += bet->yellow;
    if(bet->white != 0)
        player->white += bet->white;
}

void display(Chips *player)
{
    cout << "Here are your chips: " << endl;
    if(player->black != 0)
        cout << "Black: " << player->black << endl;
    if(player->orange != 0)
        cout << "Orange: " << player->orange << endl;
    if(player->green != 0)
        cout << "Green: " << player->green << endl;
    if(player->gray != 0)
        cout << "Gray: " << player->gray << endl;
    if(player->blue != 0)
        cout << "Blue: " << player->blue << endl;
    if(player->red != 0)
        cout << "Red: " << player->red << endl;
    if(player->yellow != 0)
        cout << "Yellow: " << player->yellow << endl;
    if(player->white != 0)
        cout << "White: " << player->white << endl;
}

