/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #2 - Exercise 4.14 p150
	2 / 1 / 20

	This class defines the members and function prototypes for the Account
	class which is used to track amount details suck as balance, charges,
	credits and credit limit.

*/

#include "Account.h"

// constructor implementation which intializes an Account object with the passed
// in parameters; each private variable is assigned to the passed in account
// parameters.
Account::Account(int accountNumber, double beginningBalance, double totalItemsCharged,
	double totalCreditsApplied, double creditLimit) 
	: _accountNumber{accountNumber}, _beginningBalance{beginningBalance}, 
	_totalItemsCharged{totalItemsCharged}, _totalCreditsApplied{totalCreditsApplied}, 
	_creditLimit{creditLimit}
{

}

// get account number
int Account::getAccountNumber()
{
	return _accountNumber;
}

// set account number
void Account::setAccountNumber(int accountNumber)
{
	_accountNumber = accountNumber;
}

// get beginning balance
double Account::getBeginningBalance()
{
	return _beginningBalance;
}

// set beginning balance
void Account::setBeginningBalance(double beginningBalance)
{
	_beginningBalance = beginningBalance;
}

// get total items charged
double Account::getTotalItemsCharged()
{
	return _totalItemsCharged;
}

// set total items charged
void Account::setTotalItemsCharged(double totalItemsCharged)
{
	_totalItemsCharged = totalItemsCharged;
}

// get total credits applied
double Account::getTotalCreditsApplied()
{
	return _totalCreditsApplied;
}

// set total credits applied
void Account::setTotalCreditsApplied(double totalCreditsApplied)
{
	_totalCreditsApplied = totalCreditsApplied;
}

// get credit limit
double Account::getCreditLimit()
{
	return _creditLimit;
}

// set credit limit
void Account::setCreditLimit(double creditLimit)
{
	_creditLimit = creditLimit;
}

// get current balance
double Account::getCurrentBalance()
{
	return _beginningBalance + _totalItemsCharged - _totalCreditsApplied;
}
