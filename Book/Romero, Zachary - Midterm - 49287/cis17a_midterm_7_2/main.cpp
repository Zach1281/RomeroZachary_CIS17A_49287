#include <iostream>
using namespace std;

struct Prime
{
    int prime;                       //the prime number itself
    int power;                        //how many times the number is saved after modding
};

struct Primes 
{
    int nPrimes;                      //this is the number of primes given the number
    Prime *prime;                     //this is the array of structs with the prime numbers
};

const int SIZE = 50;

Primes *factor(int);            //input integer, return all prime factors
void prntPrm(Primes *);         //output all prime factors

int main()
{   
    int num;
    int count = 0;
    int primes[SIZE]{};
    int powers[SIZE]{};
    int j = 1;
    primes[0] = 2;
    
    cout << "Enter a number between 2 and 10000: " << endl;
    do{
        cin >> num;
        if(num > 10000 || num < 2)
            cout << "Not in bounds, please enter a number between 2 and 10000: " << endl;
    }while(num > 10000 || num < 2);
    
    while(num % 2 == 0)
    {
        num /= 2;
        count++;
    }
    powers[0] = count;
    
    for(int i = 2; i <= num; i++)               //1 doesn't work, have to start at maybe 2?
    {
        while(num % i == 0)                     //save the number on i and repeat the mod until it doesn't = 0
        {                                       //with each counter that should be the power of the number                                       
            num /= i;                           //now i don't know how to get rid of the 4
            count++; 
        }
        if(i % 2 != 0)
        {
            while(j<10000)
            {
                primes[j] = i;
                powers[j] = count;
                j++;
                break;
            }
        }
        count = 0;
    }
    for(int i = 0; i < SIZE; i++)
    {
        if(primes[i] > 0)
            cout << primes[i] << '^' << powers[i] << '*';
    }
    cout << endl;
    return 0;
}

/*Primes *factors(int num)
{
    Primes factors;
    factors.prime->prime = 0;
    cout
}

void prntPrm(Primes *array)
{
    
}
*/