#include <iostream>
#include <iomanip>

struct SodaMachine 
{
    std::string name;
    int cost;
    int count;
};

const int SIZE = 5;

int main()
{
    SodaMachine soda[SIZE] = 
    {
        {"Cola", 75, 20},
        {"Root Beer", 75, 20},
        {"Lemon-Lime", 75, 20},
        {"Grape Soda", 80, 20},
        {"Cream Soda", 80, 20}
    };
    
    std::string type;
    std::string exit{"Quit"};
    int pay{}, diff{}, profit{};
    
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << soda[0].name << "       " << soda[0].cost << "  " << soda[0].count << std::endl;
        std::cout << soda[1].name << "  " << soda[1].cost << "  " << soda[1].count << std::endl;
        std::cout << soda[2].name << " " << soda[2].cost << "  " << soda[2].count << std::endl;
        std::cout << soda[3].name << " " << soda[3].cost << "  " << soda[3].count << std::endl;
        std::cout << soda[4].name << " " << soda[4].cost << "  " << soda[4].count << std::endl;
        std::cout << exit << std::endl;
        if(i == 0)
            std::getline(std::cin,type);
        else
        {
            std::cin.ignore();
            std::getline(std::cin,type);
        }
        do{
        std::cin >> pay;
        }while((pay < 0) || (pay > 100));
        
        if(type == soda[0].name)
        {
            if(pay >= soda[0].cost)
            {
                diff = pay - soda[0].cost;
                soda[0].count -= 1;
                std::cout << diff << std::endl;
                profit += pay - diff;
            }
            else
            {
                std::cout << "This is not enough to pay for the soda, please try again." << std::endl;
                break;
            }
        }
        else if(type == soda[1].name)
        {
            if(pay >= soda[1].cost)
            {
                diff = pay - soda[1].cost;
                soda[1].count -= 1;
                std::cout << diff << std::endl;
                profit += pay - diff;
            }
            else
            {
                std::cout << "This is not enough to pay for the soda, please try again." << std::endl;
                break;
            }
        }
        else if(type == soda[2].name)
        {
            if(pay > soda[2].cost)
            {
                diff = pay - soda[2].cost;
                soda[2].count -= 1;
                std::cout << diff << std::endl;
                profit += pay - diff;
            }
            else
            {
                std::cout << "This is not enough to pay for the soda, please try again." << std::endl;
                break;
            }
        }
        else if(type == soda[3].name)
        {
            if(pay > soda[3].cost)
            {
                diff = pay - soda[3].cost;
                soda[3].count -= 1;
                std::cout << diff << std::endl;
                profit += pay - diff;
            }
            else
            {
                std::cout << "This is not enough to pay for the soda, please try again." << std::endl;
                break;
            }
        }
        else if(type == soda[4].name)
        {
            if(pay > soda[4].cost)
            {
                diff = pay - soda[4].cost;
                soda[4].count -= 1;
                std::cout << diff << std::endl;
                profit += pay - diff;
            }
            else
            {
                std::cout << "This is not enough to pay for the soda, please try again." << std::endl;
                break;
            }
        }
        else
        {
            std::cout << profit << std::endl;
            return 0;
            
        }
    }
    return 0;
}