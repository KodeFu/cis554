/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Project
    3 / 19 / 20

	This class implements the battle arena logic. It brings in the elements
	of the player data, performs the battles and displays statistics.
*/
#include "Arena.h"
#include "Dice.h"

using std::cout;
using std::endl;

Arena::Arena(Player& playerOne, Player& playerTwo)
	: _playerOne {playerOne}, _playerTwo {playerTwo}
{
	Dice twoSidedDie(2);

	(twoSidedDie.roll() == 1) ? _playerOneGoesFirst = true : _playerOneGoesFirst = false;
}

void Arena::setPlayerOne(Player& playerOne)
{
	_playerOne = playerOne;
}

void Arena::setPlayerTwo(Player& playerTwo)
{
	_playerTwo = playerTwo;
}

void Arena::showBattleBanner()
{
	cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl;
	cout << "Battle Arena has been set." << endl;
	cout << _playerOne.getName() << " the " << _playerOne.getType() << " will fight " << _playerTwo.getName() << " the " << _playerTwo.getType() << "." << endl;

	_playerOne.reset();
	_playerTwo.reset();
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

	cout << first->getName() << ": " << first->getHitPoints() << " - " << second->getName() << ": " << second->getHitPoints() << endl;
	int firstDamage = first->attack();

	// Note, first->getAttackText() will call derived class's getAttackText(), not the base Player class
	cout << first->getAttackText() << first->getName() << " does " << firstDamage << " damage." << endl;

	int secondDefense = second->defend(firstDamage);

	// Note, first->getDefenseText() will call derived class's getDefenseText(), not the base Player class
	cout << second->getDefenseText() << second->getName() << " blocks " << secondDefense << " damage and now has " << second->getHitPoints() << " hit points.";

	// output dead status if second player dead
	if (second->getHitPoints() <= 0)
	{
		cout << " " << second->getName() << " is now Dead! :-(";
	}
	cout << endl;

	// only continue battle if second player is alive
	if (second->getHitPoints())
	{
		int secondDamage = second->attack();
		cout << second->getAttackText() << second->getName() << " does " << secondDamage << " damage." << endl;

		int firstDefense = first->defend(secondDamage);
		cout << first->getDefenseText() << first->getName() << " blocks " << firstDefense << " damage and now has " << first->getHitPoints() << " hit points.";

		// output dead status if first player dead
		if (first->getHitPoints() <= 0)
		{
			cout << " " << first->getName() << " is now Dead! :-(";
			cout << endl;
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

void Arena::showVictoryMessage()
{
	// only continue battle if second player is alive
	cout << endl;
	if ( _playerOne.getHitPoints() )
	{
		cout << "-->" << _playerOne.getName() << " is the victor, beating " << _playerTwo.getName() << "." << endl;
	}
	else if (_playerTwo.getHitPoints())
	{
		cout << "-->" << _playerTwo.getName() << " is the victor, beating " << _playerOne.getName() << "." << endl;
	}
	cout << endl;
}