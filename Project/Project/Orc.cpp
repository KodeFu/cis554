/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #5 - 3-tiered object oriented program
	2 / 23 / 20

	This class derives from Player class to customize the
	Orc class.
*/
#include "Orc.h"
using std::string;
using std::cout;
using std::endl;

Orc::Orc(string name, int level)
	: Player(name, level)
{

}

string Orc::getType()
{
	return "Orc";
}

string Orc::getAttackText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + " swings with great might! ";
		break;
	case 1:
		attackText = getName() + " feels no pain. ";
		break;
	case 2:
		attackText = getName() + " calls on the power Sauran! ";
		break;
	case 3:
		attackText = getName() + " yells something Orcish \"Yogundish flakamesh!\" ";
		break;
	case 4:
	default:
		attackText = getName() + " seethes with anger! ";
		break;
	}

	return attackText;
}

string Orc::getDefenseText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + " feels no pain! ";
		break;
	case 1:
		attackText = getName() + " calls upon a Cerabus, the demon dog! ";
		break;
	case 2:
		attackText = getName() + " uses Jeff the Goblin as a shield! ";
		break;
	case 3:
		attackText = getName() + " spews black tar! ";
		break;
	case 4:
	default:
		attackText = getName() + " takes a bite of jerkie. Nothing can hurt me! ";
		break;
	}

	return attackText;
}