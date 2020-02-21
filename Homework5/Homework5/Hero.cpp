#include "Hero.h"

using std::string;
using std::cout;
using std::endl;

Hero::Hero(string name, int level)
	: Player(name, level)
{

}

void Hero::ass()
{
	cout << "hero ass" << endl;
}