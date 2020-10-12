#include <iostream>
#include <iomanip>

struct DivName
{
    float fqs;    //first quarter sales
    float sqs;    //second quarter sales
    float tqs;    //third quarter sales
    float fourqs;    //fourth quarter sales
    float tas;    //total annual sales
    float aqs;    //average quarterly sales
};

//function prototypes
void getData(DivName&);

int main()
{
    DivName north;
    DivName south;
    DivName east;
    DivName west;
    std::cout << "North" << std::endl;
    getData(north);
    std::cout << "\nWest" << std::endl;
    getData(west);
    std::cout << "\nEast" << std::endl;
    getData(east);
    std::cout << "\nSouth" << std::endl;
    getData(south);
    
    return 0;
}

void getData(DivName &sales)
{
    std::cout << "Enter first-quarter sales:" << std::endl;
    std::cin >> sales.fqs;
    std::cout << "Enter second-quarter sales:" << std::endl;
    std::cin >> sales.sqs;
    std::cout << "Enter third-quarter sales:" << std::endl;
    std::cin >> sales.tqs;
    std::cout << "Enter fourth-quarter sales:" << std::endl;
    std::cin >> sales.fourqs;
    sales.tas = sales.fqs + sales.sqs + sales.tqs + sales.fourqs;
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "Total Annual sales:$" << sales.tas << std::endl;
    sales.aqs = (sales.fqs + sales.sqs + sales.tqs + sales.fourqs)/4;
    std::cout << "Average Quarterly Sales:$" << sales.aqs;
}