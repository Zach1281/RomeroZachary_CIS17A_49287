/* 
 * File:   Gaddis_9th_4_10_DaysInAMonth
 * Author: Zachary Romero
 * Created on August 26, 2020, 1:34 PM
 */
#include <iostream>

int main()
{
    int month{},year{};                 /*leap year rules
                                         * the year must be divisible by 4
                                         * if the year can also be divided by 100, it is not a leap year unless
                                         * the year is also evenly divisible by 400
                                         */
    
    std::cout << "This is a program meant to determine days in a month given a month and year by the user.\n";
    std::cout << "Enter a month (1-12): ";
    std::cin >> month;
    std::cout << "Enter a year: ";
    std::cin >> year;
    
    if(month<=12 && month > 0)
    {
        if ((year%4==0) && (year%100!=0) || (year%400==0))
        {
            if ((month%2==0) && (month!=2))
                std::cout << "30 days" << std::endl;
            else if (month == 8)
                std::cout << "31 days" << std::endl;
            else if (month == 2)
                std::cout << "29 days" << std::endl;
            else
                std::cout << "31 days" << std::endl;
        }
        else
        {
            if((month%2==0) && (month!=2))
                std::cout << "30 days" << std::endl;
            else if (month == 8)
                std::cout << "31 days" <<std::endl;
            else if (month == 2)
                std::cout << "28 days" <<std::endl;
            else
                std::cout << "31 days" << std::endl;
        }
    }
    return 0;
}