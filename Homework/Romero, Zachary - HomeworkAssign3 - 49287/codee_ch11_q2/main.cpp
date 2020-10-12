#include <iostream>
#include <string>

struct WeatherStats
{
    float totRain;      //inches total rainfall
    float highTemp;     //highest temp for month
    float lowTemp;      //lowest temp for month
    float avgTemp;      //average temp for month
};

enum months{JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE};

const int SIZE = 6;

int main()
{
    WeatherStats array[SIZE];
    float accTemp{}, accRain{}, min{}, max{};
    
    for(int i = 0; i < 6; i++)
    {
        std::cout << "Enter the total rainfall for the month:" << std::endl;
        std::cin >> array[i].totRain;
        std::cout << "Enter the high temp:" << std::endl;
        std::cin >> array[i].highTemp;
        std::cout << "Enter the low temp:" << std::endl;
        std::cin >> array[i].lowTemp;
        array[i].avgTemp = (array[i].lowTemp + array[i].highTemp)/2;
        
        accTemp += array[i].avgTemp;
        accRain += array[i].totRain;
    }
    
    accTemp = accTemp/SIZE;
    accRain = accRain/SIZE;
    min = array[0].lowTemp;
    max = array[0].highTemp;
    
    for(int i = 0; i < 6; i++)
    {
        if(array[i].lowTemp < min)
            min = array[i].lowTemp;
        if(array[i].highTemp > max)
            max = array[i].highTemp;
    }
    
    std::cout << "Average monthly rainfall:" << accRain << std::endl;
    std::cout << "High Temp:" << max << std::endl;
    std::cout << "Low Temp:" << min << std::endl;
    std::cout << "Average Temp:" << accTemp;
    
    return 0;
}