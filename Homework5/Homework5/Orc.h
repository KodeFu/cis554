#pragma once
#include "Player.h"
class Orc :
	public Player
{
public:
	Orc(string name, int level);

	string getType();

	string getAttackText();

	string getDefenseText();
};

