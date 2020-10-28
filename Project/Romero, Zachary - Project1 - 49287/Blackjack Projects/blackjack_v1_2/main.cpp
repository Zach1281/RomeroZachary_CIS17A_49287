#include <iostream>
#include <cstdlib>
#include <string>

const int SUIT = 4;
const int CARD = 13;
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
    
    int deck[52] = {Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
                    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};
    display(deck, SIZE);
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