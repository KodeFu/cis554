#include <iostream>
#include "Player.h"
#include "Hero.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string playerName;
    int playerLevel;

    cout << "Welcome to D&D Arena" << endl << endl;
    cout << "Where victory (or death) awaits!" << endl;

    cout << "What is the hero's name? ";
    cin >> playerName;

    cout << "Player name? ";
    cin >> playerLevel;

    Hero hero(playerName, playerLevel);

    cout << hero.getLevel() << endl;
    hero.ass();

    Player* basePlayer = &hero;
    basePlayer->ass();

    //Arena arena(playerName, enemy);
    //arena.turn();
}
