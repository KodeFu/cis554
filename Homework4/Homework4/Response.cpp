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
		response = "Excellent!";
		break;
	case 2:
		response = "Nice work!";
		break;
	case 3:
		response = "Keep up the good work!";
		break;
	case 0:
		response = "Very Good!";
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
		response = "Wrong. A tin can is smarter than you! Try once more.";
		break;
	case 2:
		response = "Don't give up, meatsack!";
		break;
	case 3:
		response = "No. You make a Trash-80 look like genius! Keep trying.";
		break;
	case 0:
		response = "No. Id10T. Please try again.";
	default:
		break;
	}

	return response;
}