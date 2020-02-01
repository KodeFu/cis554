#include "pch.h"
#include "SimpleMath.h"


SimpleMath::SimpleMath()
{
}


SimpleMath::~SimpleMath()
{
}

SimpleMath::SimpleMath(int a, int b)
{
	number1 = a;
	number2 = b;
}

int SimpleMath::GetResult()
{
	return result;

}

void SimpleMath::Add()
{
	result = number1 + number2;
}

void SimpleMath::Multiply()
{
	result = number1 * number2;
}