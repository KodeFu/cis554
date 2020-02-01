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
	int number1;
	int number2;
	int result;

public:
	SimpleMath(int a, int b)
	{
		number1 = a;
		number2 = b;
	}

	int GetResult()
	{
		return result;

	}

	void Add()
	{
		result = number1 + number2;
	}

	void Multiply()
	{
		result = number1 * number2;
	}
};

int main()
{
	// declare some variables to work with
	int number1 = 5;
	int number2 = 10;

	// declare an object of type SimpleMath
	SimpleMath simpleMath(number1, number2);

	// perform our operation using the simpleMath object, then display result
	simpleMath.Add();
	cout << number1 << " + " << number2 << " = " << simpleMath.GetResult() << endl;

	simpleMath.Multiply();
	cout << number1 << " * " << number2 << " = " << simpleMath.GetResult() << endl;

	return 0;
}
