///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 2 - Modify Simple Program
///////////////////////////////////////////////
#include "pch.h"
#include <iostream>

int main()
{
	// declare the variables needed for our program
	int integerVariable1 = 5;
	int integerVariable2 = 10;
	int integerVariable3 = 15;
	int integerResult = 0;

	// perform our addition
	integerResult = integerVariable1 + integerVariable2 + integerVariable3;

	// print a simple message to our standard output device (display attached
	// to this computer)
	std::cout << "Welcome to C++ !" << std::endl;
	std::cout 
		<< integerVariable1 
		<< " + " 
		<< integerVariable2 
		<< " + "
		<< integerVariable3
		<< " = " 
		<< integerResult 
		<< std::endl;

	// return a status value
	return 0;
}
