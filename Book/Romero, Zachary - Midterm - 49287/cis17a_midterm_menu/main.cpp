#include <iostream>
using namespace std;

//User Libraries
#include "Array.h"
#include "mdstruct.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
struct AccountInfo              //Question 1
{
    string name;
    string address;
    string accNum;
    float balance;
    float *checks = nullptr;
    float *deposits = nullptr;
};
struct EmployeeInfo             //Question 2     
{
    float payRate;
    float hours;
    float pay;
    string name;
};

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
void engConv(EmployeeInfo *);
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
    cout<<"Type anything else to exit the program"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<"Problem 1"<<endl;
    AccountInfo *user = new AccountInfo;
    int numCheck{};
    float totDep{};
    cout << "Welcome to the Bank" << endl;
    cout << "Enter your name: " << endl;
    cin.ignore();
    getline(cin, user->name);
    cout << "Enter your address: " << endl;
    getline(cin, user->address);
    cout << "Enter your five digit account number: " << endl;
    do{
        getline(cin, user->accNum);
        if(user->accNum.length() > 5 || user->accNum.length() < 5)
            cout << "Error, please enter your five digit account number->" << endl;
    }while(user->accNum.length() != 5);
    cout << "Enter your balance: " << endl;
    cin >> user->balance;
    cout << "Enter the number of checks written this month: " << endl;
    cin >> numCheck;
    user->checks = new float[numCheck];
    user->deposits = new float[numCheck];
    for(int i = 0; i < numCheck; i++)
    {
        cout << "Enter the value of check #" << i + 1 << ": " << endl;
        cin >> user->checks[i];
        user->balance -= user->checks[i];
        user->deposits[i] = user->checks[i];
        totDep += user->deposits[i];
    }
    cout << "Name: " << user->name << endl;
    cout << "Address: " << user->address << endl;
    cout << "Account Number: " << user->accNum << endl;
    cout << "Current Balance: " << user->balance << endl;
    cout << "Total Deposit: " << totDep << endl;
    if(user->balance < 0)
    {
        cout << "You have overdrawn your account, you will be charged $20." << endl;
        user->balance -= 20;
        cout << "You now owe: " << user->balance;
    }
   
    delete [] user->checks;
    delete [] user->deposits;
    delete user;
    
    return;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
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
                return;
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
            return;
        }
        cout << "Planar" << endl;
        cout << "1324 Elucid Ave." << endl;
        cout << "Name: " << user[i].name << "\t\t" << "Amount: $" << user[i].pay << endl;
        cout << "Amount: ";
        engConv(user);
        cout << "Signature Line: " << endl;
        delete [] user;
        user = nullptr;
    }
    return;
}



//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){      //the stat function is on line 583
    cout<<"Problem 3"<<endl;
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
    const int SIZE = 4;

    string num;
    int array[SIZE];
    int temp;
    char choice;
    cout << "Enter a four digit number with each digit between 0-7: ";
    cin >> num;
    if(num.length() != 4)
    {
        cout << "Incorrect digit length, end program." << endl;
        return;
    }
    cout << "Would you like to encrypt or decrypt your number?(e/d)" << endl;
    cin >> choice;
    switch (choice)
    {
        case 'e':
        {
            for(int i = 0; num[i] != '\0'; i++)
            {
                array[i] = num[i] - 48;
                if(array[i] < 0 || array[i] > 7){
                    cout << array[i] << " not between 0 and 7, end program.";
                        return;}
                array[i] += 5;
                array[i] = array[i] % 8;
            }
            temp = array[0];
            array[0] = array[2];
            array[2] = temp;
            temp = array[1];
            array[1] = array[3];
            array[3] = temp;
            for(int i = 0; i < 4; i++)
                cout << array[i];
            break;
        }
        case 'd':
        {
            for(int i = 0; num[i] != '\0'; i++)
                array[i] = num[i] - 48;
            //reverse the encryption
            temp = array[0];
            array[0] = array[2];
            array[2] = temp;
            temp = array[1];
            array[1] = array[3];
            array[3] = temp;
            cout << endl;
            for(int i = 0; i < 4; i++)
            {
                array[i] += (-5 + 8);
                array[i] = array[i] % 8;
                cout << array[i];
            }
            break;
        }
        default:
             cout << "Incorrect input, end program." << endl;
    }
    return;
}

