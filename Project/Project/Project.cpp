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
     - std::array used to store enemy data (human, orc, troll, dragon).
     - std::vector shown when battling in "auto" mode. A vector of Arena type is created.
     - For loop used to initialize arena vector.
     - Range-based for loop used to traverse arena vector.
     - Pass by reference is use when players are passed to the Arena constructor so that 
       Player contents can be modified by Arena. Also assign references of enemy objects
       to enemy array.
     - Pass by value shown when initializing Dice. We set side by passing in int value.
     - Pass by pointer used in showVictoryMessages().

     *BONUS* demonstration:
     - Inheritance. Player is the base class for Hero, Dragon, Troll and Orc.
     - Virtual functions are used to provide Hero, Dragon, Troll and Orc specific 
       attack and defense text. We call the Player objects getAttackText() for 
       example, which is empty, and if the derivied class has an implementation
       of the getAttackText() virtual function, it will be executed. Very neat!

    Note:
    - Some choices were made to ensure the demonstratbility of the homework 
      requirements therefore may not be as efficient as can be.
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
    bool done = false;
    bool validInput;
    int enemyType;

    // initialize PRNG
    srand(time(NULL));

    // initialize enemies
    array<Player *, 4> enemies;  // allocate pointers to enemies

    // assign refernece to player objects to enemies; could be done 
    // with new/pointer, but using C++ references here
    Player player = Player("Evil Jeff", 1);
    Dragon dragon = Dragon("Doug the Dragon", 1);
    Orc orc = Orc("Ollie the Orc", 1);
    Troll troll = Troll("Tommy the Troll", 1);
    enemies.at(0) = &player;
    enemies.at(1) = &dragon;
    enemies.at(2) = &orc;
    enemies.at(3) = &troll;

    cout << "Welcome to Battle Arena Simulation" << endl << endl;
    cout << endl;

	cout << "This game allows you to simulate one-on-one battles, role-playing style. Attacks and" << endl;
	cout << "blocks are random so victory is never a sure thing. You play a Hero who can battle" << endl;
	cout << "a Human, Dragon, Orc, or Troll." << endl;
    cout << endl;

    do {
        cout << "What is the hero's name? ";
        cin >> playerName;
        cout << endl;

        // get hero level
        validInput = false;
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

        // get enemy type
        validInput = false;
        do
        {
            cout << "Who would you like to fight (1=Human, 2=Dragon, 3=Orc, 4=Troll)? ";
            cin >> input;

            // check if a valid integer
            try {
                enemyType = std::stoi(input) - 1;
                if (enemyType >= 0 && enemyType < 4)
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

        // show final battle stats
        arena.showVictoryMessage();

        // should we play again?
        string playAgain;
        validInput = false;
        do {
            cout << "Want to play again? (y/n) ";
            cin >> playAgain;
            cout << endl;

            if (playAgain=="y")
            {
                done = false;
                validInput = true;
            }
            else if (playAgain == "n")
            {
                done = true;
                validInput = true;
            }
            else
            {
                cout << "brrrp! ... bad mojo" << endl;
            }
            
        } while (!validInput);

    } while (!done);
}

void showVictoryMessages(Arena* arena)
{
    // show the battle banner; i.e. A vs B
    arena->showVictoryMessage();
}