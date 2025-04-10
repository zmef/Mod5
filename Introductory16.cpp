// Introductory16.cpp
// This program displays a table of numbers 10 through 13
// along with the squares and cubes.
//Created/revised by ZMF on 4/10/25

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // Set up table headers
    cout << left << setw(10) << "Number"
         << setw(10) << "Square"
         << setw(10) << "Cube" << endl;

    cout << "------------------------------" << endl;

    // Loop from 10 to 13 and calculate square and cube
    for (int num = 10; num <= 13; num++)
    {
        cout << left << setw(10) << num
             << setw(10) << pow(num, 2)
             << setw(10) << pow(num, 3) << endl;
    }

    return 0;
}
