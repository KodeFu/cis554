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