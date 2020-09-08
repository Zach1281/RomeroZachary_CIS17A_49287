/* 
 * File:   main.cpp
 * Author: Zachary Romero
 * 
 * Created on September 7, 2020, 5:14 PM
 */

#include <iostream>
#include <string>

void selectionSort(std::string[], int);
void swap (std::string &, std::string &);
int binarySearch(std::string[], int, std::string);

int main()
{
    const int NUM_NAMES = 20;
    int results{};
    std::string search_name{};
    std::string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty","Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy", 
                                "Pike, Gordon", "Holland, Beth"};
    
    selectionSort(names, NUM_NAMES);
    
    std::cout << "Enter the employee name you would like to find: (LastName, FirstName)" << std::endl;
    std::cin >> search_name;
    
    results = binarySearch(names, NUM_NAMES, search_name);
    
    std::cout << results << std::endl;
    
    if (results == -1)
        std::cout << "Element is not present.\n";
    else 
        std::cout << "Element is found at index " << results << std::endl;
 
    return 0;
}

void selectionSort (std::string names[], int num_names)
{
    int minIndex{};
    std::string minValue{};
    
    for(int start = 0; start < (num_names - 1); start++)
    {
        minIndex = start;
        minValue = names[start];
        for (int index = start + 1; index < num_names; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        swap(names[minIndex], names[start]);
    }
}

void swap (std::string &a, std::string &b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

int binarySearch(std::string names[], int num_names, std::string search_name)
{
    int first = 0,
        last = num_names - 1,
        middle,
        position = -1;
    bool found = false;
            
            
    
    while (!found && first <= last)
    {
        middle = (first + last) /2;
        if (names[middle] == search_name)
        {
            position = middle;
            found = true;
        }
        else if (names[middle] > search_name)
            last = middle - 1;
        else 
            first = middle + 1;
    }
    return position;
}
/*
 * I'm not sure why the binarySearch function is returning a -1 everything leads me to believe this is the way you should write this.
 */

