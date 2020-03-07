/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #5 - 3-tiered object oriented program
	2 / 23 / 20

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

	string getType();

	string getAttackText();

	string getDefenseText();
};

