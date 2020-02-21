#pragma once
#include "Player.h"

class Arena
{
public:
	Arena(Player& playerOne, Player& playerTwo);

	void setPlayerOne(Player& playerOne);
	void setPlayerTwo(Player& playerTwo);

	bool doBattle();

	// final stats class
	class finalStats {
	public:
		finalStats();
		int attacks;

	};

private:
	bool _playerOneGoesFirst;
	Player& _playerOne;
	Player& _playerTwo;
};

