/*
    Mudit Vats
    CIS 554 - M401 Object Oriented Programming in C++
    Syracuse University
    HW #4 - Exercise 6.54-6.61 p281-282
    2 / 15 / 20

    This program is a simple math learning game which allows students to 
    the type of problem and difficulty and go through a series of problems
    and ultimately get a score and recommendataion based on that score.

*/
#include <iostream>
#include <ctime>
#include "Question.h"
#include "Response.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    string input;
    bool validInput;
    int answer;
    bool isCorrect;
    int difficulty;
    int problemType;
    bool quit = false;
    Response response;
   
    ///////////////////////////////////////////////////////////
    //
    // Start CAIB - Computer-Assisted Instruction Bot
    //
    ///////////////////////////////////////////////////////////
    do
    {
        int answerCount = 0;
        int correctAnswerCount = 0;
        bool completedRound = false;

        cout << endl;
        cout << "     \\   /" << endl;
        cout << "   *********" << endl;
        cout << "   * O   O *" << endl;
        cout << "   *   ^   *   /--- Bada-beep, bada-boop!" << endl;
        cout << "   * ||||| * -" << endl;
        cout << "   *********" << endl;
        cout << endl;
        cout << "Hi, I'm CAIB, your Computer-Assisted Instruction Bot!" << endl << endl;
        cout << "     \"Would you like to play a game?\"" << endl << endl;
        cout << "** Please enter \"quit\" at anytime to quit. **" << endl << endl;

        /////////////////////////////////////////////////
        //
        // Get difficulty
        //
        /////////////////////////////////////////////////
        validInput = false;
        do
        {
            cout << "What's your pain... I mean difficulty (1=easy, 2=moderate, 3=hard)? ";
            cin >> input;

            // check for quit
            if (input == "quit")
            {
                quit = true;
                validInput = true;
            }
            // check for 80's trivia rock-star!
            else if (input == "joshua")
            {
                cout << "Starting Global Themonuclear War! ... not really. You are an 80's trivia master! Setting to highest difficulty!" << endl;
                difficulty = 3;
                validInput = true;
            }
            // check if a valid integer
            else
            {
                try {
                    difficulty = std::stoi(input);
                    validInput = true;
                }
                catch (...)
                {
                    cout << "brrrp! ... bad mojo" << endl;
                }
            }
        } while (!validInput);
        cout << endl;

        // check for quit
        if (quit)
        {
            continue;
        }

        /////////////////////////////////////////////////
        //
        // Get problem type
        //
        /////////////////////////////////////////////////
        validInput = false;
        do
        {
            cout << "What's your problem... type? (1=add, 2=subtract, 3=multiply, 4=divide, 5=random)? ";
            cin >> input;

            // check for quit
            if (input == "quit")
            {
                quit = true;
                validInput = true;
            }
            // check if a valid integer
            else
            {
                try {
                    problemType = std::stoi(input);
                    validInput = true;
                }
                catch (...)
                {
                    cout << "brrrp! ... bad mojo" << endl;
                }
            }
        } while (!validInput);
        cout << endl;

        // check for quit
        if (quit)
        {
            continue;
        }

        /////////////////////////////////////////////////
        //
        // Start Q&A loop
        //
        /////////////////////////////////////////////////

        // create a new question object
        Question question(difficulty, problemType);
        
        do
        {
            // get a new question, randomized left and right values
            question.randomizeQuestion();

            do {

                validInput = false;
                do
                {
                    // ask a question
                    cout << (answerCount + 1) << ". " << question.getQuestion();
                    cin >> input;

                    // check for quit
                    if (input == "quit")
                    {
                        quit = true;
                        validInput = true;
                    }
                    // check if a valid integer
                    else
                    {
                        try {
                            answer = std::stoi(input);
                            answerCount++;
                            validInput = true;
                        }
                        catch (...)
                        {
                            cout << "brrrp! ... bad mojo" << endl;
                        }
                    }
                } while (!validInput);

                // check for quit
                if (quit)
                {
                    continue;
                }

                isCorrect = question.isAnswerCorrect(answer);
                if (isCorrect)
                {
                    correctAnswerCount++;
                }
                cout << response.getResponse(isCorrect) << endl << endl;

                // are we done yet?
                if (answerCount == 10)
                {
                    int score = (int) (((double) correctAnswerCount / (double) answerCount) * 100.0);
                    cout << "** You scored a " << score << " percent. **" << endl << endl;
                    if (score >= 75)
                    {
                        cout << "Congratulations, you are ready to go to the next level! :-)" << endl;
                    }
                    else
                    {
                        cout << "Please ask your teacher for extra help. :-(" << endl;
                    }

                    // completed 10 responses
                    completedRound = true;
                }

            } while (!quit && !completedRound && !isCorrect);

        } while (!quit && !completedRound);

    } while (!quit);
}
