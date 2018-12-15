/*
Author: 		Annie Wu
Assignment:	    Homework #4

Class:			CS 2560.01 - C++ Programming
Date:			14 December 2018

Purpose:		This file holds the base class for bank account information:
					- Balance
					- Number of deposits this month
					- Number of withdrawals
					- Annual Interest Rate
					- Monthly service charges

*/

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//base class
class Account {
protected:
	double balance; //account balance
	int deposits; //number of deposits
	int withdrawals; //number of withdrawls
	double interestRate; //annual interest rate
	double serviceCharge; //monthly service charges

public:
	Account(double bal, double interest) {
		balance = bal;
		interestRate = interest / 100.0; //convert from percentage to decimal
		withdrawals = 0;
		deposits = 0;
		serviceCharge = 0;
	}
	
	virtual void deposit(double depositAmount) {
		balance += depositAmount;
		cout << fixed << setprecision(2);
		cout << "Deposit of $" << depositAmount << " was successful." << endl;
		deposits++; //increase num of deposits
	}

	virtual void withdraw(double withdrawlAmount) {
		balance -= withdrawlAmount;
		cout << fixed << setprecision(2);
		cout << "Withdrawal of $" << withdrawlAmount << " was successful." << endl;
		withdrawals++; //increase num of withdrawls
	}

	void calcInt() {
		double monthlyinterestRate = interestRate / 12.0;
		balance += (balance * monthlyinterestRate);
	}

	virtual void monthlyProc() {
		balance -= serviceCharge;
		calcInt();
		withdrawals = 0;
		deposits = 0;
		serviceCharge = 0;
	}

	double getBalance() {
		return balance;
	}
};
