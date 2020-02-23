#pragma once
#include "Player.h"

class Dragon :
	public Player
{
public:
	Dragon(string name, int level);

	string getType();

	string getAttackText();

	string getDefenseText();
};

