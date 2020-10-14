#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    string lines, name;
    char repeat;
    cout << "Enter in the name of the file." << endl;
    getline(cin,name);
    file.open(name, ios::in);//the file name is "file.txt"
    do{
    for(int i = 0; i <= 24; i++)
    {
        getline(file, lines);
        cout << lines << endl;
        if(file.eof())
        {
            cout << "End of file." << endl;
            return 0;
        }
    }
    cout << "The file is not done being displayed, would you like to see the rest?(y/n)" << endl;
    cin >> repeat;
    }while((repeat == 'y') || (repeat == 'Y'));
    file.close();
    return 0;
}