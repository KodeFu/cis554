/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #3 - Exercise 5.16 p206-207
	2 / 8 / 20

	This class defines the members and function prototypes for the BarChart
	class which is used to store the value and display barcharts.

*/
#pragma once
class BarChart
{
public:
	// constructor used to initialze new BarChart object
	BarChart(int numElements);

	// getter and setter for number of elements
	int getNumElements();
	void setNumElements(int numElements);

	// display bar chart
	void displayChart();

private:
	// validator function
	bool validateElements();

	// member variabiles
	int _numElements;
};

