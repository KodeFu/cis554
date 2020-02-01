#include "TimeDiff.h"

TimeDiff::TimeDiff(int hour, int minute, int second)
	: _hour{ hour }, _minute{ minute }, _second{ second }
{

}

int TimeDiff::SecondsSinceNoon()
{
	if (!ValidateTime())
	{
		return -1;
	}

	int secondsSinceNoon = 0;
	int actualHours;

	if (_hour < 12) 
	{
		actualHours = _hour + 12;
	}
	else
	{
		actualHours = _hour - 12;
	}


	int finalResult = (actualHours * 60 * 60) + (_minute * 60) + (_second);

	return finalResult;
}

bool TimeDiff::ValidateTime()
{
	if ((_hour < 0) || (_hour > 23) || (_minute < 0) || (_minute > 59) || (_second < 0) || (_second > 59))
	{
		return false;
	}

	return true;
}