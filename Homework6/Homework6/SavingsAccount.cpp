/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Homework 6, Exercise 9.20 on p443
	2 / 26 / 20

	This class implements a savings account. It also allows interst
	rates to be taken into account when calculating monthly balance.

*/
#include "SavingsAccount.h"

double SavingsAccount::_annualInterestRate = 0.0;

// constructor
SavingsAccount::SavingsAccount(double savingsBalance)
	: _savingsBalance{savingsBalance}
{
}

// calculate monthly rate and add to balance
void SavingsAccount::calculateMonthlyInterest()
{
	double monthlyRate = _savingsBalance * (_annualInterestRate / 100.0) / 12.0;

	_savingsBalance += monthlyRate;
}

// get savings balance
double SavingsAccount::getSavingsBalance()
{
	return _savingsBalance;
}

// set savings balance
void SavingsAccount::setSavingsBalance(double savingsBalance)
{
	_savingsBalance = savingsBalance;
}

// get interest rate
double SavingsAccount::getInterestRate()
{
	return _annualInterestRate;
}

// modify interest rate
void SavingsAccount::modifyInterestRate(double annualInterestRate)
{
	_annualInterestRate = annualInterestRate;
}