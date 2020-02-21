#pragma once
#include "Player.h"

class Arena
{
public:
	Arena(Player& playerOne, Player& playerTwo);
	bool doBattle();

private:
	bool _playerOneGoesFirst;
	Player& _playerOne;
	Player& _playerTwo;
};

