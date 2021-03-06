///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 2_1 - Simple Class
///////////////////////////////////////////////
#include "pch.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class SimpleMath
{
public:
	// simple Add method
	int Add(int number1, int number2)
	{
		int result = number1 + number2;
		return result;
	}

	int Multiply(int number1, int number2)
	{
		int result = number1 * number2;
		return result;
	}
};

int main()
{
	// declare an object of type SimpleMath
	SimpleMath simpleMath;

	// declare some variables to work with
	int number1 = 0;
	int number2 = 0;
	int result = 0;

	// prompt user for input
	cout << "Enter first number: ";
	cin >> number1;
	cout << "Enter second number: ";
	cin >> number2;

	// perform our operation using the simpleMath object, then display result
	result = simpleMath.Add(number1, number2);
	cout << number1 << " + " << number2 << " = " << result << endl;

	result = simpleMath.Multiply(number1, number2);
	cout << number1 << " * " << number2 << " = " << result << endl;

	return 0;
}