void prblm5()
{
    cout << "signed char:    n = 5" << endl;
    cout << "unsigned char:  n = 5" << endl;
    cout << "signed int:     n = 12" << endl;
    cout << "unsigned int:   n = 12" << endl;
    cout << "signed short:   n = 7" << endl;
    cout << "unsigned short: n = 8" << endl;
    cout << "signed long:    n = 20" << endl;
    cout << "unsigned long:  n = 20" << endl;
    cout << "float:          n = 34" << endl;
    cout << "double:         n = 170" << endl;
}

void prblm6()
{
    cout << "***********************************" << endl;
    cout << "Number 1: 2.875" << endl;
    cout << "Base 2 -> 10.111" << endl;
    cout << "Base 8 -> 2.7" << endl;
    cout << "Base 16 -> 2.E" << endl;
    cout << "Positive NASA Float -> 5C000002" << endl;
    cout << "Negative NASA Float -> DC000002" << endl;
    cout << "***********************************" << endl;
    cout << "Number 2: 0.1796875" << endl;
    cout << "Base 2 -> 0.0010111" << endl;
    cout << "Base 8 -> 0.134" << endl;
    cout << "Base 16 -> 0.2E" << endl;
    cout << "***********************************" << endl;
    cout << "Number 3: 59999901" << endl;
    cout << "Base 10 -> 1.399999857" << endl;
    cout << "***********************************" << endl;
    cout << "Number 4: 59999902" << endl;
    cout << "Base 10 -> 2.79999971389770507813" << endl;
    cout << "***********************************" << endl;
    cout << "Number 5: A66667FE" << endl;
    cout << "Base 10 -> -0.00000000027939677655" << endl;
    cout << "***********************************" << endl;
}

void prblm7()
{
    const int SIZE = 50;
    int num;
    int count = 0;
    int primes[SIZE]{};
    int powers[SIZE]{};
    int j = 1;
    primes[0] = 2;
    
    cout << "Enter a number between 2 and 10000: " << endl;
    do{
        cin >> num;
        if(num > 10000 || num < 2)
            cout << "Not in bounds, please enter a number between 2 and 10000: " << endl;
    }while(num > 10000 || num < 2);
    
    while(num % 2 == 0)
    {
        num /= 2;
        count++;
    }
    powers[0] = count;
    
    for(int i = 2; i <= num; i++)               //1 doesn't work, have to start at maybe 2?
    {
        while(num % i == 0)                     //save the number on i and repeat the mod until it doesn't = 0
        {                                       //with each counter that should be the power of the number                                       
            num /= i;                           //now i don't know how to get rid of the 4
            count++; 
        }
        if(i % 2 != 0)                          
        {
            while(j<10000)
            {
                primes[j] = i;
                powers[j] = count;
                j++;
                break;
            }
        }
        count = 0;
    }
    for(int i = 0; i < SIZE; i++)
    {
        if(primes[i] > 0)
            cout << primes[i] << '^' << powers[i] << '*';
    }
    cout << endl;
    return;
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
//Question 3 Functions
int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    bool diff;
    int freq = 1;
    int num = array->data[0];
    int count = 1;
    int mode = 0;
    float sum = 0;
    Stats *stats=new Stats;
    stats->mode=new Array;
    int *factors = nullptr;
    factors = new int[array->size]{};
    for(int i = 1; i < array->size; i++)
    {
        if(array->data[i] == num)
            count++;
        else
        {
            if(count > freq)
                freq = count;
            if(count == freq)
            {
                mode++;
                factors[i-1] = array->data[i];
            }
            count = 1;
            num = array->data[i];
        }
        sum += array->data[i];
    }
    
    float avg = sum/array->size;
    int med = sum/array->size;
    if(freq == 1)
        mode = 0;
    stats->mode->size=mode;
    int nModes=mode;
    if(nModes!=0)
    {
        stats->mode->data=new int[nModes];
        int j = 0;
        for(int i = 0; i < array->size; i++)
        {
            if(factors[i] > 0)
            {
                while(j<10000)
                {
                    stats->mode->data[j] = array->data[i];
                    j++;
                    break;
                }
            }
        }
    }
    stats->modFreq=freq;
    stats->median=med;
    stats->avg=avg;
    delete [] factors;
    factors = nullptr;
    return stats;
}