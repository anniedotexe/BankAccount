/*
Author: 		Annie Wu
Assignment:		Homework #4

Class:			CS 2560.01 - C++ Programming
Date:			14 December 2018

Purpose:		This file holds the CheckingAccount class that is derived from Account.

*/

#pragma once

#include <iostream>
#include <string>
using namespace std;

class CheckingAccount : public Account {
public:
	CheckingAccount(double b, double i) : Account(b,i) { }
	virtual void withdraw() {
		double amount = 0.0;
		cout << "\nHow much would you like to withdraw from Checking Account? ";
		cin >> amount;

		//if balance will go below zero, cannot withdraw
		if ((balance - amount) < 0) {
			serviceCharge = 15;
			cout << "Withdrawal of $" << amount << " was unsuccessful. It will make your balance negative." << endl;
		}
		else {
			Account::withdraw(amount);
		}
	}

	virtual void monthlyProc() {
		serviceCharge = 5 + (0.10 * withdrawals);
		Account::monthlyProc();
	}
};
