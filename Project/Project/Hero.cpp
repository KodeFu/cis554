/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Project
    3 / 19 / 20

	This class derives from Player class to customize the
	Hero class.
*/
#include "Hero.h"

using std::string;
using std::cout;
using std::endl;

Hero::Hero(string name, int level)
	: Player(name, level)
{

}

string Hero::getType()
{
	return "Human";
}

string Hero::getAttackText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + " tears down the world! ";
		break;
	case 1:
		attackText = getName() + " increases focus. ";
		break;
	case 2:
		attackText = getName() + " give's it all! ";
		break;
	case 3:
		attackText = getName() + " gives the eye of the tiger. ";
		break;
	case 4:
	default:
		attackText = getName() + " summons the ancients! ";
		break;
	}
	
	return attackText;
}

string Hero::getDefenseText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + " anticipates the enemy! ";
		break;
	case 1:
		attackText = getName() + " cushions the blow. ";
		break;
	case 2:
		attackText = getName() + " bobs and weaves. ";
		break;
	case 3:
		attackText = getName() + " hits the deck! ";
		break;
	case 4:
	default:
		attackText = getName() + " skillfully parrys the attack! ";
		break;
	}

	return attackText;
}