/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	Homework 6, Exercise 9.20 on p443
	2 / 26 / 20

	This class implements a savings account. It also allows interst
	rates to be taken into account when calculating monthly balance.

*/
#pragma once
class SavingsAccount
{
public:
	// constructor
	SavingsAccount(double savingsBalance);

	// calculate monthly interest add that to the balance
	void calculateMonthlyInterest();

	// getter and setter for savings account balance
	double getSavingsBalance();
	void setSavingsBalance(double savingsBalance);

	// update interest rate
	static double getInterestRate();
	static void modifyInterestRate(double annualInterestRate);
	

private:
	static double _annualInterestRate; // static annual interest rate; one per all objects
	double _savingsBalance;            // savings balance
	
};

