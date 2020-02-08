// Homework3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "BarChart.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<BarChart> barChartList;

    std::cout << "Greatest Bar Chart Program EVER!!!\n";

    BarChart bc(10);

    bc.displayChart();
}