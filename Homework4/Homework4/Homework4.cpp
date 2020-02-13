#include <iostream>
#include <ctime>
#include "Question.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int answer;
    int difficulty;

    cout << endl;
    cout << "     \\  /" << endl;
    cout << "   *********" << endl;
    cout << "   * O   O *" << endl;
    cout << "   *   ^   *   /--- Beda-beep, bada-boop!" << endl;
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

    Question q(difficulty);

    cout << q.getQuestion();
    cin >> answer;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Answer the question HUMAN! " << q.getQuestion();
        cin >> answer;
    }

    if (q.isAnswerCorrect(answer))
    {
        cout << "you rock! :-)" << endl;
    }
    else
    {
        cout << "you DO NOT rock! :-(" << endl;
    }

}
