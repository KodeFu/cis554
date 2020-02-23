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

private:
	bool _playerOneGoesFirst;
	Player& _playerOne;
	Player& _playerTwo;
};

