// Checkbook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale>
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

struct sum {
	int deposits;
	int withdrawals;
	double totald;
	double totalw;
	double balance;
	double total;
	double loan;
};

struct user {
	sum sum;
	string name;
};


double getbalance(double balance, string& name);
void print(char transaction[], double amount[], sum& sum);
void summary(sum& sum, string name);
void servicecharge(double& total);



int main()
{

	char ans;
	
		do {
			user user;
			
			double total = 0;
			double balance = 0;
			char transaction[40];
			double amount[40];
			int i = 0;
			user.sum.loan = 0;
			int deposits = 0;
			int withdrawals = 0;
			
			


			balance = getbalance(balance, user.name);
			user.sum.balance = balance;
			
			do {
				cout << "Transaction: ";
				cin >> (transaction[i]);
				if (toupper(transaction[i]) == 'E') {
					break;
				}
				cout << "Amount: ";
				cin >> amount[i];
				i = i + 1;
			} while (toupper(transaction[i]) != 'E');

			for (int a = i; a <= 30; a++) {
				amount[a] = 0;
			}


			print(transaction, amount, user.sum);
			cout << setfill('-') << setw(80) << "" << endl;
			cout << setfill('-') << setw(80) << "" << endl;
			summary(user.sum, user.name);
			cout << setfill('-') << setw(80) << "" << endl;
			cout << setfill('-') << setw(80) << "" << endl;

			cout << "Run again? (y/n) ";
			cin >> ans;
			cin.ignore();
		} while (ans == 'y');

    return 0;
}

double getbalance(double balance, string& name) {

	cout << "What is your name?";
	getline(cin, name);
	cout << "Welcome to Keybank" << endl;
	cout << "Please enter this month's transactions: " << endl;
	cout << "Balance: ";
	cin >> balance;
	return balance;
}

void print(char transaction[], double amount[], sum& sum) {
	sum.deposits = 0;
	sum.withdrawals = 0;
	sum.totald = 0;
	sum.totalw = 0;
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
	int i;
	cout << setiosflags(ios::left) << setfill(' ') << setw(40) << "\nTransaction" << resetiosflags(ios::left) << setw(20) << "Amount" << setw(20) << "Balance" << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(40) << "Beginning Balance" << resetiosflags(ios::left) << setw(20) << sum.balance << setw(20) << sum.balance << endl;
	i = 0;
	sum.total = sum.balance;
	do {
		
		switch (toupper(transaction[i])) {
		case 'D' : 
			sum.total = sum.total + amount[i];
			cout << setiosflags(ios::left) << setfill(' ') << setw(40) << "Deposit" << resetiosflags(ios::left) << setw(20) << amount[i] << setw(20) << sum.total << endl;
			sum.deposits = sum.deposits + 1;
			sum.totald = sum.totald + amount[i];
			break;
		case 'C' :
			if (sum.total - amount[i] < 0) {
				sum.total = sum.total - 10;
				cout << setiosflags(ios::left) << setfill(' ') << setw(40) << "Insufficient Funds" << resetiosflags(ios::left) << setw(20) << "10.00" << setw(20) << sum.total << endl;
				sum.totalw = sum.totalw + 10;
			}
			else {
				sum.total = sum.total - amount[i];
				cout << setiosflags(ios::left) << setfill(' ') << setw(40) << "Check" << resetiosflags(ios::left) << setw(20) << amount[i] << setw(20) << sum.total << endl;
				sum.totalw = sum.totalw + amount[i];
			}
			sum.withdrawals = sum.withdrawals + 1;
			
			break;
		case 'E': break;
		case 'L': sum.total = sum.total + amount[i];
			cout << setiosflags(ios::left) << setfill(' ') << setw(40) << "Loan" << resetiosflags(ios::left) << setw(20) << amount[i] << setw(20) << sum.total << endl;
			sum.loan = sum.loan + amount[i];
		default: cout << "Illegal Transaction Code" << endl; break;
		}
		i = i + 1;
	} while (amount[i-1] != 0);
	

	servicecharge(sum.total);
	cout << setiosflags(ios::left) << setfill(' ') << setw(40) << "Service Charge" << resetiosflags(ios::left) << setw(20) << "5.00" << setw(20) << sum.total << endl;
	sum.withdrawals = sum.withdrawals + 1;
	sum.totalw = sum.totalw + 5;
}

void servicecharge(double& total) {
	total = total - 5;
}

void summary(sum& sum, string name) {
	cout << "Account Sumary of " << name << endl;
	cout << setfill(' ') << setw(20) << "" << setw(10) << "Number" << setw(10) << "Amount" << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(30) << "Beginning Balance" << setw(10) << resetiosflags(ios::left) << sum.balance << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "Plus Deposits" << setw(10) << resetiosflags(ios::left) << sum.deposits << setw(10) << sum.totald << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "Less Withdrawals" << setw(10) << resetiosflags(ios::left) << sum.withdrawals << setw(10) << sum.totalw << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(30) << "Ending Balance" << setw(10) << resetiosflags(ios::left) << sum.total << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(30) << "Amount owed" << setw(10) << resetiosflags(ios::left) << sum.loan << endl;
}

