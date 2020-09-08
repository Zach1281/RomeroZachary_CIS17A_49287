/* 
 * File:   Gaddis_9th_3_12_CelsiusToFahrenheit
 * Author: Zachary Romero
 * Created on August 26, 2020, 11:52 AM
 */
#include <iostream>

int main()
{
    double F{},C{};
    
    std::cout << "This is a program that converts Celsius to Fahrenheit.\n"
              << "What is the temperature in Celsius?\n";
    std::cin >> C;
    F = (1.8 * C) + 32;
    std::cout << "The temperature in Fahrenheit is: " << F << "." << std::endl;
}
