/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 4_3 - Logical operators
/////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	bool bool1 = true;
	bool bool2 = true;
	bool bool3 = false;
	bool bool4 = false;

	// Semi ambiguous--
	//
	// Interpretting "regardless of the value of bool2 and bool4" as a
	// we don't care about evaluating whether either value is true or falese.
	// If that is the case, we remove the evaluation of those variables.
	// The if / else execute the else branch since bool1 && bool3 evaluate
	// to false.

	if ((bool1 && bool3))
	{
		cout << "Expression is TRUE" << endl;
	}
	else
	{
		cout << "Expression is FALSE" << endl;
	}

	return 0;
}
