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

#pragma once
class Account
{
public:
	// constructor used to initialize a new Account object
	Account(int accountNumber, double beginningBalance, double totalItemsCharged, 
		double totalCreditsApplied, double creditLimit);

	// getter and setter for account number
	int     getAccountNumber();
	void    setAccountNumber(int accountNumber);
	
	// getter and setter for balance
	double  getBeginningBalance();
	void    setBeginningBalance(double beginningBalance);
	
	// getter and setter for total items charged
	double  getTotalItemsCharged();
	void    setTotalItemsCharged(double totalItemsCharged);
	
	// getter and setter for credits applied
	double  getTotalCreditsApplied();
	void    setTotalCreditsApplied(double totalCreditsApplied);
	
	// getter and setter for credit limit
	double  getCreditLimit();
	void    setCreditLimit(double creditLimit);

	// getter for current balance; this is calculated so there
	// is no setter
	double  getCurrentBalance();

private:
	// member variables
	int     _accountNumber;
	double  _beginningBalance;
	double  _totalItemsCharged;
	double  _totalCreditsApplied;
	double  _creditLimit;
};

