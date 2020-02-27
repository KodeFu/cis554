// Week7_7_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DvideByZeroException.h"
#include "NumberTooLargeException.h"

using namespace std;

int multiplication(int numerator, int denominator)
{
    int result = numerator * denominator;
    if (result > 1000000)
    {
        throw NumberTooLargeException();
    }

    return result;
}

double quotient(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw DivideByZeroException();
    }

    return static_cast<double>(numerator) / denominator;
}

int main()
{
    int number1;
    int number2;

    cout << "Enter two integers (EOF to end): ";

    while (cin >> number1 >> number2)
    {
        try
        {
            double result = quotient(number1, number2);
            cout << "The quotient is: " << result << endl;
        }
        catch (DivideByZeroException &divideByZeroException)
        {
            cout << "Exception: " << divideByZeroException.what() << endl;
        }

        try
        {
            double result = multiplication(number1, number2);
            cout << "The result is: " << result << endl;
        }
        catch (NumberTooLargeException &numberTooLargeException)
        {
            cout << "Exception: " << numberTooLargeException.what() << endl;
        }

        cout << "Enter two integers (EOF to end): ";
    }

    cout << endl;
}
