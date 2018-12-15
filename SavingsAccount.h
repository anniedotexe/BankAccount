/*
Author: 		Annie Wu
Assignment:	    Homework #4

Class:			CS 2560.01 - C++ Programming
Date:			14 December 2018

Purpose:		This file holds the SavingsAccount class that is derived from Account.
				It additionally holds the infomation about the status of an account.

*/

#pragma once

#include <iostream>
#include <string>
using namespace std;

class SavingsAccount : public Account {
private:
	bool status; //true for active, false for inactive

public:
	SavingsAccount(double b, double i) : Account(b, i) {
		checkStatus();
	}
	
	virtual void deposit() {
		double amount = 0.0;
		cout << "\nHow much would you like to deposit to Savings Account? ";
		cin >> amount;
		Account::deposit(amount);
		//if account is inactive
		if (status == false) {
			if (balance >= 25) {
				//set to active
				status = true;
			}
		}
	}

	virtual void withdraw() {
		//if account is inactive, cannot withdraw
		if (status == false) {
			cout << "\nYou're Savings account is INACTIVE, you cannot withdraw." << endl;
		}
		else {
			double amount = 0.0;
			cout << "\nHow much would you like to withdraw from Savings Account? ";
			cin >> amount;
			Account::withdraw(amount);
			checkStatus();
		}
	}

	virtual void monthlyProc() {
		if (withdrawals > 3) {
			serviceCharge = withdrawals - 3; //multiply by $1, dont need to include it
		}
		Account::monthlyProc();
	}

	bool getStatus() {
		return status;
	}

	void checkStatus() {
		if (balance < 25) {
			status = false; //inactive
		}
	}
};
