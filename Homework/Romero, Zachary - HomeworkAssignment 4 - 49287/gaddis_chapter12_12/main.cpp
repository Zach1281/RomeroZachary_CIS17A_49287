#include <iostream>
#include <fstream>
using namespace std;

struct CompanyData
{
    string division;
    int quarter;
    float sales;
};

int main()
{
    fstream division("divison.dat", ios::out | ios::binary);
    int sizeIn;
    cout << "How many divisions of the company would you like to record?" << endl;
    cin >> sizeIn;
    CompanyData *div = new CompanyData[sizeIn];
    for(int i = 0; i < sizeIn; i++)
    {
        cout << "Division: " << endl;
        cin.ignore();
        getline(cin, div[i].division);
        cout << "Quarter: " << endl;
        for(int i = 0; i < 4; i++)
        {
            cin >> div[i].quarter;
            if(div[i].quarter < 0)
                return 0;
            cout << "Quarterly Sales: " << endl;
            cin >> div[i].sales;
            if(div[i].sales < 0)
                return 0;
        }
        division.write(reinterpret_cast<char *>(&div[i]), sizeof(div[i]));
    }
    division.close();
    delete [] div;
    div = nullptr;
    return 0;  
}

