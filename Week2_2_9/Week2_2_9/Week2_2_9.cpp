///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 2_1 - Simple Class
///////////////////////////////////////////////
#include "pch.h"
#include <iostream>
#include "SimpleMath.h"

using std::cout;
using std::cin;
using std::endl;



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
