/*
    Mudit Vats
    CIS 554 - M401 Object Oriented Programming in C++
    Syracuse University
    Homework 6, Exercise 9.20 on p443
    2 / 26 / 20

    This program is a simple monthly saving calculater which
    monthly saving account balance by calculating the interest
    on the balance.

*/

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using std::cout;
using std::endl;

int main()
{
    std::cout << "Hello Savings Account Homework!\n";

    // create two savings accounts
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    // display balance
    cout << "Starting balance for saver1: $" << std::fixed << std::setprecision(2) << saver1.getSavingsBalance() << endl;
    cout << "Starting balance for saver2: $" << std::fixed << std::setprecision(2) << saver2.getSavingsBalance() << endl;

    // set the interst rate (static so only need to set
    // in one object)
    saver1.modifyInterestRate(3.0);
    cout << endl << "Interest rate now set to: " << saver1.getInterestRate() << "%" << endl;

    // caculate new monthly rate
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    // display balance
    cout << "Balance for saver1: $" << std::fixed << std::setprecision(2) << saver1.getSavingsBalance() << endl;
    cout << "Balance for saver2: $" << std::fixed << std::setprecision(2) << saver2.getSavingsBalance() << endl;

    // set the interst rate (static so only need to set
    // in one object)
    saver1.modifyInterestRate(4.0);
    cout << endl << "Interest rate now set to: " << saver1.getInterestRate() << "%" << endl;

    // caculate new monthly rate
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    // display balance
    cout << "Balance for saver1: $" << std::fixed << std::setprecision(2) << saver1.getSavingsBalance() << endl;
    cout << "Balance for saver2: $" << std::fixed << std::setprecision(2) << saver2.getSavingsBalance() << endl;

}
