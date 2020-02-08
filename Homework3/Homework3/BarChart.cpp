#include "BarChart.h"

#include <iostream>

using std::cout;
using std::endl;

BarChart::BarChart(int numElements)
	: _numElements{numElements}
{
	// default graph character is askterick
	// user can overrirde with setGraphcCharacter()
	_graphCharacter = '*';
}

int BarChart::getNumElements()
{
	return _numElements;
}

void BarChart::setNumElements(int numElements)
{
	_numElements = numElements;
}

char BarChart::getGraphCharacter()
{
	return _graphCharacter;
}

void BarChart::setGraphCharacter(char graphCharacter)
{
	_graphCharacter = graphCharacter;
}

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
	if (!validateElements())
	{
		return;
	}

	for (int i=0; i<_numElements; i++)
	{
		cout << _graphCharacter;
	}

	cout << endl;
}