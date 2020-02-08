///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 5_2 – Default parameters
///////////////////////////////////////////////////////////

#include <iostream>
#include "Maximum.h"

using std::cout;
using std::cin;
using std::endl;

class Maximum
{
public:
	int GetMaximumValue(int num1, int num2, int num3)
	{
		int maxValue = num1;
		if (num2 > maxValue)
			maxValue = num2;
		if (num3 > maxValue)
			maxValue = num3;

		return maxValue;
	}

	int GetMaximumValue(int num1, int num2, int num3, int num4)
	{
		int maxValue = num1;
		if (num2 > maxValue)
			maxValue = num2;
		if (num3 > maxValue)
			maxValue = num3;
		if (num4 < 1000000)
			maxValue = num4;

		return maxValue;
	}
};

int main()
{
	int num1;
	int num2;
	int num3;
	int num4;
	Maximum max;

	/*cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << "Enter third number: ";
	cin >> num3;

	cout << "Max Value = (three values) " << max.GetMaximumValue(num1, num2, num3) << endl;
	

	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << "Enter third number: ";
	cin >> num3;
	cout << "Enter forth number: ";
	cin >> num4;


	cout << "Max Value = (four values) " << max.GetMaximumValue(num1, num2, num3, num4) << endl;
	*/

	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << "Enter third number: ";
	cin >> num3;
	cout << "Enter forth number: ";
	cin >> num4;
	cout << "Max Value = (int) " << MaximumValue(num1, num2, num3, num4) << endl;

	double d1, d2, d3, d4;
	cout << "Enter first number: ";
	cin >> d1;
	cout << "Enter second number: ";
	cin >> d2;
	cout << "Enter third number: ";
	cin >> d3;
	cout << "Enter forth number: ";
	cin >> d4;
	cout << "Max Value = (double) " << MaximumValue(d1, d2, d3, d4) << endl;

	char c1, c2, c3, c4;
	cout << "Enter first number: ";
	cin >> c1;
	cout << "Enter second number: ";
	cin >> c2;
	cout << "Enter third number: ";
	cin >> c3;
	cout << "Enter forth number: ";
	cin >> c4;
	cout << "Max Value = (char) " << MaximumValue(c1, c2, c3, c4) << endl;


	return 0;
}
