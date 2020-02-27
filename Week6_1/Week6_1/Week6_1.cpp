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

    for (int &item : n)
    {
        item = rand() % 100 + 1;
    }

    cout << "Element" << setw(13) << "Value" << endl;

    int counter = 0;
    for (int item : n)
    {

        cout << setw(7) << counter++ << setw(13) << item << endl;
        sum += item;
    }

    cout << "The average value is: " << ( ((double)sum) / n.size()) << endl;
}

