// Week5_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;

int computeSum(int number)
{
    if (number <= 1)
    {
        return 1; // base case
    }
    else
    {
        return number + computeSum(number-1);
    }
}

int main()
{
    std::cout << "Recursive sum calculator\n";

    int value = 4;

    cout << "Enter a value: ";
    cin >> value;
    cout << "The sum of all numbers from 1 to " << value << " is " << computeSum(value);
}
