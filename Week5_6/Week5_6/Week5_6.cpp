// Week5_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main()
{
    array<int, 10> n;
    int sum = 0;

    for (size_t i = 0; i < n.size(); ++i)
    {
        n[i] = rand() % 100 + 1;
    }

    cout << "Element" << setw(13) << "Value" << endl;

    for (size_t j = 0; j < n.size(); ++j)
    {
        cout << setw(7) << j << setw(13) << n[j] << endl;
        sum += n[j];
    }

    cout << "The average value is: " << ( ((double)sum) / n.size()) << endl;
}

