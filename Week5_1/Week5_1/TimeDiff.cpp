#include "TimeDiff.h"

TimeDiff::TimeDiff(int hour, int minute, int second)
	: _hour{ hour }, _minute{ minute }, _second{ second }
{

}

int TimeDiff::SecondsSinceNoon()
{
	if (!ValidateTimeByRef(_hour, _minute, _second))
	{
		return -1;
	}

	return SecondsSinceNoonCalcByRef(_hour, _minute, _second);
}

int TimeDiff::SecondsSinceNoonCalcByRef(int &hour, int &minute, int &second)
{
	int secondsSinceNoon = 0;
	int actualHours;

	if (hour < 12)
	{
		actualHours = hour + 12;
	}
	else
	{
		actualHours = hour - 12;
	}


	int finalResult = (actualHours * 60 * 60) + (minute * 60) + (second);

	return finalResult;
}

bool TimeDiff::ValidateTimeByRef(int& hour, int& minute, int& second)
{
	if ((hour < 0) || (hour > 23) || (minute < 0) || (minute > 59) || (second < 0) || (second > 59))
	{
		return false;
	}

	return true;
}

bool TimeDiff::ValidateTime()
{
	if ((_hour < 0) || (_hour > 23) || (_minute < 0) || (_minute > 59) || (_second < 0) || (_second > 59))
	{
		return false;
	}

	return true;
}