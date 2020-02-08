#pragma once
class TimeDiff
{
public:
	TimeDiff(int hour, int minute, int second);
	int SecondsSinceNoon();
	
	int SecondsSinceNoonCalcByRef(int& hour, int& minute, int& second);

private:
	bool ValidateTime();
	bool ValidateTimeByRef(int& hour, int& minute, int& second);

	int _hour;
	int _minute;
	int _second;
};

