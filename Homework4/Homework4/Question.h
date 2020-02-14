#pragma once
#include <string>

using std::string;

class Question
{
public:
	// constructor
	Question(int difficulty);
	string getQuestion();
	string getNewQuestion();
	bool isAnswerCorrect(int guess);


private:
	void generateRandoms();

	int _difficulty;
	int _left;
	int _right;
};

