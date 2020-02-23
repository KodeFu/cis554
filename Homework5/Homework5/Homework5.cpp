/*
    Mudit Vats
    CIS 554 - M401 Object Oriented Programming in C++
    Syracuse University
    HW #5 - 3-tiered object oriented program
    2 / 23 / 20

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
     - std::array used to store enemy data (orc, troll, dragon).
     - std::vector shown when battling in "auto" mode. A vector of Arena type is created.
     - For loop used to initialize arena vector.
     - Range-based for loop used to traverse arena vector.
     - Pass by reference is use when players are passed to the Arena constructor so that 
       Player contents can be modified by Arena. Also assign references of enemy objects
       to enemy array.
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
#include <string>
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
using std::stoi;

const int maximumEnemies = 4; // maximum number of enemies

// show victory message function used to demonstate pointer passing; here
// arena is an Arena* which gets passed to the function.
void showVictoryMessages(Arena* arena);

int main()
{
    string playerName;
    string input;
    int playerLevel;
    string gameplayMode;

    // initialize PRNG
    srand(time(NULL));

    // initialize enemies
    array<Player *, 4> enemies;  // allocate pointers to enemies

    // assign refernece to player objects to enemies; could be done 
    // with new/pointer, but using C++ references here
    Player player = Player("Evil Jeff", 1);
    Dragon dragon = Dragon("Deathwing", 1);
    Orc orc = Orc("Azog the Terrible", 1);
    Troll troll = Troll("Grendel", 1);
    enemies.at(0) = &player;
    enemies.at(1) = &dragon;
    enemies.at(2) = &orc;
    enemies.at(3) = &troll;

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

    cout << "What is the hero's name? ";
    cin >> playerName;
    cout << endl;

    // get hero level
    bool validInput = false;
    do
    {
        cout << "What is the hero's level? (1-5) ";
        cin >> input;

        // check if a valid integer
        try {
            playerLevel = std::stoi(input);
            if (playerLevel > 0 && playerLevel <= 5)
            {
                validInput = true;
            }
        }
        catch (...)
        {
            cout << "brrrp! ... bad mojo" << endl;
        }

    } while (!validInput);
    cout << endl;
    
    // Set up hero info
    Hero hero(playerName, playerLevel);

    if (gameplayMode == "m")
    {
        int enemyType;        
     

        // get enemy type
        bool validInput = false;
        do
        {
            cout << "Who would you like to fight (1=Human, 2=Dragon, 3=Orc, 4=Troll)? ";
            cin >> input;

            // check if a valid integer
            try {
                enemyType = std::stoi(input) - 1;
                if (enemyType >= 0 && enemyType<4)
                {
                    validInput = true;
                }
            }
            catch (...)
            {
                cout << "brrrp! ... bad mojo" << endl;
            }

        } while (!validInput);
        cout << endl;

        // set enemy level based on player level
        enemies.at(enemyType)->setLevel(playerLevel);

        // start the arena!
        Arena arena(hero, *enemies.at(enemyType));

        bool dead = false;
        int turns = 0;

        // show the battle banner; i.e. A vs B
        arena.showBattleBanner();

        do {

            cout << endl;
            cout << "Turn " << ++turns << endl;

            // battle!
            dead = arena.doBattle();

            // sleep for a second to digest battle text
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        } while (!dead);

        arena.showVictoryMessage();
    }

    if (gameplayMode == "a")
    {
        // create several battle arenas
        vector<Arena*> arenaList;
        for (int i = 0; i < 10; i++)
        {
            // radomize an enemy to fight, also use same level as hero
            int randomEnemy = rand() % maximumEnemies;
            enemies.at(randomEnemy)->setLevel(playerLevel);
            Arena *tmp = new Arena(hero, *enemies.at(randomEnemy));

            // add the new arena to the list
            arenaList.push_back(tmp);
        }

        // battle each arena
        for (Arena* arena : arenaList)
        {
            bool dead = false;
            int turns = 0;
          
            // show the battle banner; i.e. A vs B
            arena->showBattleBanner();

            do {

                cout << endl;
                cout << "Turn " << ++turns << endl;

                // battle!
                dead = arena->doBattle();

            } while (!dead);

            // show victory message
            showVictoryMessages(arena);
        }

    }
}

void showVictoryMessages(Arena* arena)
{
    // show the battle banner; i.e. A vs B
    arena->showVictoryMessage();
}