// SnackBar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <iomanip>
using namespace std;
#include <locale>



double gettax(double &total) {
	double tax;
	tax = total  + (total * 0.06);
	return tax;
}

void printmenu() {
	const double sandwich = 5.99;
	const double chips = 6.99;
	const double brownie = 10.99;
	const double regdrink = 2.99;
	const double ldrink = 4.99;
	cout << setiosflags(ios::left);
	cout << setfill(' ') << setw(20) << "S - Sandwich: " << resetiosflags(ios::left) <<setw(4)<<'$'<< setw(5) << sandwich << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "C - Chips: " << resetiosflags(ios::left) <<setw(4)<<'$'<< setw(5) << chips << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "B - Brownie: " << resetiosflags(ios::left) << setw(4) << '$' << setw(5) << brownie << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "R - Regular Drink: " << resetiosflags(ios::left) << setw(4) << '$' << setw(5) << regdrink << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "L - Large Drink: " << resetiosflags(ios::left) << setw(4) << '$' << setw(5) << ldrink << endl;
	cout << '\n';
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "X - Cancel sale and start over" << endl;
	cout << setfill(' ') << setw(20) << "T - Total the sale" << endl;
}

int main()
{
	char ans;
	int flag;
	do {
		const double sandwich = 5.99;
		const double chips = 6.99;
		const double brownie = 10.99;
		const double regdrink = 2.99;
		const double ldrink = 4.99;
		double total;
		total = 0;
		char choice;
		flag = 1;
		do {
			
			printmenu();
		
				cin >> choice;
				choice = toupper(choice);
				switch (choice) {
				case 'S': total = total + sandwich; break;
				case 'C': total = total + chips; break;
				case 'B': total = total + brownie; break;
				case 'R': total = total + regdrink; break;
				case 'L': total = total + ldrink; break;
				case 'X': total = 0; break;
				case 'T':
					cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);
					total = gettax(total);
					flag = 0;
					break;
				}
			cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);
			cout <<setfill(' ')<< '$'<<resetiosflags(ios::left) <<setw(5) << total << endl;
		} while (flag == 1);


		cout << "Run again? (y/n): ";
		cin >> ans;
	} while (ans == 'y');

    return 0;
}

