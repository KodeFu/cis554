/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #1 - Exercise 3.10 p100
	1 / 16 / 20

	This Class defines the members and function prototypes for the Invoice class
	which is used to track details such as part number, description, quantity 
	and price.
*/
#pragma once
#include <iostream>

class Invoice
{
public:
	// constructor used to initialize a new object
	Invoice(std::string partNumber, std::string partDescription, int quantity, int price);

	// getter and setter for part number
	std::string getPartNumber();
	void setPartNumber(std::string partNumber);

	// getter and setter for part description
	std::string getPartDescription();
	void setPartDescription(std::string partDescription);
	
	// getter and setter for quantity
	int getQuantity();
	void setQuantity(int quantity);
	
	// getter and setter for price
	int getPrice();
	void setPrice(int price);

	// calculate invoice amount; i.e. quantity * price
	int getInvoiceAmount();

	// display invoice details and amount
	void displayInvoice();

private:
	// member variables
	std::string _partNumber;
	std::string _partDescription;
	int _quantity;
	int _price;
};

