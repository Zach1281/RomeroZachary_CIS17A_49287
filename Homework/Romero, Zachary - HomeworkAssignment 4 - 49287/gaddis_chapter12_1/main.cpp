#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream lines;
    string wewo;
    lines.open("head.txt", ios::in);
    
    for(int i = 0; i < 10; i++)
    {
        getline(lines, wewo);
        cout << wewo << endl;
        if((lines.eof()) && (i != 10))
            cout << "End of file." << endl;
    }
    lines.close();
    return 0;
}