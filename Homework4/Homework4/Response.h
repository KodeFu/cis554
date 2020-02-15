/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #4 - Exercise 6.54-6.61 p281-282
	2 / 15 / 20

	This class defines the members and function prototypes for the Response
	class which is used to generate witty responses for ecouragement.
*/
#pragma once
#include <string>

using std::string;

class Response
{
public:
	// constructor
	Response();

	// return response; default to returning response for correct answers
	string getResponse(bool correctAnswer = true);

private:
	string getCorrectResponse(int choice);   // return positive response
	string getIncorrectResponse(int choice); // return negative response
};

