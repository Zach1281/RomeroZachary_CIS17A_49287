/* 
 * Author: Zachary Romero
 * Purpose: Blackjack Project Version 1
 * Created on October 15, 2020, 4:40 PM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
//i want to simulate a deck of cards
//i feel like an array writing to a binary file would work 
//maybe an enum with a dynamic array?
//i should have an outline with everything i should do before i start
/* Basic Blackjack Rules
 * 1.) Beat the dealer's hand without going over 21.
 * 2.) Face cards are worth 10. Aces are worth 1 or 11, which ever makes a better hand.
 * 3.) Each player starts with two cards, one of the dealer's cards is hidden until the end.
 * 4.) To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.
 * 5.) If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.
 * 6.) If you are dealt 21 from the start (Ace & 10), you got a blackjack.
 * 7.) Blackjack usually means you win 1.5 the amount of your bet. Depends on the casino.
 * 8.) Dealer will hit until their cards total 17 or higher.
 * 9.) Doubling is like a hit, the best is doubled and you only get one more card.
 * 10.) Split can be done when you have two of the same card - the pair is split into two hands.
 * 11.) Splitting also doubles the bet, because each new hand is worth the original bet.
 * 12.) You can only double/split on the first move, or first move of a hand created by a split.
 * 13.) You cannot play on two aces after they are split.
 * 14.) You can double on a hand resulting from a split, tripling, or quadrulping you bet.
 */

void swap(int *, int *);
void display(int [], int);
void shuffle(int [], int);

const int SIZE = 52;

int main()
{
    
    
    int deck[SIZE];             //creating a deck of 52 cards       
    for(int i = 0; i < SIZE; i++)
    {
        deck[i] = i;
        std::cout << deck[i] << " ";
    }
    std::cout << std::endl;
    
    shuffle(deck, SIZE);
    display(deck, SIZE);
    
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

//in total for this we have an array from 1 - 52 that randomly shuffles, good start i guess
//in terms of checking off the list i suppose it uses pointers for the swapping function