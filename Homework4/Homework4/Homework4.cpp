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
    Response response;

    cout << endl;
    cout << "     \\  /" << endl;
    cout << "   *********" << endl;
    cout << "   * O   O *" << endl;
    cout << "   *   ^   *   /--- Bada-beep, bada-boop!" << endl;
    cout << "   * ||||| * -" << endl;
    cout << "   *********" << endl;
    cout << endl;
    cout << "Hi, I'm CAIB, your Computer-Assisted Instruction Bot!" << endl << endl;
   

    cout << "What's your pleasure, I mean, pain... I mean difficulty (1=easy, 2=moderate, 3=hard)? ";
    cin >> difficulty;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "BEEP! Enter 1 for easy, 2 for moderate, or 3 or hard? ";
        cin >> difficulty;
    }

    // create a new question object
    Question q(difficulty);

    do {
        // ask a question
        cout << q.getQuestion();

        // get the answer
        cin >> answer;

        // double-check cin, in case invalid input was entered
        while (cin.fail())
        {
            // clear previous state
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');

            // ask the question again
            cout << "Answer the question HUMAN! " << q.getQuestion();
            cin >> answer;
        }
    
        isCorrect = q.isAnswerCorrect(answer);
        cout << response.getResponse(isCorrect) << endl;
    } while (!isCorrect);
}
