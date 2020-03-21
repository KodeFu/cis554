/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Project
    3 / 19 / 20

	This class defines the player class. This class is the base class for
	many other player types. The common functionality is provided here
	inlcluding hitpoints, levels, attack and defense. Also, two virtual
	functions provide the abilty for derived classes to implement their
	own attack and defense messages.
*/
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

	
	// level getter and setter
	int getLevel();
	void setLevel(int level);

	// hit point getter and setter
	int getHitPoints();
	void setHitPoints(int hitPoints);

	// return base hit points
	int getBaseHitPoints();

	// attack function
	int attack();

	// defend function
	int defend(int attack);

	// reset player to max hitpoints
	void reset();

	/////////////////////////////////
	// Virtual Functions
	/////////////////////////////////

	// get type of player (class or race)
	virtual string getType() = 0;      // must implement this function

	// special attack
	virtual int specialAttack();       // optional special attack

	// customize messages
	virtual string getAttackText();    // optional attack text
	virtual string getDefenseText();   // optional defense text

private:
	string _name;     // player name
	int   _level;     // player level
	int   _hitPoints; // player hitpoints
	Dice  _dice;      // dice used for rolls

	static const int _baseHitPoints = 10; // base hitpoints factor
};

