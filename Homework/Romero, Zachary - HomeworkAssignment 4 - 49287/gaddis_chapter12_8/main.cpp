#include <iostream>
#include <fstream>
using namespace std;

void arrayToFile(fstream &, int *, int);
void fileToArray(fstream &, int *, int);

int main()
{
    fstream Ary;
    int *out = nullptr;
    int *in = nullptr;
    int sizeIn;
    out = new int[sizeIn];
    in = new int[sizeIn];
    cout << "Enter the size of the array." << endl;
    cin >> sizeIn;
    cout << "Enter integers into the array." << endl;
    for(int i = 0; i < sizeIn; i++)
        cin >> out[i];
    arrayToFile(Ary,out,sizeIn);
    fileToArray(Ary,in,sizeIn);
    for(int i = 0; i < sizeIn; i++)
        cout << in[i] << ' ';
    cout << endl;
    delete [] in;
    delete [] out;
    in = nullptr;
    out = nullptr;
    return 0;
}

void arrayToFile(fstream &out, int *array, int sizeIn)
{
    out.open("array.dat", ios::out | ios::binary);
    out.write(reinterpret_cast<char *>(array), sizeof(array) * sizeIn);
    out.close();
}

void fileToArray(fstream &in, int *array, int sizeIn)
{
    in.open("array.dat", ios::in | ios::binary);
    in.read(reinterpret_cast<char *>(array), sizeof(array) * sizeIn);
    in.close();
}