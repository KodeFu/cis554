/*

This homework required the use of a three-tier architecture for a project of our
choosing. I chose to implement a D&D style battle arena where a hero and an enemy
can duke it out for supremancy.

The three tiers as in viewed like a Model-View-Controller or Presentation, Logic
or Data tiers would be described as -
1. Presentation - main.cpp and Arena.h/cpp. These are main() function which gets
   input from the user and creates the Arena() class to performs the battles. Some
   presentation is performed by the Arena() class as well.
2. Logic - This would be the Arena class which accesses the Player data to 
   perform the battle actions, including attack and defense.
3. Data - Player() class in Player.h/.cpp, such as, Hero() class in Hero.h/.cpp, 
   Dragon() class Dragon.h/.cpp, Troll() class in Troll.h/.cpp, and Orc() class in
   Orc.h/.cpp.

 These techniques demonstrated:
 - Pass by value when setting player Name and Level.
 - std::array used to store enemy data (orc, troll, dragon)
 - std::vector shown when battling in "auto" mode. A vector of Arena type is created.
 - For loop used to initialize arena vector.
 - Range-based for loop used to traverse arena vector.
 - Pass by reference is use when players are passed to the Arena constructor so that 
   Player contents can be modified by Arena.
 - Pass by pointer

 *BONUS* demonstration:
 - Inheritance. Player is the base class for Hero, Dragon, Troll and Orc.
 - Virtual functions are used to provide Hero, Dragon, Troll and Orc specific 
   attack and defense text. We call the Player objects getAttackText() for 
   example, which is empty, and if the derivied class has an implementation
   of the getAttackText() virtual function, it will be executed. Very neat!
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <array>
#include <thread>
#include "Player.h"
#include "Hero.h"
#include "Dragon.h"
#include "Orc.h"
#include "Troll.h"
#include "Arena.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::array;

int main()
{
    string gameplayMode;

    // initialize PRNG
    srand(time(NULL));

    // initialize enemies
    array<Player *, 4> enemies;
    enemies[0] = &Player("Jeff", 1);
    enemies[1] = &Dragon("Don", 1);
    enemies[2] = &Orc("Ollie", 1);
    enemies[3] = &Troll("Tommy", 1);

    cout << "Welcome to Ba-Zork Battle Arena Simulation" << endl << endl;
    cout << "Where victory (or death) awaits!" << endl;

    cout << endl;
	cout << \
		"This game allows you to simulate one-on-one battles, D&D style. Attacks and" << endl;
	cout << \
		"blocks are random so victory is never a sure thing. You play a Hero who can battle" << endl;
	cout << \
		"an Orc, Troll, or, the most vicious, Dragon! Do you have what it takes?" << endl;

    cout << endl;
    cout << "Manual or auto battle? (\"m\" for manual or \"a\" for auto) ";
    cin >> gameplayMode;
    cout << endl;

    if (gameplayMode == "m")
    {
        string playerName;
        int playerLevel;
        Hero p1("Hero", 1);
        //Dragon p2("Deathwing", 1);
		Troll p2("Drobney", 1);

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

            // sleep for a second to digest battle text
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        } while (!dead);

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
            //Player *p1 = new Player("Syd", 1);
			Hero* p1 = new Hero("Mistress Nancy", 1);
            Dragon *p2 = new Dragon("Syd the Dragon", 1);
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
