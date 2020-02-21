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

