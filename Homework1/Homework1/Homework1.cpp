/*
    Mudit Vats
    CIS 554 - M401 Object Oriented Programming in C++
    Syracuse University
    HW #1 - Exercise 3.10 p100
    1 / 16 / 20

    This program creates invoices for parts and shows the invoice amounts. This
    is a test application for the Invoice class.

*/

#include <iostream>
#include "Invoice.h"

// start of Invoice Class test application
int main()
{
    std::cout << "Greatest Invoice test application ever!\n";

    // Example 1
    // initialize invoice object values
    std::string partNumber = "100";
    std::string partDescription = "A simple part";
    int quantity = 10;
    int price = 4;

    // instantiate an Invoice object
    Invoice myInvoice(partNumber, partDescription, quantity, price);

    // Display invoice details
    std::cout << std::endl;
    std::cout << "partNumber:        " << partNumber << std::endl;
    std::cout << "partDescription:   " << partDescription << std::endl;
    std::cout << "quantity:          " << quantity << std::endl;
    std::cout << "price:             " << price << std::endl;
    std::cout << "invoice amount:    " << myInvoice.getInvoiceAmount() << std::endl;



    // Example 2
    // initialize invoice object values
    partNumber = "200";
    partDescription = "A complex part";
    quantity = 20;
    price = 50;

    // instantiate an Invoice object
    Invoice mySecondInvoice(partNumber, partDescription, quantity, price);

    // Display using member function
    mySecondInvoice.displayInvoice();
}
