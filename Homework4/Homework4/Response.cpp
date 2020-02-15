#include "Response.h"
#include <iostream>
#include <ctime>

Response::Response()
{
	srand(time(NULL));
}

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