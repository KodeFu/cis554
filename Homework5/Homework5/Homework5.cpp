#include <iostream>
#include <vector>
#include <ctime>
#include "Player.h"
#include "Hero.h"
#include "Arena.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string gameplayMode;

    // initialize PRNG
    srand(time(NULL));

    cout << "Welcome to Ba-Zork Battle Arena Simulation" << endl << endl;
    cout << "Where victory (or death) awaits!" << endl;

    cout << endl;
    cout << "This game allows you to simulate one-on-one battles, D&D style. Attacks and blocks are random so victory is never a sure thing." << endl;

    cout << endl;
    cout << "Manual or auto battle? (\"m\" for manual or \"a\" for auto) ";
    cin >> gameplayMode;

    if (gameplayMode == "m")
    {
        string playerName;
        int playerLevel;
        Player p1("Hero", 1);
        Player p2("Enemy", 1);

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
    if (gameplayMode == "a")
    {
        // create several battle arenas
        vector<Arena*> arenaList;
        for (int i = 0; i < 10; i++)
        {
            // we use pointers here since we need to allocate new players
            // and new arenas for battle; we don't use static alloction since
            // player and arena instance data would be retained and we don't
            // want that.
            Player *p1 = new Player("Syd", 1);
            Player *p2 = new Player("Nancy", 1);
            Arena *tmp = new Arena(*p1, *p2);

            // add the new arena to the list
            arenaList.push_back(tmp);
        }

        // battle each arena
        for (Arena* arena : arenaList)
        {
            bool dead = false;
            int turns = 0;
            do {

                cout << endl;
                cout << "Turn " << ++turns << endl;
                dead = arena->doBattle();

            } while (!dead);
        }
    }


}
