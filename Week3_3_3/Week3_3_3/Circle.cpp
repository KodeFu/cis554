#include "Circle.h"
#include <cmath>

Circle::Circle(double radius)
	: _radius{radius}
{

}

double Circle::getDiameter()
{
	return _radius * 2.0;
}

double Circle::getCircumference()
{
	return 2.0 * PI * _radius;
}

double Circle::getArea()
{
	return PI * pow(_radius, 2);
}