/*
	Mudit Vats
	CIS 554 - M401 Object Oriented Programming in C++
	Syracuse University
	HW #1 - Exercise 3.10 p100
	1 / 16 / 20

	This Class implements the members and function prototypes for the Invoice 
	class which is used to track details such as part number, description, 
	quantity and price.
*/

#include "Invoice.h"

// constructor implementation which intializes an Invoice object with the passed
// in invoice parameter; each private variable is assigned to the passed in invoice
// parameters.
Invoice::Invoice(std::string partNumber, std::string partDescription, int quantity, int price)
	: _partNumber{partNumber}, _partDescription{partDescription}, _quantity{quantity}, _price{price}
{

}

// get part number
std::string Invoice::getPartNumber()
{
	return _partNumber;
}

// set the part number
void Invoice::setPartNumber(std::string partNumber)
{
	_partNumber = partNumber;
}

// get part description
std::string Invoice::getPartDescription()
{
	return _partDescription;
}

// set part description
void Invoice::setPartDescription(std::string partDescription)
{
	_partDescription = partDescription;
}

// get quantity
int Invoice::getQuantity()
{
	return _quantity;
}

// set quantity
void Invoice::setQuantity(int quantity)
{
	_quantity = quantity;
}

// get price
int Invoice::getPrice()
{
	return _price;
}

// set price
void Invoice::setPrice(int price)
{
	_price = price;
}

// calculate invoice amount; i.e. quantity * price
//
// Some ambiguity - book says to check for less than zero, but it could be
// checked at input, or in the setter, or in the constructor or upon caclulation (here).
// Since the "check less than zero" text was in the context of calculating the invoice
// amount, I did it here. It would be just as trivial to put the check at any one of the
// other places. The good thing about this way is that the entered values as the user
// put them in, stay the same so we don't modify the input in any way.
int Invoice::getInvoiceAmount()
{
	int finalPrice = _price;
	int finalQuantity = _quantity;

	// check if price is valid
	if (_price < 0) finalPrice = 0;

	// check if quantity is valid
	if (_quantity < 0) finalQuantity = 0;

	// return the calculated invoice amount
	return (finalPrice * finalQuantity);
}

void Invoice::displayInvoice()
{
	std::cout << std::endl;
	std::cout << "partNumber:        " << _partNumber << std::endl;
	std::cout << "partDescription:   " << _partDescription << std::endl;
	std::cout << "quantity:          " << _quantity << std::endl;
	std::cout << "price:             " << _price << std::endl;
	std::cout << "invoice amount:    " << getInvoiceAmount() << std::endl;
}