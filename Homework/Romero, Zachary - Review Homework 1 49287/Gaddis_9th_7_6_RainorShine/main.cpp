/* 
 * File:   main.cpp
 * Author: Zachary Romero
 * Created on September 2, 2020, 10:40 AM
 * Purpose: Create a program that reads data from a file, using a two-dimensional array.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    const int SIZE = 5;
    int numbers [SIZE] = {10, 20, 30, 40, 50};
    
    for(int val : numbers)
        std::cout << val << std::endl;
}

