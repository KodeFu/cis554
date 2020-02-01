/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 4_1 - Switch Statements
/////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << endl << "Part A: No print after Wednesday!" << endl;
	for (int currentDay = 1; currentDay <= 7; currentDay++)
	{
		switch (currentDay)
		{
		case 1:
			cout << "Day " << currentDay << " = Sunday" << endl;
			break;
		case 2:
			cout << "Day " << currentDay << " = Monday" << endl;
			break;
		case 3:
			cout << "Day " << currentDay << " = Tuesday" << endl;
			break;
		case 4:
			cout << "Day " << currentDay << " = Wednesday" << endl;
			break;
		case 5:
			continue;
			// Weird example since we can just not handle cases 5-7 and then
			// use a default case to continue...
			// Weird again... would normally remove the cout and break below, but
			// then we would be doing nothing in these cases so goes back to the
			// previous point.
			// Weird / odd exercise.
			cout << "Day " << currentDay << " = Thursday" << endl;
			break;
		case 6:
			continue;
			cout << "Day " << currentDay << " = Friday" << endl;
			break;
		case 7:
			continue;
			cout << "Day " << currentDay << " = Saturday" << endl;
			break;
		default: cout << "Not an allowable day number";
			continue;
			break;
		}
	}

	cout << endl << "Part A: Don't print Thursday!" << endl;
	for (int currentDay = 1; currentDay <= 7; currentDay++)
	{
		switch (currentDay)
		{
		case 1:
			cout << "Day " << currentDay << " = Sunday" << endl;
			break;
		case 2:
			cout << "Day " << currentDay << " = Monday" << endl;
			break;
		case 3:
			cout << "Day " << currentDay << " = Tuesday" << endl;
			break;
		case 4:
			cout << "Day " << currentDay << " = Wednesday" << endl;
			break;
		case 5:
			// Weird exercise. Would normally let the default case handle this
			// and completely remove it. But ok...
			continue;
			cout << "Day " << currentDay << " = Thursday" << endl;
			break;
		case 6:
			cout << "Day " << currentDay << " = Friday" << endl;
			break;
		case 7:
			cout << "Day " << currentDay << " = Saturday" << endl;
			break;
		default: cout << "Not an allowable day number";
			break;
		}
	}

	return 0;
}
