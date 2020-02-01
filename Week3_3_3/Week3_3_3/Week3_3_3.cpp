// Week3_3_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Circle.h"


int main()
{
    double radius;

    std::cout << "input a radius: ";
    std::cin >> radius;

    if (radius < 0)
    {
        return 0;
    }

    Circle circle(radius);
    
    std::cout << "diameter:      " << circle.getDiameter() << std::endl;
    std::cout << "circumference: " << circle.getCircumference() << std::endl;
    std::cout << "area:          " << circle.getArea() << std::endl;
}
