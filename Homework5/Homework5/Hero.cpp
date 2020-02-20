#include "Hero.h"

using std::string;
using std::cout;
using std::endl;

Hero::Hero(string name, int level)
{
	cout << "hero constructor" << endl;

	setName(name);
	setLevel(level);

}

void Hero::ass()
{
	cout << "hero ass" << endl;
}