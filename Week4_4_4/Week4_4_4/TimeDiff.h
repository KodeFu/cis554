#pragma once
class TimeDiff
{
public:
	TimeDiff(int hour, int minute, int second);
	int SecondsSinceNoon();
	bool ValidateTime();

private:
	int _hour;
	int _minute;
	int _second;
};

