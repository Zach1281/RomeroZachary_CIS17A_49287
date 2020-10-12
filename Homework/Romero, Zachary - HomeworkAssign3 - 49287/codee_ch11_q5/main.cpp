#include <iostream>
#include <string>

const int SIZE = 12;

int main()
{
    std::string months[SIZE];
    std::string highMon, lowMon;
    int totRain[SIZE], highTemp[SIZE], lowTemp[SIZE], sumTemp[SIZE];
    int sizeIn, avgTemp{}, avgRain{}, max{}, min{};
    
    std::cout << "Enter the amount of months(< 12): " << std::endl;
    std::cin >> sizeIn;
    
    for(int i = 0; i < sizeIn; i++)
    {
        std::cout << "Enter the month: " << std::endl;
        std::cin.ignore();
        getline(std::cin,months[i]);
        std::cout << "Enter the total rainfall for the month: " << std::endl;
        std::cin >> totRain[i];
        std::cout << "Enter the highest temp for the month: " << std::endl;
        std::cin >> highTemp[i];
        std::cout << "Enter the lowest temp for the month: " << std::endl;
        std::cin >> lowTemp[i];
        sumTemp[i] = (highTemp[i] + lowTemp[i]);
    }
    for(int i = 0; i < sizeIn; i++)
    {
        avgTemp += sumTemp[i];
        avgRain += totRain[i];
    }
    
    avgRain = avgRain/sizeIn;
    avgTemp = avgTemp/(sizeIn*2);
    lowMon = months[0];
    highMon = months[0];
    min = lowTemp[0];
    max = highTemp[0];
    
    for(int i = 0; i < sizeIn; i++)
    {
        if(lowTemp[i] < min)
        {
            min = lowTemp[i];
            lowMon = months[i];
        }
    }
    for(int i = 0; i < sizeIn; i++)
    {
        if(highTemp[i] > max)
        {
            max = highTemp[i];
            highMon = months[i];
        }
    }
    
    std::cout << "Average Rainfall " << avgRain << std::endl;
    std::cout << "Lowest Temperature " << lowMon << "  " << min << " Degrees Fahrenheit" << std::endl;
    std::cout << "Highest Temperature " << highMon << "  " << max << " Degrees Fahrenheit" << std::endl;
    std::cout << "Average Temperature for the year " << avgTemp << " Degrees Fahrenheit" << std::endl;
    return 0;
}