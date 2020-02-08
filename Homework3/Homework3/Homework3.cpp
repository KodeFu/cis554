/*
    Mudit Vats
    CIS 554 - M401 Object Oriented Programming in C++
    Syracuse University
    HW #3 - Exercise 5.16 p206-207
    2 / 8 / 20

    This program is a simple bar chart program which takes input from the user for
    five bar charts. Once the input is recieved, the corresponding barcharts are
    displayed.

*/
#include <iostream>
#include <vector>
#include "BarChart.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    // create a vector of BarChart which will hold user inputted
    // barchart objects
    vector<BarChart> barChartList;
    int barChartValue;

    // print an awesome title
    std::cout << "Greatest Bar Chart Program EVER!!!" << endl;
    std::cout << "Enter a value and this program with plot the corresponding bar chart." << endl;
    
    // get user input
    cout << endl << "Chart input" << endl;
    for (int i = 0; i < 5; i++)
    {
        // get a value for each chart
        cout << "Please enter a value to chart (1-30): ";
        cin >> barChartValue;

        // add a new chart object initialized with the barChartValue to the barChartList
        barChartList.push_back(BarChart(barChartValue));
    }
    
    // display the bar charts
    cout << endl << "Barcharts" << endl;
    for (BarChart b : barChartList)
    {
        // dispaly the bar chart
        b.displayChart();
    }
            
}

