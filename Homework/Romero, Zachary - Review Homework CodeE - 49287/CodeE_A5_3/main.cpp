/* 
 * File:   main.cpp
 * Author: Zachary Romero
 * Created on DATE AND TIME HERE
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  sum(const int [],int);
int max(const int [], int);
int min(const int [], int);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn{},add{},high{},low{};
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    add = sum(array,sizeIn);
    high = max(array,sizeIn);
    low = min(array,sizeIn);
    //Output the sum, max and min
    
    
    //Print the results
    print(array,sizeIn,add,high,low);//print the array, sum, max and min

    //Exit
    return 0;
}

void read (int array[], int sizeIn)
{
    for (int i = 0; i < sizeIn; i++)
        cin >> array[i];
    for (int i = 0; i < sizeIn; i++)
        cout << "a[" << i << "] = " << array[i] << endl;
}

int sum (const int array[], int sizeIn)
{
    int total = 0;
    for (int i = 0; i < sizeIn; i++)
        total += array[i];
    return total;
}

int max (const int array[], int sizeIn)
{
    int max{};
    max = array[0];
    for (int i = 1; i < sizeIn; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int min (const int array[], int sizeIn)
{
    int min{};
    min = array[0];
    for (int i = 1; i < sizeIn; i++)
    {
        if(array[i] < min)
            min = array[i];
    }
    return min;
}

void print (const int array[], int sizeIn, int add, int high, int low)
{
    cout << "Min  = " << low << endl;
    cout << "Max  = " << high << endl;
    cout << "Sum  = " << add << endl;
}