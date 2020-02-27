// Week5_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>

using namespace std;

int main()
{
    vector<int> n;
    int sum = 0;

    for (size_t i = 0; i < 10; ++i)
    {
        n.push_back( rand() % 100 + 1 );
    }

    cout << "Element" << setw(13) << "Value" << endl;

    int j = 0;
    for (int item : n)
    {
        cout << setw(7) << j++ << setw(13) << item << endl;
        sum += item;
    }

    cout << "The average value is: " << ( ((double)sum) / n.size()) << endl;
}

