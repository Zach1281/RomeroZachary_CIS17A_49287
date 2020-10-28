#include <iostream>
using namespace std;

const int SIZE = 4;

int main()
{
    string num;
    int array[SIZE];
    int temp;
    char choice;
    cout << "Enter a four digit number with each digit between 0-7: ";
    cin >> num;
    if(num.length() != 4)
    {
        cout << "Incorrect digit length, end program." << endl;
        return 0;
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
                        return 0;}
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
    return 0;
}