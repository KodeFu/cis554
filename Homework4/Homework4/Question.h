#pragma once
#include <string>

using std::string;

class Question
{
public:
	// constructor
	Question(int difficulty);

	// randomize left and right values
	void randomizeQuestion();

	// get a formatted question
	string getQuestion();

	// return the answer
	int getAnswer();

	// given an answer, check if it's correct
	bool isAnswerCorrect(int guess);
	
private:
	int _difficulty; // difficulty left (1=easy, 2=moderate, 3=hard)
	int _left;       // left value
	int _right;      // right value
};

