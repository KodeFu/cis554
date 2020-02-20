#include "Player.h"

using std::cout;
using std::endl;

Player::Player()
	: _name {"nomo"}, _level{1}, _hitPoints{100}
{
	cout << "player constructor" << endl;
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

void Player::ass()
{
	cout << "base ass" << endl;
}