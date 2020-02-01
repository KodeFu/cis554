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
private:
	int result;

public:
	int GetResult()
	{
		return result;

	}

	void Add(int number1, int number2)
	{
		result = number1 + number2;
	}

	void Multiply(int number1, int number2)
	{
		result = number1 * number2;
	}
};

int main()
{
	// declare an object of type SimpleMath
	SimpleMath simpleMath;

	// declare some variables to work with
	int number1 = 0;
	int number2 = 0;

	// prompt user for input
	cout << "Enter first number: ";
	cin >> number1;
	cout << "Enter second number: ";
	cin >> number2;

	// perform our operation using the simpleMath object, then display result
	simpleMath.Add(number1, number2);
	cout << number1 << " + " << number2 << " = " << simpleMath.GetResult() << endl;

	simpleMath.Multiply(number1, number2);
	cout << number1 << " * " << number2 << " = " << simpleMath.GetResult() << endl;

	return 0;
}
