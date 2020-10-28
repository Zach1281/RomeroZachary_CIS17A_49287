#include <iostream>

//figuring out how to make a betting system using a struct would make the most sense
struct Chips
{
    int black{};
    int orange{};
    int green{};
    int grey{};
    int blue{};
    int red{};
    int yellow{};
    int white{};
};

int main()
{
    Chips player1;
    int totChips{};                 //maybe make different colors different chips with different values
    int bet{};
    std::cout << "We have different chips for you to buy: " << std::endl;
    std::cout << "Black  = $100" << std::endl;
    std::cout << "Orange = $50" << std::endl;
    std::cout << "Green  = $25" << std::endl;
    std::cout << "Grey   = $20" << std::endl;
    std::cout << "Blue   = $10" << std::endl;
    std::cout << "Red    = $5" << std::endl;
    std::cout << "Yellow = $2" << std::endl;
    std::cout << "White  = $1" << std::endl;
    std::cout << "How much money would you like to enter into the game?" << std::endl;
    std::cin >> totChips;
    while(totChips >= 100)          //this section gives the amount of chips per category and stores them in the structure above
    {
        player1.black += 1;
        totChips -= 100;
        std::cout << totChips << std::endl;
    }
    while(totChips >= 50)
    {
        player1.orange += 1;
        totChips -= 50;
        std::cout << totChips << std::endl;
    }
    while(totChips >= 25)
    {
        player1.green += 1;
        totChips -= 25;
        std::cout << totChips << std::endl;
    }
    while(totChips >= 20)
    {
        player1.grey += 1;
        totChips -= 20;
        std::cout << totChips << std::endl;
    }
    while(totChips >= 10)
    {
        player1.blue += 1;
        totChips -= 10;
        std::cout << totChips << std::endl;
    }
    while(totChips >= 5)
    {
        player1.red += 1;
        totChips -= 5;
        std::cout << totChips << std::endl;
    }
    while(totChips >= 2)
    {
        player1.yellow += 1;
        totChips -= 2;
        std::cout << totChips << std::endl;
    }
    while(totChips >= 1)
    {
        player1.white += 1;
        totChips -= 1;
        std::cout << totChips << std::endl;
    }
    std::cout << "Here are your chips: " << std::endl;
    std::cout << "Black: " << player1.black << std::endl;
    std::cout << "Orange: " << player1.orange << std::endl;
    std::cout << "Green: " << player1.green << std::endl;
    std::cout << "Grey: " << player1.grey << std::endl;
    std::cout << "Blue: " << player1.blue << std::endl;
    std::cout << "Red: " << player1.red << std::endl;
    std::cout << "Yellow: " << player1.yellow << std::endl;
    std::cout << "White: " << player1.white << std::endl;
    //figuring out how to bet with the chips
    std::cout << "Enter the "
    return 0;
}