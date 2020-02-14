#pragma once
#include <string>

using std::string;

class Response
{
public:
	Response();
	string getResponse(bool correctAnswer = true);

private:
	string getCorrectResponse(int choice);
	string getIncorrectResponse(int choice);
};

