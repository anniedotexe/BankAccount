/*
Author: 		Annie Wu
Assignment:		Homework #4

Class:			CS 2560.01 - C++ Programming
Date:			14 December 2018

Purpose:		This file holds the main class that contains a menu-driven system
			that allows to user to:
				- Make a deposit to savings
				- Make a deposit to checkings
				- Make a withdrawal from savings
				- Make a withdrawal from checkings
				- View the balance of either
				- Indicate that a month has passed
*/

#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	double savingsStart, checkingsStart, savingsInt, checkingsInt;
	cout << "Enter starting balance of Savings account: ";
	cin >> savingsStart;
	cout << "Enter annual interest rate % of Savings account: ";
	cin >> savingsInt;
	cout << "Enter starting balance of Checking account: ";
	cin >> checkingsStart;
	cout << "Enter annual interest rate % of Checking account: ";
	cin >> checkingsInt;

	SavingsAccount mySavings (savingsStart, savingsInt);
	CheckingAccount myChecking (checkingsStart, checkingsInt);

	int input;
	bool run = true;
	string menu = "\nWhat would you like to do?"
		"\n 1. Make a Deposit to Savings"
		"\n 2. Make a Deposit to Checkings"
		"\n 3. Make a Withdrawl from Savings"
		"\n 4. Make a Withdrawl from Checkings"
		"\n 5. View the Balance of your Accounts"
		"\n 6. Indicate that a Month has Passed"
		"\n 0. Exit this Program"
		"\nEnter a number: ";

	while (run) {
		cout << "---------------------------------------------------------------" << endl;
		cout << menu;
		cin >> input;
		double amount = 0.0;

		switch (input) {
			case 1: //deposit savings
				mySavings.SavingsAccount::deposit();
				break;

			case 2: //deposit checkings
				cout << "\nHow much would you like to deposit to Checking Account? ";
				cin >> amount;
				myChecking.deposit(amount);
				break;

			case 3: //withdrawl savings
				mySavings.withdraw();
				break;

			case 4: //withdrawl checkings
				myChecking.withdraw();
				break;

			case 5: //view balance
				cout << fixed << setprecision(2);
				cout << "\nSavings Account Balance: " << mySavings.getBalance() << endl;
				if (mySavings.getStatus() == false) {
					cout << "Savings Account is inactive." << endl;
				}
				cout << "Checking Account Balance: " << myChecking.getBalance() << endl;
				break;

			case 6: //month has passed
				mySavings.monthlyProc();
				myChecking.monthlyProc();

				//print current account balances after monthly fees have been charged
				cout << endl << "A month has passed. Current Account Balances:" << endl;
				cout << fixed << setprecision(2);
				cout << "\nSavings Account Balance: " << mySavings.getBalance() << endl;
				if (mySavings.getStatus() == false) {
					cout << "Savings Account is INACTIVE." << endl;
				}
				cout << "Checking Account Balance: " << myChecking.getBalance() << endl;
				break;

			case 0: //exit
				run = false;
				cout << "\nExiting the program...\n";
				break;

			default:
				cout << endl << "Invalid input. Please enter a number." << endl;
		}
	}
	return 0;
}
