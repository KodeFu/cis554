#include <iostream>
#include "Player.h"
#include "Hero.h"
#include "Arena.h"


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
	/*
    cout << "What is the hero's name? ";
    cin >> playerName;

    cout << "Player name? ";
    cin >> playerLevel;

    Hero hero(playerName, playerLevel);

    cout << hero.getLevel() << endl;
    hero.ass();

    Player* basePlayer = &hero;
	*/
    //basePlayer->ass();

    //Arena arena(playerName, enemy);
    //arena.turn();

	Player p1("hero", 1);
	Player p2("enemy", 1);

	Arena arena(p1, p2);

    bool dead = false;
    int turns = 0;
    do {

        cout << endl;
        cout << "Turn " << ++turns << endl;
        dead = arena.doBattle();
        

    } while (!dead);

    cout << "********************************************************" << endl;
    cout << "Final Stats" << endl;
    cout << endl;
    cout << "Turns: " << turns << endl;
    cout << p1.getName() << endl;
    cout << "  " << "hit points: " << p1.getHitPoints() << endl;
    cout << p2.getName() << endl;
    cout << "  " << "hit points: " << p2.getHitPoints() << endl;
    if (p1.getHitPoints() > 0)
    {
        cout << p1.getName() << " is the victor!" << endl;
    }
    else
    {
        cout << p2.getName() << " is the victor!" << endl;
    }
    cout << "********************************************************" << endl;
}
