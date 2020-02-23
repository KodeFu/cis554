/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #5 - 3-tiered object oriented program
	2 / 23 / 20

	This class implements a dice class which allows for
	pseudo-random rolls based on dice size.
*/
#include "Dice.h"
#include <cstdlib>

Dice::Dice(int sides)
	: _sides{sides}
{

}

int Dice::getSides()
{
	return _sides;
}

void Dice::setSides(int sides)
{
	_sides = sides;
}

int Dice::roll()
{
	return (1 + (rand() % _sides) );
}