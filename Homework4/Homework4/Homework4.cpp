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
   
    // start CAIB
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
                    if (correctAnswerCount >= 8)
                    {
                        // we check for 8 correct response since 75% of 10 is 7.5. We can't have 7.5
                        // answers so, so anything >= 8 is 80% and can move to the next level.
                        cout << "Congratulations, you are ready to go to the next level! :-)" << endl;
                    }
                    else
                    {
                        // <= 7 or 70% needs extra help
                        cout << "Please ask your teacher for extra help. :-(" << endl;
                    }

                    // completed 10 responses
                    completedRound = true;
                }

            } while (!quit && !completedRound && !isCorrect);

        } while (!quit && !completedRound);

    } while (!quit);
}
