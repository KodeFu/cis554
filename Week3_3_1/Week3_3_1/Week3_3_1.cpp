/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 3_1 - Properly constructed IF statements
/////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int number1 = 0;
	int number2 = 0;

	// get user input
	cout << "Enter value for number1" << endl;
	cin >> number1;
	cout << "Enter value for number2" << endl;
	cin >> number2;

	if (number1 > 5)
	{
		if (number2 > 5)
		{
			cout << "number1 and number2 are both > 5" << endl;
		}
		else
		{
			cout << "number1 > 5 but number2 <= 5" << endl;
		}
	}
	else
	{
		cout << "number1 is <= 5" << endl;
	}

	return 0;
}
