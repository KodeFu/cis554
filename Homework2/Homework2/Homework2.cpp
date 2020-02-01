/*
    Mudit Vats
    CIS 554 - M401 Object Oriented Programming in C++
    Syracuse University
    HW #2 - Exercise 4.14 p150
    2 / 1 / 20

    This program is a simple credit limit program which allows users to enter
    balance, charges, and credits to their account and then displays their
    current balance. If the balance exceeds the entered credit limit, a message
    will be displayed along with the details of the amounts entered.

*/
#include <iostream>
#include <iomanip>
#include "Account.h"

using std::cin;
using std::cout;
using std::setprecision;
using std::fixed;
using std::endl;

// start of main credit limit applicaton
int main()
{
    int accountNumber = 0;
    double beginningBalance;
    double totalItemsCharged;
    double totalCreditsApplied;
    double creditLimit;

    cout << "**************************************************" << endl;
    cout << "Welcome to the GREATEST Accounting Program Ever!!!" << endl;
    cout << "**************************************************" << endl;

    // loop through inputs until user wants to quit
    while (accountNumber != -1)
    {
        // input account number
        cout << "Enter account number (or -1 to quit): ";
        cin >> accountNumber;

        if (accountNumber != -1)
        {
            // input beginning balance
            cout << "Enter beginning balance: ";
            cin >> beginningBalance;

            // input total charges
            cout << "Enter total charges: ";
            cin >> totalItemsCharged;

            // input total credits
            cout << "Enter total credits: ";
            cin >> totalCreditsApplied;

            // input credit limit
            cout << "Enter credit limit: ";
            cin >> creditLimit;

            // create a new account object with the amounts inputted
            Account account(
                accountNumber, 
                beginningBalance, 
                totalItemsCharged, 
                totalCreditsApplied, 
                creditLimit);

            // calculate and display current balance
            double currentBalance = account.getCurrentBalance();
            cout << "New balance is: ";
            cout << fixed << setprecision(2) << currentBalance << endl;

            // check if the credit limit has been exceeded
            if (currentBalance > account.getCreditLimit())
            {
                // display amount details
                cout << "Account: ";
                cout << account.getAccountNumber() << endl;
                cout << "Credit limit: ";
                cout << fixed << setprecision(2) << account.getCreditLimit() << endl;
                cout << "Balance: ";
                cout << fixed << setprecision(2) << currentBalance << endl;
                cout << "Credit Limit Exceeded." << endl;
                cout << endl;
            }
        }
    }
}
