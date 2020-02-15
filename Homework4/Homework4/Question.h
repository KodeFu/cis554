#pragma once
#include <string>

using std::string;

class Question
{
public:
	// constructor
	Question(int difficulty, int problemType);

	// randomize left and right values
	void randomizeQuestion();

	// get a formatted question
	string getQuestion();

	// return the answer
	int getAnswer();

	// given an answer, check if it's correct
	bool isAnswerCorrect(int guess);
	
private:
	int _difficulty;   // difficulty left (1=easy, 2=moderate, 3=hard)
	int _problemType;  // problem type (1=add, 2=subtract, 3=multiply, 4=divide, 5=random)
	int _operation;    // actual operation being used (1=add, 2=subtract, 3=multiply, 4=divide)
	int _left;         // left value
	int _right;        // right value
};

