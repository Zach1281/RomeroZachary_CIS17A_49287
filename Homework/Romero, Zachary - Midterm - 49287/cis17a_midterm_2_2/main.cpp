#include <iostream>
#include <cstdlib>
using namespace std;

struct EmployeeInfo
{
    float payRate;
    float hours;
    float pay;
    string name;
};

void engConv(EmployeeInfo *);

int main()
{
    int sizeIn;
    cout << "Enter the amount of employees: " << endl;
    cin >> sizeIn;
    EmployeeInfo *user = new EmployeeInfo[sizeIn];
    for(int i = 0; i < sizeIn; i++)
    {
        cout << "Enter your name: " << endl;
        cin.ignore();
        getline(cin,user[i].name);
        
        do{
            cout << "Enter your pay rate: " << endl;
            cin >> user[i].payRate;
            if(user[i].payRate <= 0)
            {
                cout << "It looks like you're not getting paid or paying to work." << endl;
                return 0;
            }
        }while(user[i].payRate <= 0);
        cout << "Enter the hours worked this week: " << endl;
        cin >> user[i].hours;
        if(user[i].hours <= 40 && user[i].hours >= 0)
        {
            user[i].pay = user[i].payRate * user[i].hours;
            cout << "You worked 40 hours or less this week, you are being paid straight time: $" << user[i].pay << '.' << endl;
        }
        else if(user[i].hours > 40 && user[i].hours < 50)
        {
            user[i].pay = user[i].payRate * user[i].hours * 2;
            cout << "You worked more than 40 hours but less than 50, you are being paid double time: $" << user[i].pay << '.' << endl;
        }
        else if(user[i].hours >= 50)
        {
            user[i].pay = user[i].payRate * user[i].hours * 3;
            cout << "You worked 50 or more hours this week, you are being paid triple time: $" << user[i].pay << '.' << endl;
        }
        else
        {
            cout << "You entered a negative number, end program." << endl;
            return 0;
        }
        cout << "Planar" << endl;
        cout << "1324 Elucid Ave." << endl;
        cout << "Name: " << user[i].name << "\t\t" << "Amount: $" << user[i].pay << endl;
        cout << "Amount: ";
        engConv(user);
        cout << "Signature Line: " << endl;
    }
    return 0;
}

void engConv(EmployeeInfo *user)
{
    unsigned short n2Cnvrt = user->pay;
    //Check for a valid input
    if(n2Cnvrt>=1 && n2Cnvrt<=9000){
    //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s,n100s,n10s,n1s;
        n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
        n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=n2Cnvrt%10;        //Remainder of division by 10
        
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        if(n1000s == 9)cout<<"Nine Thousand ";
        if(n1000s == 8)cout<<"Eight Thousand ";
        if(n1000s == 7)cout<<"Seven Thousand ";
        if(n1000s == 6)cout<<"Six Thousand ";
        if(n1000s == 5)cout<<"Five Thousand ";
        if(n1000s == 4)cout<<"Four Thousand ";
        if(n1000s == 3)cout<<"Three Thousand ";
        if(n1000s == 2)cout<<"Two Thousand ";
        if(n1000s == 1)cout<<"One Thousand ";
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?"Nine Hundred ":
               n100s==8?"Eight Hundred ":
               n100s==7?"Seven Hundred ":
               n100s==6?"Six Hundred ":
               n100s==5?"Five Hundred ":
               n100s==4?"Four Hundred ":
               n100s==3?"Three Hundred ":
               n100s==2?"Two Hundred ":
               n100s==1?"One Hundred ":"");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<<"and Ninety ";
        if(n10s==8)cout<<"and Eighty ";
        if(n10s==7)cout<<"and Seventy ";
        if(n10s==6)cout<<"and Sixty ";
        if(n10s==5)cout<<"and Fifty ";
        if(n10s==4)cout<<"and Forty ";
        if(n10s==3)cout<<"and Thirty ";
        if(n10s==2)cout<<"and Twenty ";
        if(n10s==1 && n1s ==1){
            cout<<"and Eleven" << endl;
            return;}
        if(n10s==1 && n1s==2){
            cout<<"and Twelve" << endl;
            return;}
        if(n10s==1 && n1s==3){
            cout <<"and Thirteen" << endl;
            return;}
        if(n10s==1 && n1s==4){
            cout <<"and Fourteen" << endl;
            return;}
        if(n10s==1 && n1s==5){
            cout <<"and Fifteen" << endl;
            return;}
        if(n10s==1 && n1s==6){
            cout <<"and Sixteen" << endl;
            return;}
        if(n10s==1 && n1s==7){
            cout <<"and Seventeen" << endl;
            return;}
        if(n10s==1 && n1s==8){
            cout <<"and Eighteen" << endl;
            return;}
        if(n10s==1 && n1s==9){
            cout <<"and Nineteen" << endl;
            return;}
        //Output the number of 1's
        //Using Dependent If Statements
        
            if(n1s==9)cout<<"Nine";
            else if(n1s==8)cout<<"Eight";
            else if(n1s==7)cout<<"Seven";
            else if(n1s==6)cout<<"Six";
            else if(n1s==5)cout<<"Five";
            else if(n1s==4)cout<<"Four";
            else if(n1s==3)cout<<"Three";
            else if(n1s==2)cout<<"Two";
            else if(n1s==1)cout<<"One";
        cout<<" Dollars" << endl;
    }
    else;
}