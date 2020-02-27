#pragma once
class Time
{
public:
	Time();
	void setTime(int, int, int);
	void printUniversal() const;
	void printStandard() const;
private:
	unsigned int hour = 0;
	unsigned int minute = 0;
	unsigned int second = 0;
};

