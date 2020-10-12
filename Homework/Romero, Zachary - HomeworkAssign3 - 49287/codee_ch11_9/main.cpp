#include <iostream>
#include <iomanip>

struct Speaker
{
    std::string name;
    float telenum;
    std::string topic;
    float fee;
};

void getData(Speaker&);
void display(Speaker&);

const int SIZE = 10;

int main()
{
    char choice{};
    Speaker speakers[SIZE]{};
    
    std::cout << "This application allows the user to enter in up to ten speakers." << std::endl;
    
    while(choice != 'q')
    {
        std::cout << "Type in numbers 0-9 to get access to the respective speakers." << std::endl;
        std::cin >> choice;
        switch (choice)
        {
            case '0':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch (choice)
                {
                    case 'e':
                    {
                        getData(speakers[0]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[0]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '1':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch (choice)
                {
                    case 'e':
                    {
                        getData(speakers[1]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[1]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '2':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch (choice)
                {
                    case 'e':
                    {
                        getData(speakers[2]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[2]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '3':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 'e':
                    {
                        getData(speakers[3]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[3]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '4':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 'e':
                    {
                        getData(speakers[4]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[4]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '5':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 'e':
                    {
                        getData(speakers[5]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[5]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '6':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 'e':
                    {
                        getData(speakers[6]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[6]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '7':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 'e':
                    {
                        getData(speakers[7]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[7]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '8':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 'e':
                    {
                        getData(speakers[8]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[8]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case '9':
            {
                std::cout << "Would you like to edit or view this speaker?(e/v)" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 'e':
                    {
                        getData(speakers[9]);
                        break;
                    }
                    case 'v':
                    {
                        display(speakers[9]);
                        break;
                    }
                    default:
                    {
                        std::cout << "Incorrect input, end program" << std::endl;
                        return 0;
                    }
                }
                break;
            }
            default:
            {
                std::cout << "Do you wish to exit the program?(press q if so)" << std::endl;
                std::cin >> choice;
            }

        }
    };
}

void getData(Speaker &s)
{
    std::cout << "Name: " << std::endl;
    std::cin.ignore();
    getline(std::cin,s.name);
    std::cout << "Telephone Number: " << std::endl;
    std::cin >> s.telenum;
    std::cout << "Speaking Topic: " << std::endl;
    std::cin.ignore();
    getline(std::cin,s.topic);
    std::cout << "Fee Required: " << std::endl;
    std::cin >> s.fee;
}

void display(Speaker &s)
{
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "Telephone Number: " << s.telenum << std::endl;
    std::cout << "Speaking Topic: " << s.topic << std::endl;
    std::cout << "Fee Required: " << s.fee << std::endl;
}