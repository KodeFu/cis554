#pragma once
class BarChart
{
public:
	// constructor used to initialze new BarChart object
	BarChart(int numElements);

	// getter and setter for number of elements
	int getNumElements();
	void setNumElements(int numElements);

	// getter and setter for graph character; default is asterick '*'
	char getGraphCharacter();
	void setGraphCharacter(char graphCharacter);

	// display bar chart
	void displayChart();

	


private:
	// validator function
	bool validateElements();

	// member variabiles
	char _graphCharacter;
	int _numElements;
};

