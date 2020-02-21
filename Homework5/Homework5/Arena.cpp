#include "Arena.h"
#include "Dice.h"

Arena::Arena(Player& playerOne, Player& playerTwo)
	: _playerOne {playerOne}, _playerTwo {playerTwo}
{
	Dice twoSidedDie(2);

	(twoSidedDie.roll() == 1) ? _playerOneGoesFirst = true : _playerOneGoesFirst = false;
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
	int secondDefense = second->defend(firstDamage);

	// only continue battle if second player is alive
	if (second->getHitPoints())
	{
		int secondDamage = second->attack();
		int firstDefense = first->defend(secondDamage);
	}
	
	// if either player are dead, return true; i.e. dead!
	if (!first->getHitPoints() || !second->getHitPoints())
	{
		return true;
	}

	// both players are still alive
	return false;
}