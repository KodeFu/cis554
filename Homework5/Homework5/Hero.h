#pragma once
#include "Player.h"

class Hero :
	public Player
{
public:
	Hero(string name, int level);

	string getType();

	string getAttackText();

	string getDefenseText();

private:
	
};

