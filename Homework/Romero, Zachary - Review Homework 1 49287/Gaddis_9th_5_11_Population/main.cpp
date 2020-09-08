/*
 * File: Gaddis_9th_5_11_Population
 * Author: Zachary Romero
 * Created on August 27, 2020, 11:38 AM
 */
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    const double e = 2.71828;       //P = Pnaught(e^(rt))
    int p_start{},days{};
    double r{}, p_total{}, rate_days{};
    
    do{
        std::cout << "Enter in the initial population (cannot be less than 2): " << std::endl;
        std::cin >> p_start;
    }while (p_start < 2);
    
    do{
        std::cout << "Enter the number of days you wish to calculate (cannot be less than 1): " << std::endl;
        std::cin >> days;
    }while (days < 1);
    
    do{
        std::cout << "Enter the percent rate of growth (cannot be a negative number): " << std::endl;
        std::cin >> r;
    }while (r < 0);
    
    rate_days = days * r;
    
    for(int x = 0; x <= days; x++)
    {
        p_total = p_start * pow(e,rate_days);
        std::cout << "Day " << x << ":" << p_total << std::endl;
    }
    
    return 0;
    
}