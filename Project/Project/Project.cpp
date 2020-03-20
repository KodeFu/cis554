/*
    Mudit Vats
    CIS 554 - M401 Object Oriented Programming in C++
    Syracuse University
    Project
    3 / 19 / 20

    This is the final project.

    Final Project Requirements:
    - A game or program that provides a useful business function that shows the proper usage of inheritance and 
      polymorphism.
    - I should be able to write a derived class that fits right into your program and extends your base class, 
      without any changes being made to the base class.

    In this game, the user can play a Hero which can battle various enemies (to the death!). Each of the enemies 
    are derived from the Player base class. Further, the derived enemies implement getAttackText() and getDefenseText() 
    which get called from the base Player class to output enemy specific messages.
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
using std::stoi;

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
    vector<Player *> enemies; 

    // add the various enemies
    enemies.push_back(new Hero("Evil Jeff", 1));
    enemies.push_back(new Dragon("Doug", 1));
    enemies.push_back(new Orc("Ollie", 1));
    enemies.push_back(new Troll("Tommy", 1));
    // <-------- Add more enemies here! -------->
    // <-------- Add more enemies here! -------->
    // <-------- Add more enemies here! -------->

    cout << "Welcome to Battle Arena Simulation" << endl;
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
            cout << "Enemies:" << endl;
            int i = 1;
            for (auto enemy : enemies)
            {
                // dynamically output the enemy types
                cout << "  " << i++ << ". " << enemy->getType() << endl;
            }
            cout << "Who would you like to fight? ";
            cin >> input;

            // check if a valid integer
            try {
                enemyType = std::stoi(input) - 1;
                if (enemyType >= 0 && enemyType < enemies.size())
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

    // deallocate enemies
    for (auto enemy : enemies)
    {
        delete enemy;
    }
    enemies.clear();
}

void showVictoryMessages(Arena* arena)
{
    // show the battle banner; i.e. A vs B
    arena->showVictoryMessage();
}