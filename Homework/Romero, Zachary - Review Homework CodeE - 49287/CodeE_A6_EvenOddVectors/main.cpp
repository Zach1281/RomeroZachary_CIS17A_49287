/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read (vector<int> & even, vector<int> & odd)
{
    int num, sizeIn;
    cout << "Input the number of integers to input." << endl;
    cin >> sizeIn;
    cout << "Input each number." << endl;
    for(int i = 0; i < sizeIn; i++)
    {
        cin >> num;
        if((num % 2) == 0)
            even.push_back(num);
        else
            odd.push_back(num);
    }
}

void copy (vector<int> even, vector<int> odd, int array[][COLMAX])
{
    for(int i = 0; i < even.size(); i++)
        array[i][0] = even.at(i);
    for(int j = 0; j < odd.size(); j++)
        array[j][1] = odd.at(j);
}

void prntVec (vector<int> even, vector<int> odd, int num)
{
    cout << "    Vector      Even       Odd" << endl;
    for(int i = 0;i < even.size(); i++)
        cout << setw(20)  << even.at(i) << setw(10) << odd.at(i) << endl;
    if (even.size() < odd.size())
    {
        for(int i = even.size(); i < odd.size(); i++)
            cout << right << setw(30) << odd.at(i) << endl;
    }
    else if (odd.size() < even.size())
    {
        for(int i = odd.size(); i < even.size(); i++)
            cout << right << setw(20) << even.at(i);
    }
}

void prntAry (const int array[][COLMAX], int even, int odd, int num)
{
    cout << "    Array       Even       Odd" << endl;
    for(int i = 0; i < even; i++)
        cout << setw(20) << array[i][0] << setw(10) << array[i][1] << endl;
    if(even < odd)
    {
        for(int i = even; i < odd; i++)
            cout << right << setw(30) << array[i][1] << endl;
    }
    else if(odd < even)
    {
        for(int i = odd; i < even; i++)
            cout << right << setw(20) << array[i][0] << endl;
            
    }
}