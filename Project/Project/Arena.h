/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #5 - 3-tiered object oriented program
	2 / 23 / 20

	This class defines the battle arena logic. It brings in the elements
	of the player data, performs the battles and displays statistics.
*/
#pragma once
#include "Player.h"

class Arena
{
public:
	Arena(Player& playerOne, Player& playerTwo);

	void setPlayerOne(Player& playerOne);
	void setPlayerTwo(Player& playerTwo);

	void showBattleBanner();
	bool doBattle();

	void showVictoryMessage();

private:
	bool _playerOneGoesFirst;
	Player& _playerOne;
	Player& _playerTwo;
};

