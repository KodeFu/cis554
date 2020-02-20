#pragma once
#include <iostream>

using std::string;

class Player
{
public:
	Player();

	// name getter and setter
	string getName();
	void setName(string name);

	// level getter and setter
	int getLevel();
	void setLevel(int level);

	// hit point getter and setter
	int getHitPoints();
	void setHitPoints(int hitPoints);

	virtual void ass();

private:
	string _name;
	int _level;
	int _hitPoints;
};

