#pragma once
#include "Player.h"
class Troll :
	public Player
{
public:
	Troll(string name, int level);

	string getType();

	string getAttackText();

	string getDefenseText();
};

