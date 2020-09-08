/*file: Gaddis_9th_6_7_CelsiusTempTable
 * author: Zachary Romero
 * date: 31 August 2020 3:20 PM
 */
#include <iostream>

/*Fahrenheit should be displayed as a table with corresponding celsius temps.
 * formula = 5/9(F-32)
 */

double conversion(double F)
{
    return (5.0/9.0) * (F - 92.0);
}

int main()
{
    double C{};
  
    std::cout << "F\tC\n"
              << "**********" << std::endl;
    
    for(int i =0; i <= 20; i++)
    {   
        C = conversion(i);
        std::cout << i << "\t" << C << std::endl;
    }
    return 0;
}

