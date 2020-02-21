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
    string gameplayMode;
    string playerName;
    int playerLevel;

    cout << "Welcome to D&D Arena" << endl << endl;
    cout << "Where victory (or death) awaits!" << endl;

    cout << endl;
    cout << "Manual or auto battle? (\"m\" for manual or \"a\" for auto) ";
    cin >> gameplayMode;

    Player p1("Hero", 1);
    Player p2("Enemy", 1);

    if (gameplayMode == "m")
    {
        cout << "What is the hero's name? ";
        cin >> playerName;

        cout << "What is the here's level? (1-5) ";
        cin >> playerLevel;

        if ((playerLevel < 1) || (playerLevel > 5))
        {
            playerLevel = 1;
        }

        p1.setName(playerName);
        p1.setLevel(playerLevel);
        p2.setLevel(playerLevel);
    }


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
