/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Project
    3 / 19 / 20

	This class derives from Player class to customize the
	Dragon class.
*/
#include "Dragon.h"
using std::string;
using std::cout;
using std::endl;

Dragon::Dragon(string name, int level)
	: Player(name, level)
{

}

string Dragon::getType()
{
	return "Dragon";
}

string Dragon::getAttackText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + " shoots a blaze of fire! ";
		break;
	case 1:
		attackText = getName() + " gives a hearty dose of dragon breath... ";
		break;
	case 2:
		attackText = getName() + " summons the spirits of Puff, Smaug and the Never Ending Story dog-dragon thing! ";
		break;
	case 3:
		attackText = getName() + " employs the dragon tail sweep! ";
		break;
	case 4:
	default:
		attackText = getName() + " seethes with anger! ";
		break;
	}

	return attackText;
}

string Dragon::getDefenseText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + "'s scales can't be touched! ";
		break;
	case 1:
		attackText = getName() + " fly's away. ";
		break;
	case 2:
		attackText = getName() + " creates a wing defense. ";
		break;
	case 3:
		attackText = getName() + " speaks in very elequent English tongue which really throws off the enemy! ";
		break;
	case 4:
	default:
		attackText = getName() + " takes one for the team. May the dragons rest in peace. ";
		break;
	}

	return attackText;
}