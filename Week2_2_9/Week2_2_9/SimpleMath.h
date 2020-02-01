#pragma once
class SimpleMath
{
public:
	SimpleMath();
	~SimpleMath();
	SimpleMath(int a, int b);
	int GetResult();
	void Add();
	void Multiply();

private:
	int number1;
	int number2;
	int result;
};

