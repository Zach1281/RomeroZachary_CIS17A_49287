/*
 * File: Gaddis_9th_3_13_Currency
 * Author: Zachary Romero
 * Created on August 26, 2020, 12:00 PM
 */
#include <iostream>

int main()
{
    const double YEN_PER_DOLLAR{106.03},EUROS_PER_DOLLAR{0.85};
    char currency{};
    int USD{};
    double conversion{};
    
    std::cout << "This is a program that converts USD to YEN and EUROS.\n"
              << "Enter the amount of dollars in US currency.\n";
    std::cin >> USD;
    std::cout << "Please enter an 'e' for euro conversion and a 'y' for yen conversion.\n";
    std::cin >> currency;
    switch (currency)
    {
        case 'e':
        {
            conversion = USD * EUROS_PER_DOLLAR;
            std::cout << "USD: " << USD << " EUROS: " << conversion << std::endl;
        }
        break;
        case 'y':
        {
            conversion = USD * YEN_PER_DOLLAR;
            std::cout << "USD: " << USD << " YEN: " << conversion << std::endl;
        }
        break;
        default:
            std::cout << "End of program.\n";
    }
    return 0;
}