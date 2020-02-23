#pragma once
#include <iostream>
#include "Dice.h"

using std::string;

class Player
{
public:
	Player();
	Player(string name, int level);

	// name getter and setter
	string getName();
	void setName(string name);

	// get type of player (class or race)
	virtual string getType();

	// level getter and setter
	int getLevel();
	void setLevel(int level);

	// hit point getter and setter
	int getHitPoints();
	void setHitPoints(int hitPoints);

	int attack();
	int defend(int attack);

	// reset player
	void reset();

	virtual string getAttackText();
	virtual string getDefenseText();

private:
	string _name;
	int _level;
	int _hitPoints;
	Dice _dice;

	static const int _baseHitPoints = 10;
};

