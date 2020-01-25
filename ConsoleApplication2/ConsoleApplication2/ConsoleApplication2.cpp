// Electric.cpp : Defines the entry point for the console application.
//
#include "pch.h"
#include<iostream>
using namespace std;
#include<iomanip>
#include<windows.h>
#include <time.h>
using namespace std;


int main()
{
	system("color 1C");
	char sdate[9];
	char stime[9];
	_strdate_s(sdate);
	_strtime_s(stime);
	cout << "time; " << stime << " date: " << sdate << endl;

	system("Color 1F");


	float d;
	const float cost = 0.0475;
	double baserate;
	float surcharge;
	float kilo, citytax;

	cout << "Enter kilowatts used: ";
	cin >> kilo;
	cout << '\n';
	cout << "     C O M P S C I Electric" << '\n';
	cout << setfill('*') << setw(34) << "" << endl;

	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "Kilowatts Used" << resetiosflags(ios::left) << setw(14) << (float)kilo << endl;
	cout << setfill('*') << setw(34) << "" << '\n' << endl;
	baserate = cost * kilo; //calculates baserate
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
	cout << setfill(' ') << "Baserate" << setw(6) << (int)kilo << " @ $" << cost << setprecision(2) << setw(6) << "$" << setw(6) << baserate << endl;
	surcharge = 0.1 * baserate; //calculates surcharge
	citytax = 0.03 * baserate; //calculates citytax
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "Surcharge" << resetiosflags(ios::left) << setw(8) << "$" << setw(6) << surcharge << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "Citytax" << resetiosflags(ios::left) << setw(8) << "$" << setw(6) << citytax << endl;


	float total;
	total = baserate + surcharge + citytax;


	d = kilo;


	cout << endl;
	cout << setfill('*') << setw(34) << "" << endl;

	//calculates late fee
	const float late = 0.04;
	float tlate;
	tlate = total + (total * late);

	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "Pay this amount" << resetiosflags(ios::left) << setw(8) << "$" << setw(6) << (float)total << endl;
	cout << '\n';
	cout << setiosflags(ios::left) << setfill(' ') << setw(20) << "After May 20th Pay" << resetiosflags(ios::left) << setw(8) << "$" << setw(6) << (float)tlate << endl;

	cout << setfill('*') << setw(34) << "" << endl;

	cout << " ______ " << endl;
	cout << "| |__| |" << endl;
	cout << "|  ()  |" << endl;
	cout << "|______|" << endl;

	system("Pause");
	return 0;
}