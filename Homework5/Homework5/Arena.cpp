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
	cout << first->getAttackText() << first->getName() << " does " << firstDamage << " damage." << endl;

	int secondDefense = second->defend(firstDamage);
	cout << second->getDefenseText() << second->getName() << " blocks " << secondDefense << " damage and now has " << second->getHitPoints() << " hit points.";
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
		if (first->getHitPoints() <= 0)
		{
			cout << " " << first->getName() << " is now Dead! :-(";
			cout << endl;
			cout << second->getName() << " is the victor!" << endl;
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
