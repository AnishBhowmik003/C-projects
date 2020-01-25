// Calender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
#include <string.h>
#include <string>
using namespace std;

int fdate = 0;

int Zeller(int day, int month, int year)
{
	if (month == 1)
	{
		month = 13;
		year--;
	}
	if (month == 2)
	{
		month = 14;
		year--;
	}
	int q = day;
	int m = month;
	int k = year % 100;
	int j = year / 100;
	int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
	h = h % 7;
	fdate = h;
	return 0;
}

int main() {
	char ans1;
	do {
		int counter;
		int day, month, year;
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		//calculates the first date
		Zeller(1, month, year);

		int maxday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		string dates[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
			maxday[1] = 29;
		}
		//gets the last day of the month
		int lastday = maxday[month - 1];


		switch (month) {
		case 1: cout << "January"; break;
		case 2: cout << "February"; break;
		case 3: cout << "March"; break;
		case 4: cout << "April"; break;
		case 5: cout << "May"; break;
		case 6: cout << "June"; break;
		case 7: cout << "July"; break;
		case 8: cout << "August"; break;
		case 9: cout << "September"; break;
		case 10: cout << "October"; break;
		case 11: cout << "November"; break;
		case 12: cout << "December"; break;
		}
		cout << '\n';
		cout << setiosflags(ios::left);

		for (int i = 0; i <= 6; i++) {
			cout << setfill(' ') << setw(10) << dates[i];
		}
		cout << resetiosflags(ios::left);

		cout << '\n';
		cout << setfill('-') << setw(71) << "";
		cout << '\n';
		counter = 1;

		if (fdate == 0) {
			cout << '|';
			for (int i = 1; i <= 5; i++) {
				cout << '|' << setfill(' ') << setw(8) << ' ' << '|';

			}
			counter = 7;
		}
		else {
			cout << '|';
			for (int i = 1; i <= (fdate - 1); i++) {
				cout << '|' << setfill(' ') << setw(8) << ' ' << '|';
			}
			counter = fdate;
		}


		for (int i = 1; i <= lastday; i++) {
			if (counter % 7 == 1) {

				cout << '\n';
				cout << setfill('-') << setw(71) << "";


				cout << '\n' << '|';
			}
			cout << '|' << setfill(' ') << setw(8) << i << '|';
			counter = counter + 1;
		}

		cout << '\n';
		cout << "Holiday Legend: ";
		cout << '\n';
		switch (month) {
		case 1: cout << "1: New Year's Day" << endl; break;
		case 2: cout << "12: Lincoln's Birthday" << endl; break;
		case 3: cout << "5: Mardi Gras" << endl; break;
		case 4: cout << "1: April Fool's Day" << endl; break;
		case 5: cout << "5: Cinco de Mayo" << endl; break;
		case 6: cout << "14: Flag Day" << endl; break;
		case 7: cout << "4: Independance Day" << endl; break;
		case 8: cout << "4: Obama's Birthday" << endl; break;
		case 9:cout << "2: Labor Day" << endl; break;
		case 10:cout << "31: Halloween" << endl; break;
		case 11:cout << "28: Thanksgiving" << endl; break;
		case 12:cout << "25: Christmas" << endl; break;
		}
		cout << "Run again? (y/n): ";
		
		cin >> ans1;

	} while (ans1 == 'y');
	return 0;
	system("Pause");
}