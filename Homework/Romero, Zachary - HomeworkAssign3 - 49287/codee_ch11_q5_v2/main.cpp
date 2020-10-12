#include <iostream>
#include <string>
#include <iomanip>

struct WeatherStats
{
    std::string month;
    int totRain;      //inches total rainfall
    int highTemp;     //highest temp for month
    int lowTemp;      //lowest temp for month
    int avgTemp;      //average temp for month
};

const int SIZE = 12;

int main()
{
    WeatherStats array[SIZE];
    int sumTemp[SIZE];
    int accTemp{}, accRain{}, min{}, max{};
    std::string lowMon{}, highMon{};
    
    for(int i = 0; i < SIZE; i++)
    {
        std::cin.ignore();
        std::cin >> array[i].month;
        std::cin >> array[i].totRain;
        std::cin >> array[i].lowTemp;
        std::cin >> array[i].highTemp;
        array[i].avgTemp = (array[i].lowTemp + array[i].highTemp)/2;
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        accTemp += array[i].avgTemp;
        accRain += array[i].totRain;
    }
    
    accTemp = accTemp/SIZE;
    accRain = accRain/SIZE;
    min = array[0].lowTemp;
    max = array[0].highTemp;
    lowMon = array[0].month;
    highMon = array[0].month;
    
    for(int i = 0; i < SIZE; i++)
    {
        if(array[i].lowTemp < min)
        {
            min = array[i].lowTemp;
            lowMon = array[i].month;
        }
        if(array[i].highTemp > max)
        {
            max = array[i].highTemp;
            highMon = array[i].month;
        }
    }
    
    std::cout << "Average Rainfall " << accRain << std::endl;
    std::cout << "Lowest Temperature " << lowMon << "  " << min << " Degrees Fahrenheit" << std::endl;
    std::cout << "Highest Temperature " << highMon << "  " << max << " Degrees Fahrenheit" << std::endl;
    std::cout << " Average Temperature for the year " << accTemp << " Degrees Fahrenheit" << std::endl;
    
    return 0;
}