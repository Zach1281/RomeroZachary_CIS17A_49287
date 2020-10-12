#include <iostream>
#include <string>

struct WeatherStats
{
    char *month;  //i think i need to change this to a char array
    float totRain;      //inches total rainfall
    float highTemp;     //highest temp for month
    float lowTemp;      //lowest temp for month
    float avgTemp;      //average temp for month
};

const int SIZE = 12;

int main()
{
    WeatherStats array[SIZE];
    float accTemp{}, accRain{}, min{}, max{};
    char *lowMon = nullptr;
    char *highMon = nullptr;
    
    for(int i = 0; i < SIZE; i++)
    {
        array[i].month = new char[SIZE];
        std::cin.getline(array[i].month,SIZE-1);
        std::cin >> array[i].totRain;
        std::cin >> array[i].lowTemp;
        std::cin >> array[i].highTemp;
        array[i].avgTemp = (array[i].lowTemp + array[i].highTemp);
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        accTemp += array[i].avgTemp;
        accRain += array[i].totRain;
    }
    
    accTemp = accTemp/(SIZE*2);
    accRain = accRain/SIZE;
    min = array[0].lowTemp;
    max = array[0].highTemp;
    
    for(int i = 0; i < SIZE; i++)
    {
        if(array[i].lowTemp < min)
        {
            min = array[i].lowTemp;
            lowMon = new char[SIZE];
            lowMon = array[i].month;
        }
        if(array[i].highTemp > max)
        {
            max = array[i].highTemp;
            highMon = new char[SIZE];
            highMon = array[i].month;
        }
    }
    
    std::cout << "Average Rainfall " << accRain << std::endl;
    std::cout << "Lowest Temperature " << lowMon << "  " << min << " Degrees Fahrenheit" << std::endl;
    std::cout << "Highest Temperature " << highMon << "  " << max << " Degrees Fahrenheit" << std::endl;
    std::cout << "Average Temperature for the year " << accTemp << " Degrees Fahrenheit" << std::endl;
    
    delete [] lowMon;
    delete [] highMon;
    for(int i = 0; i < SIZE; i++)
    {
        delete [] array[i].month;
    }
    delete [] array;
    
    return 0;
}