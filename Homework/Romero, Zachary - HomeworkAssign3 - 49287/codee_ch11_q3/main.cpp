#include <iostream>
#include <iomanip>

struct MonthlyBudget
{
    float housing = 500.00;
    float util = 150.00;
    float hexp = 65.00;
    float trans = 50.00;
    float food = 250.00;
    float med = 30.00;
    float ins = 100.00;
    float ent = 150.00;
    float cloth = 75.00;
    float mis = 50.00;
};

struct BudgetCheck      // i think i could have just made a different structure with MonthlyBudget instead of predefining MonthlyBudget idk 
{
    float chouse;
    float cutil;
    float chexp;
    float ctrans;
    float cfood;
    float cmed;
    float cins;
    float cent;
    float ccloth;
    float cmis;
};

void getData(BudgetCheck&);
bool overUnder(BudgetCheck&, MonthlyBudget&);

int main()
{
    float totMonth{}, totWowe{}, diff{};
    MonthlyBudget wowe;
    BudgetCheck month;
    getData(month);
    
    totWowe = wowe.housing + wowe.util + wowe.hexp + wowe.trans + wowe.food
              + wowe.med + wowe.ins + 
              + wowe.ent + wowe.cloth + wowe.mis;
    totMonth = month.chouse + month.cutil + month.chexp + month.ctrans + month.cfood 
               + month.cmed + month.cins
               + month.cent + month.ccloth + month.cmis;
    if(month.chouse > wowe.housing)
        std::cout << "Housing Over" << std::endl;
    else if(month.chouse < wowe.housing)
        std::cout << "Housing Under" << std::endl;
    else
        std::cout << "Housing Even" << std::endl;
    if(month.cutil > wowe.util)
        std::cout << "Utilities Over" << std::endl;
    else if(month.cutil < wowe.util)
        std::cout << "Utilities Under" << std::endl;
    else
        std::cout << "Utilities Even" << std::endl;
    if(month.chexp > wowe.hexp)
        std::cout << "Household Expenses Over" << std::endl;
    else if(month.chexp < wowe.hexp)
        std::cout << "Household Expenses Under" << std::endl;
    else 
        std::cout << "Household Expenses Even" << std::endl;
    if(month.ctrans > wowe.trans)
        std::cout << "Transportation Over" << std::endl;
    else if(month.ctrans < wowe.trans)
        std::cout << "Transportation Under" << std::endl;
    else
        std::cout << "Transportation Even" << std::endl;
    if(month.cfood > wowe.food)
        std::cout << "Food Over" << std::endl;
    else if(month.cfood < wowe.food)
        std::cout << "Food Under" << std::endl;
    else
        std::cout << "Food Even" << std::endl;
    if(month.cmed > wowe.med)
        std::cout << "Medical Over" << std::endl;
    else if(month.cmed < wowe.med)
        std::cout << "Medical Under" << std::endl;
    else
        std::cout << "Medical Even" << std::endl;
    if(month.cins > wowe.ins)
        std::cout << "Insurance Over" << std::endl;
    else if(month.cins < wowe.ins)
        std::cout << "Insurance Under" << std::endl;
    else 
        std::cout << "Insurance Even" << std::endl;
    if(month.cent > wowe.ent)
        std::cout << "Entertainment Over" << std::endl;
    else if(month.cent < wowe.ent)
        std::cout << "Entertainment Under" << std::endl;
    else
        std::cout << "Entertainment Even" << std::endl;
    if(month.ccloth > wowe.cloth)
        std::cout << "Clothing Over" << std::endl;
    else if(month.ccloth < wowe.cloth)
        std::cout << "Clothing Under" << std::endl;
    else 
        std::cout << "Clothing Even" << std::endl;
    if(month.cmis > wowe.mis)
        std::cout << "Miscellaneous Over" << std::endl;
    else if(month.cmis < wowe.mis)
        std::cout << "Miscellaneous Under" << std::endl;
    else 
        std::cout << "Miscellaneous Even" << std::endl;
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    if(totMonth > totWowe)
    {
        diff = totMonth - totWowe;
        std::cout << "You were $" << diff << " over budget";
    }
    else if(totMonth < totWowe)
    {
        diff = totWowe - totMonth;
        std::cout << "You were $" << diff << " under budget";
    }
    else
        std::cout << "You were even" << std::endl;
    return 0;
}

void getData(BudgetCheck &budCheck)
{
    std::cout << "Enter housing cost for the month:$" << std::endl;
    std::cin >> budCheck.chouse;
    std::cout << "Enter utilities cost for the month:$" << std::endl;
    std::cin >> budCheck.cutil;
    std::cout << "Enter household expenses cost for the month:$" << std::endl;
    std::cin >> budCheck.chexp;
    std::cout << "Enter transportation cost for the month:$" << std::endl;
    std::cin >> budCheck.ctrans;
    std::cout << "Enter food cost for the month:$" << std::endl;
    std::cin >> budCheck.cfood;
    std::cout << "Enter medical cost for the month:$" << std::endl;
    std::cin >> budCheck.cmed;
    std::cout << "Enter insurance cost for the month:$" << std::endl;
    std::cin >> budCheck.cins;
    std::cout << "Enter entertainment cost for the month:$" << std::endl;
    std::cin >> budCheck.cent;
    std::cout << "Enter clothing cost for the month:$" << std::endl;
    std::cin >> budCheck.ccloth;
    std::cout << "Enter miscellaneous cost for the month:$" << std::endl;
    std::cin >> budCheck.cmis;
}


