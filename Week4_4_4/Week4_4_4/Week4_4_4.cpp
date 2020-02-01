// Week4_4_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "TimeDiff.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int hour;
    int minute;
    int second;

    std::cout << "Greatest TimeDiff app ever!\n";

    cout << "Enter hour: ";
    cin >> hour;

    cout << "Enter minute: ";
    cin >> minute;

    cout << "Enter second: ";
    cin >> second;

    TimeDiff timeDiff(hour, minute, second);

    int secondsSinceNoon = timeDiff.SecondsSinceNoon();

    if (secondsSinceNoon == -1)
    {
        cout << "Invalid time entered!" << endl;
    }
    else
    {
        cout << "Seconds since previous noon = " << secondsSinceNoon <<  endl;
    }
}