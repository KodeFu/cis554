#pragma once
#include <string>

using std::string;

class Question
{
public:
	// constructor
	Question(int difficulty);
	string getQuestion();
	bool isAnswerCorrect(int guess);

private:
	int _difficulty;
	int _left;
	int _right;
};

