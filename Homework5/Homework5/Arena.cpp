#include "Arena.h"
#include "Dice.h"

using std::cout;
using std::endl;

Arena::Arena(Player& playerOne, Player& playerTwo)
	: _playerOne {playerOne}, _playerTwo {playerTwo}
{
	Dice twoSidedDie(2);

	(twoSidedDie.roll() == 1) ? _playerOneGoesFirst = true : _playerOneGoesFirst = false;

	cout << _playerOneGoesFirst << endl;
}

void Arena::setPlayerOne(Player& playerOne)
{
	_playerOne = playerOne;
}

void Arena::setPlayerTwo(Player& playerTwo)
{
	_playerTwo = playerTwo;
}

bool Arena::doBattle()
{
	Player* first;
	Player* second;

	// battle in order depending on who went first
	if (_playerOneGoesFirst)
	{
		first = &_playerOne;
		second = &_playerTwo;
	}
	else
	{
		first = &_playerTwo;
		second = &_playerOne;
	}

	int firstDamage = first->attack();
	cout << first->getName() << " does " << firstDamage << " damage." << endl;

	int secondDefense = second->defend(firstDamage);
	cout << second->getName() << " blocks " << secondDefense << " damage and now has " << second->getHitPoints() << " hit points.";
	if (second->getHitPoints() <= 0)
	{
		cout << " " << second->getName() << " is now " << " Dead! :-(";
	}
	cout << endl;


	// only continue battle if second player is alive
	if (second->getHitPoints())
	{
		int secondDamage = second->attack();
		cout << second->getName() << " does " << secondDamage << " damage." << endl;

		int firstDefense = first->defend(secondDamage);
		cout << first->getName() << " blocks " << firstDefense << " damage and now has " << first->getHitPoints() << " hit points.";
		if (first->getHitPoints() <= 0)
		{
			cout << " " << first->getName() << " is now " << " Dead! :-(";
		}
		cout << endl;
	}
	
	// if either player are dead, return true; i.e. dead!
	if (!first->getHitPoints() || !second->getHitPoints())
	{
		return true;
	}

	// both players are still alive
	return false;
}

Arena::finalStats::finalStats()
	: attacks{ 0 }
{

}