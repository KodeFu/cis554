#include "Troll.h"
using std::string;
using std::cout;
using std::endl;

Troll::Troll(string name, int level)
	: Player(name, level)
{

}

string Troll::getType()
{
	return "Troll";
}

string Troll::getAttackText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + " grunts with glee! ";
		break;
	case 1:
		attackText = getName() + " eggs someone on in an internet forum! ";
		break;
	case 2:
		attackText = getName() + " swings at everything in sight. ";
		break;
	case 3:
		attackText = getName() + " thinks happy thoughts. ";
		break;
	case 4:
	default:
		attackText = getName() + " crushes it! ";
		break;
	}

	return attackText;
}

string Troll::getDefenseText()
{
	string attackText;

	int randomCase = rand() % 5;

	switch (randomCase)
	{
	case 0:
		attackText = getName() + " hides under a bridge! ";
		break;
	case 1:
		attackText = getName() + " uses his head as a shield! ";
		break;
	case 2:
		attackText = getName() + " turns to stone. ";
		break;
	case 3:
		attackText = getName() + " belches loudly. ";
		break;
	case 4:
	default:
		attackText = getName() + " slathers in SPF 100. ";
		break;
	}

	return attackText;
}