#include "Question.h"
#include <iostream>
#include <ctime>

using std::to_string;

Question::Question(int difficulty)
	: _difficulty{difficulty}, _left{0}, _right{0}
{	
	srand(time(NULL));
}

void Question::randomizeQuestion()
{
	int digitSizeDivisor;

	switch (_difficulty)
	{
	case 2:
		digitSizeDivisor = 100;
		break;
	case 3:
		digitSizeDivisor = 1000;
		break;
	case 1:
	default:
		digitSizeDivisor = 10;
		break;
	}

	// generate random numbers for operands to left and right of the operator
	_left = rand() % digitSizeDivisor;
	_right = rand() % digitSizeDivisor;
}

string Question::getQuestion()
{
	string question = "How much is " + to_string(_left) + " times " + to_string(_right) + "? ";

	return question;
}

bool Question::isAnswerCorrect(int guess)
{
	int answer = _left * _right;

	if (guess == answer)
	{
		return true;
	}

	return false;
}

int Question::getAnswer()
{
	int answer = _left * _right;

	return answer;
}