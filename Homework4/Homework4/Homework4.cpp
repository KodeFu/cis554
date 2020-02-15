#include <iostream>
#include <ctime>
#include "Question.h"
#include "Response.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
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
        cout << "     \\  /" << endl;
        cout << "   *********" << endl;
        cout << "   * O   O *" << endl;
        cout << "   *   ^   *   /--- Bada-beep, bada-boop!" << endl;
        cout << "   * ||||| * -" << endl;
        cout << "   *********" << endl;
        cout << endl;
        cout << "Hi, I'm CAIB, your Computer-Assisted Instruction Bot!" << endl << endl;
        cout << "** Please enter -1 at anytime to quit. **" << endl << endl;

        /////////////////////////////////////////////////
        //
        // Get difficulty
        //
        /////////////////////////////////////////////////
        cout << "What's your pain... I mean difficulty (1=easy, 2=moderate, 3=hard)? ";
        cin >> difficulty;

        // check for cin 
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "BEEP! Enter 1 for easy, 2 for moderate, or 3 or hard? ";
            cin >> difficulty;
        }
        cout << endl;

        // check for quit
        if (difficulty == -1)
        {
            quit = true;
            continue;
        }


        /////////////////////////////////////////////////
        //
        // Get problem type
        //
        /////////////////////////////////////////////////
        cout << "What's your problem... type? (1=add, 2=subtract, 3=multiply, 4=divide, 5=random)? ";
        cin >> problemType;

        // check for cin 
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "BEEP! Enter 1 for add, 2 for subtract, 3 for multiply, 4 for divide, or 5 for random? ";
            cin >> problemType;
        }
        cout << endl;

        // check for quit
        if (problemType == -1)
        {
            quit = true;
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
                // ask a question
                cout << (answerCount+1) << ". " << question.getQuestion();

                // get the answer
                cin >> answer;
                answerCount++;

                // double-check cin, in case invalid input was entered
                while (cin.fail())
                {
                    // clear previous state
                    cin.clear();
                    cin.ignore(std::numeric_limits<int>::max(), '\n');

                    // ask the question again
                    cout << "Answer the question HUMAN! " << question.getQuestion();
                    cin >> answer;
                    answerCount++;
                }

                // check for quit
                if (answer == -1)
                {
                    quit = true;
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
