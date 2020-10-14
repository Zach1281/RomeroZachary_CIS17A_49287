#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    string name1, name2;
    char ch;
    
    //i'm not sure if this is exactly what the program wants but you have to enter name1 as "letter.txt" for this to work
    
    cout << "Enter the name of the upper-case file." << endl;
    getline(cin, name1);
    cout << "Enter the name of the lower-case file." << endl;
    getline(cin, name2);
    //define the in and out files with the user names
    inFile.open(name1);
    outFile.open(name2);
    if(inFile)
    {
        inFile.get(ch);
        while(inFile)
        {
            outFile.put(tolower(ch));
            inFile.get(ch);
        }
        inFile.close();
        outFile.close();
    }
    else
        cout << "Cannot open, end program" << name1 << endl;
    
    return 0;
}