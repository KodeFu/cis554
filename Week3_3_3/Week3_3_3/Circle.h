#pragma once
class Circle
{
public:
	Circle(double radius);
	double getDiameter();
	double getCircumference();
	double getArea();

private:
	double _radius;

	const double PI = 3.14159;
};

