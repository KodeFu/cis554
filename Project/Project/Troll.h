/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Project
    3 / 19 / 20

	This class derives from Player class to customize the
	Troll class.
*/
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

