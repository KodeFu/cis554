/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #4 - Exercise 6.54-6.61 p281-282
	2 / 15 / 20

	This class defines the members and function prototypes for the Questions
	class which is used to generate question, calculate answers and
	check answers.
*/

#include "Question.h"
#include <iostream>
#include <ctime>

using std::to_string;

// constructor
Question::Question(int difficulty, int problemType)
	: _difficulty{ difficulty }, _problemType{ problemType }, _left{ 0 }, _right{ 0 }
{	
	srand(time(NULL));
}

// function to randomize (change) question
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

	// set operation based on problemType
	if (_problemType == 5)
	{
		// randomize question
		_operation = (rand() % 4) + 1;
	}
	else
	{
		// use the problem type as the operation
		_operation = _problemType;
	}
}

// function to return the formatted question 
string Question::getQuestion()
{
	string operationText;

	switch (_operation)
	{
	case 2: // subtract
		operationText = " minus ";
		break;
	case 3: // multiply
		operationText = " times ";
		break;
	case 4: // divide
		operationText = " divided by ";
		break;
	case 1: // add
	default:
		operationText = " plus ";
		break;
	}

	string question = "How much is " + to_string(_left) + operationText + to_string(_right) + "? ";

	return question;
}

// functin to check if answer is correct
bool Question::isAnswerCorrect(int guess)
{
	if (guess == getAnswer())
	{
		return true;
	}

	return false;
}

// fundtion to get the answer based on operation
int Question::getAnswer()
{
	int answer;

	switch (_operation)
	{
	case 2: // subtract
		answer = _left - _right;
		break;
	case 3: // multiply
		answer = _left * _right;
		break;
	case 4: // divide
		answer = _left / _right;
		break;
	case 1: // add
	default:
		answer = _left + _right;
		break;
	}

	return answer;
}