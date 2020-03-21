/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Project
    3 / 19 / 20

	This class implements the player class. This class is the base class for
	many other player types. The common functionality is provided here
	inlcluding hitpoints, levels, attack and defense. Also, two virtual
	functions provide the abilty for derived classes to implement their
	own attack and defense messages.
*/
#include "Player.h"

using std::cout;
using std::endl;

Player::Player()
	: _name{ "" }, _level{ 1 }, _hitPoints{ _baseHitPoints }, _dice{ _baseHitPoints }
{

}

Player::Player(string name, int level)
	: _name {name}, _level{level}, _hitPoints{level * _baseHitPoints}, _dice{_baseHitPoints}
{

}

void Player::reset()
{
	setHitPoints(getLevel() * getBaseHitPoints());
}

// name getter and setter
string Player::getName()
{
	return _name;
}

void Player::setName(string name)
{
	_name = name;
}

// level getter and setter
int Player::getLevel()
{
	return _level;
}

void Player::setLevel(int level)
{
	_level = level;
}

int Player::getHitPoints()
{
	return _hitPoints;
}

void Player::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

int Player::getBaseHitPoints()
{
	return _baseHitPoints;
}

string Player::getAttackText()
{
	return "";
}

string Player::getDefenseText()
{
	return "";
}

int Player::attack()
{
	// can only attack up to base hit points
	_dice.setSides(getBaseHitPoints() / 2);
	int damage = _dice.roll();

	return damage;
}

int Player::specialAttack()
{
	// by default, no special attack
	return 0;
}

int Player::defend(int attack)
{
	// can only defend up to half the base hit points
	_dice.setSides(getBaseHitPoints() / 4);
	int defendRoll = _dice.roll();

	int finalDamage = attack - defendRoll;
	if (finalDamage < 0)
	{
		finalDamage = 0;
	}

	// adjust hit points based on the damage
	if (getHitPoints() - finalDamage < 0)
	{
		setHitPoints(0);
	}
	else
	{
		setHitPoints(getHitPoints() - finalDamage);
	}

	// return the defense amount
	return defendRoll;
}