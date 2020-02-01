// Fig. 2.13: fig02_13.cpp
// Comparing integers using if statements, relational operators
// and equality operators.
#include "pch.h"
#include <iostream> // allows program to perform input and output

using std::cout; // program uses cout
using std::cin; // program uses cin
using std::endl; // program uses endl

// function main begins program execution
int main()
{
	int number1 = 0; // first integer to compare (initialized to 0)
	int number2 = 0; // second integer to compare (initialized to 0)
	int number3 = 0;
	int result = 0;

	cout << "Enter three integers to compare: "; // prompt user for data
	cin >> number1 >> number2 >> number3; // read two integers from user

	result = number1 * number2;

	if (result == number3)
		cout << result << " == " << number3 << endl;

	if (result != number3)
		cout << result << " != " << number3 << endl;

	if (result < number3)
		cout << result << " < " << number3 << endl;

	if (result > number3)
		cout << result << " > " << number3 << endl;

	if (result <= number3)
		cout << result << " <= " << number3 << endl;

	if (result >= number3)
		cout << result << " >= " << number3 << endl;
} // end function main