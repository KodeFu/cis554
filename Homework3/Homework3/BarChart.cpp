/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #3 - Exercise 5.16 p206-207
	2 / 8 / 20

	This class defines the members and function prototypes for the BarChart
	class which is used to store the value and display barcharts.

*/
#include "BarChart.h"

#include <iostream>

using std::cout;
using std::endl;

// constructor which initializes the BarChart object with the num of elements;
// i.e. bar chart value
BarChart::BarChart(int numElements)
	: _numElements{numElements}
{

}

// get number of elements
int BarChart::getNumElements()
{
	return _numElements;
}

// set number of elements
void BarChart::setNumElements(int numElements)
{
	_numElements = numElements;
}

// validate elements range
bool BarChart::validateElements()
{
	if ((_numElements < 0) || (_numElements > 30))
	{
		return false;
	}

	return true;
}

// display bar chart
void BarChart::displayChart()
{
	cout << _numElements << ": "; 

	// check for valid element range
	if (!validateElements())
	{
		cout << "value out of range :-(" << endl;
		return;
	}

	// display bar chart
	for (int i = 0; i < _numElements; i++)
	{
		cout << "*";
	}

	cout << endl;
}