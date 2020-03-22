/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Project
    3 / 19 / 20

	This class derives from Player class to customize the
	Dragon class.
*/
#pragma once
#include "Player.h"

class Dragon :
	public Player
{
public:
	Dragon(string name, int level);

	virtual string getType() override;

	virtual int specialAttack() override;

	virtual string getAttackText() override;

	virtual string getDefenseText() override;
};

