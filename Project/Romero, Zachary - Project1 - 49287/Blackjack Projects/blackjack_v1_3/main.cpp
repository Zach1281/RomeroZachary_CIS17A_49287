#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int SIZE = 52;

void swap(int *, int *);
void shuffle(int [], int);
void display(int [], int);

int main()
{
    int Ace = 1;
    int J = 10;
    int Q = 10;
    int K = 10;
    int hand = 0;
    int dealer = 0;
    int counter = 4;
    
    int deck[52] = {Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};
    shuffle(deck, SIZE);
    for(int i = 0; i < 4; i++)
    {
        if(i % 2 == 0)
        {
            hand += deck[i];
            counter++;
        }
        else
        {
            dealer += deck[i];
            counter++;
        }
        if(i == 0 || i == 2)
        std::cout << "Your Hand: " << hand << std::endl;
        if(i == 1)
            std::cout << "Dealer's Hand: " << dealer << std::endl;
    }
    char choice;
    std::cout << "This is your hand: " << hand << std::endl;
    std::cout << "Do you wish to hit or to stay?(h/H)" << std::endl;
    std::cin >> choice;
    if((choice == 'h') || (choice == 'H'))
    {
        do
        {
            hand += deck[counter];                  //my thought process for this was to have the counter be the individual cards in the array
            counter++;
            std::cout << hand << std::endl;
            if(hand > 21)
            {
                std::cout << "You busted, better luck next time!" << std::endl;
                return 0;
            }
            std::cout << "Do you wish to hit or stay?(h/H)" << std::endl;
            std::cin >> choice;
            if(hand >= 17)
                std::cout << "I'm not sure that is the best course of action but okay." << std::endl;
        }while(choice == 'h' || choice == 'H');
    }
    else
        std::cout << "You have chosen to stay." << std::endl;
    std::cout << "This is your hand: " << hand << std::endl;        //this is to simulate the player looking at their hand
    std::cout << "This is the dealer's hand: " << dealer << std::endl;  //this is to simulate the dealer revealing the second card
    while(dealer < 17)                  //if the dealer has a hand less than 17 they must hit until they have 17 or more
    {
        dealer += deck[counter];
        counter++;
        std::cout << "Dealer's Hand: " << dealer << std::endl;
    }
    if(hand > dealer)
        std::cout << "Congratulations, your bet will be doubled!" << std::endl;
    else if(hand == dealer)
        std::cout << "That is a push." << std::endl;
    else
        std::cout << "That's unfortunate, the dealer won. Your bet will be taken." << std::endl;
    std::cout << "Thanks for playing!" << std::endl;
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
        std::cout << array[i] << " ";
    std::cout << std::endl;
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