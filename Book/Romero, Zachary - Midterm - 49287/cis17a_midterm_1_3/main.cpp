#include <iostream>
#include <string>
using namespace std;

struct AccountInfo
{
    string name;
    string address;
    string accNum;
    float balance;
    float *checks = nullptr;
    float *deposits = nullptr;
};

int main()
{
    AccountInfo *user = new AccountInfo;
    int numCheck{};
    float totDep{};
    cout << "Welcome to the Bank" << endl;
    cout << "Enter your name: " << endl;
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
    return 0;
}