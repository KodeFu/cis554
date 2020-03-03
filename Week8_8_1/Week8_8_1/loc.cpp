///////////////////////////////////////////////////////////
// loc.cpp
// CIS554 Object Oriented Programming in C++
// Exercise 8_1 - Operator Overloading - member functions
//                Class loc implementation
///////////////////////////////////////////////////////////

#include "loc.h"

loc::loc(int lon, int lat)
	: longitude(lon), latitude(lat)
{}

void loc::show()
{
	cout << longitude << " ";
	cout << latitude << "\n";
}

// Overload + for loc.
loc loc::operator+(loc op2)
{
	loc temp;

	temp.longitude = op2.longitude + longitude;
	temp.latitude = op2.latitude + latitude;

	return temp;
}
/*
// Overload + for loc.
loc loc::operator+=(loc op2)
{
	loc temp;

	temp.longitude = longitude + op2.longitude;
	temp.latitude += latitude + op2.latitude;

	return temp;
}
*/
// Overload + for loc.
loc operator+=(loc op1, loc op2)
{
	loc temp;

	temp.longitude = op1.longitude + op2.longitude;
	temp.latitude += op1.latitude + op2.latitude;

	return temp;
}