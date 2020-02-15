/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #4 - Exercise 6.54-6.61 p281-282
	2 / 15 / 20

	This class defines the members and function prototypes for the Response
	class which is used to generate witty responses for ecouragement.
*/
#include "Response.h"
#include <iostream>
#include <ctime>

// constructor
Response::Response()
{
	srand(time(NULL));
}

// return response text based on correct or incorrect answer
string Response::getResponse(bool correctAnswer)
{
	int randomResponse = rand() % 4;

	if (correctAnswer)
	{
		return getCorrectResponse(randomResponse);
	}
	else
	{
		return getIncorrectResponse(randomResponse);
	}
}

// return response text for correct answer
string Response::getCorrectResponse(int choice)
{
	string response;

	switch (choice)
	{
	case 1:
		response = "Excellent! You are a SUPER COMPUTER!!";
		break;
	case 2:
		response = "Ding, ding, ding! We have a winner!";
		break;
	case 3:
		response = "Maybe humans can be smarter then a computer?... Keep up the good work!";
		break;
	case 0:
		response = "Your spark plugs are on fire! Very Good!";
	default:
		break;
	}

	return response;
}

// return response text for incorrect answer
string Response::getIncorrectResponse(int choice)
{
	string response;

	switch (choice)
	{
	case 1:
		response = "Wrong! A tin can is smarter than you! Try once more.";
		break;
	case 2:
		response = "Don't give up, Meatsack!";
		break;
	case 3:
		response = "No! What am I talking to a TRS-80? Keep trying.";
		break;
	case 0:
		response = "Bzzzt! Id10T. Try again.";
	default:
		break;
	}

	return response;
}