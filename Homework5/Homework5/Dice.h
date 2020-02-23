/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #5 - 3-tiered object oriented program
	2 / 23 / 20

	This class implements a dice class which allows for
	pseudo-random rolls based on dice size.
*/
#pragma once
class Dice
{
public:
	Dice(int sides);

	// getter and setter for sides
	int getSides();
	void setSides(int sides);

	// roll the dice!
	int roll();

private:
	int _sides;
};

