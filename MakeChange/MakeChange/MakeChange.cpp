// MakeChange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <iomanip>
using namespace std;
#include <string>
#include <cmath>
using namespace std;
#include <string.h>



int main()
{
	system("color 1C");
	string name;
	string purchase;;
	double recieved, change;
	const double rtx2080 = 799.00;
	const double rtx2070 = 599.00;
	const double rtx2080ti = 1199.00;
	double totalprice;
	double bruh;

	totalprice = 0.00;
	cout << "What is your name? ";
	getline(cin, name);

	int buy, numbought;
	char ans;

	do {

		cout << "What do you want to buy?\n" <<
			"1: RTX 2080 ti\n" <<
			"2: RTX 2080\n" <<
			"3: RtX 2070\n";
		cin >> buy;
		cout << "How many do you want? ";
		cin >> numbought;

		if (buy == 1) {
			totalprice = totalprice + (rtx2080ti * numbought);
		}
		if (buy == 2) {
			totalprice = totalprice + (rtx2080 * numbought);
		}
		if (buy == 3) {
			totalprice = totalprice + (rtx2070 * numbought);
		}

		cout << "Do you want to buy anything else? (y/n) ";
		cin >> ans;

	} while (ans == 'y');

	//purchasing ended
	//outputting price and change

	cout <<setfill(' ') << setw(30) <<"Electronics"<< endl;
	cout << setfill(' ') << setw(30) << name << endl;
	cout << setfill('*') << setw(45) << "" << endl;
	cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);
	cout << "Purchase price:         $ " << setfill(' ') << setw(10) << resetiosflags(ios::right) <<totalprice << endl;
	double finalprice;
	finalprice = totalprice + (totalprice * 0.0575);
	cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);

	cout << "Price after tax         $ " << setfill(' ') << setw(10) << resetiosflags(ios::right) << finalprice << endl;
	cout << "Enter amound recieved:  $    ";
	cin >> recieved;
	change = recieved - finalprice;	//calculates change due

	cout << "Change Due:             $ " << setfill(' ') << setw(10) << resetiosflags(ios::right) << change << endl;
	
	
	cout << setfill('*') << setw(45) << "" << endl;

	double left;
	bruh = (change / 50.00);
	left = fmod(change, 50.00);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "50 Dollars:" << setiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
	setfill(' ') <<'$'<< setw(10) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 50.00) << endl;

	
	bruh = (left / 20.00);
	left = fmod(change, 20.00);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setfill(' ') << setw(15) << setiosflags(ios::left) << "20 Dollars:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 20.00) << endl;

	bruh = (left / 10.00);
	left = fmod(change, 10.00);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "10 Dollars:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 10.00) << endl;
	

	bruh = (left / 5.00);
	left = fmod(change, 5.00);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "5 Dollars:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 5.00) << endl;

	bruh = (left / 1.00);
	left = fmod(change, 1.00);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "1 Dollar:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 1.00) << endl;

	bruh = ((double)left / 0.25);
	left = fmod(change, 0.25);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "Quarter:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 0.25) << endl;

	bruh = (left / 0.10);
	left = fmod(change, 0.10);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "Dime:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 0.10) << endl;

	bruh = (left / 0.05);
	left = fmod(change, 0.05);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "Nickels:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 0.05) << endl;

	bruh = (left / 0.01);
	left = fmod(change, 0.01);
	cout << resetiosflags(ios::fixed) << setprecision(0);
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) <<setiosflags(ios::left)<< "Penny:" << resetiosflags(ios::right) << setfill(' ') << setw(10) << resetiosflags(ios::right) << (int)bruh <<
		setfill(' ') << '$' << setw(10) << resetiosflags(ios::right) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << resetiosflags(ios::left) << (double)((int)bruh * 0.01) << endl;

	//outputs total change
	cout << setfill('*') << setw(45) << "" << endl;
	cout << setfill(' ') << setw(15) << setiosflags(ios::left) << "Change total" << setfill(' ') << setw(21) << setiosflags(ios::right) << change << endl;

	system("Pause");
    return 0;
}