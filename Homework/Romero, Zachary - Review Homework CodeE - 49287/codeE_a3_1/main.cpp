/* 
 * File:   main.cpp
 * Author: Zachary Romero
 * Purpose: Sort a 1 Dimensional Array
 * Created on September 9, 2020, 4:48 PM
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring>//strlen

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int read(char []);
void swap (char &, char &);
void selectionSort(char [], int);
void print (const char[], int);


int main()
{
    const int SIZE = 80;
    char array[SIZE] = {};
    int sizeIn{}, sizeDet{};
    
    
    std::cout << "Read in a 1 dimensional array of characters and sort" << std::endl;
    std::cout << "Input the array size where size <= 20" << std::endl;
    std::cin >> sizeIn;
    
    std::cout << "Now read in the array" << std::endl;
    
    sizeDet = read(array);
    
    if(sizeDet == sizeIn)
    {
        selectionSort(array,SIZE);
        print(array,SIZE);
    }
    else
    {
        std::cout << (sizeDet<sizeIn?"Input size less than specified.":
                  "Input size greater than specified.") << std::endl;
    }
        
    
    return 0;
}

int read(char array[])
{
    std::cin >> array;
    int length = strlen(array);
    return length;
}


void selectionSort (char array[], int SIZE)
{
     for (int startIndex{0}; startIndex < SIZE; ++startIndex)
    {
        int smallestIndex{startIndex};
        
        for (int currentIndex{startIndex + 1}; currentIndex < SIZE; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(array[startIndex], array[smallestIndex]);
    }
}

void swap (char &a, char &b)
{
    char temp{};
    temp = a;
    a = b; 
    b = temp;
}

void print(const char array[],int SIZE)
{
    for (int index{0}; index < SIZE; ++index)
        std::cout << array[index];
}
