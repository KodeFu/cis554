#pragma once
#include "Player.h"

class Arena
{
public:
	Arena(Player playerOne, Player playerTwo);

private:
	Player _playerOne;
	Player _playerTwo;
};

