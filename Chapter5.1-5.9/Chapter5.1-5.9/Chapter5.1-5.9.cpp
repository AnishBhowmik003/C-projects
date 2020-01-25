// Chapter5.1-5.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>


int transportation() {
	int people;
	int bus;
	int remainder;
	cout << "How many people do you have?";
	cin >> people;
	bus = people / 50;
	remainder = people % 50;
	cout << "You will need " << bus << " busses" << endl;
	cout << "You have " << remainder << " people left that need to be in vans" << endl;

	return 0;
}

int ellipse() {
	double a, b;
	double area;
	cout << "What is the a axis?\n";
	cin >> a;
	cout << "What is the b axis?\n";
	cin >> b;
	area = a * b * 3.14;
	cout << "The area of the ellipse is " << area << " units\n";

	return 0;
}

int degree() {
	double degrees;
	double radians;
	cout << "What is the number of degrees?";
	cin >> degrees;
	radians = degrees / 57.3;
	cout <<"That equals "<< radians << " radians" << endl;
	cout << '\n';
	return 0;
}

int miles() {
	double mph, feet;
	cout << "What is the number of miles per hour? ";
	cin >> mph;
	feet = mph * 1.467;
	cout << "That equals " << feet << " feet per second" << '\n';
	cout << '\n';
	return 0;
}

int finance() {
	double interest;
	double principle, ir, period;
	cout << "What is the principle? ";
	cin >> principle;
	cout << "What is the interest rate? ";
	cin >> ir;
	cout << "What is the time period (in years)? ";
	cin >> period;
	interest = principle * ir * period;
	cout << "The simple interest is: " << interest << '\n';
	cout << '\n';
	return 0;
}

int electricity() {
	double i, v, r;
	cout << "What is the voltage drop across the resistor?";
	cin >> v;
	cout << "What is the resistance in ohms?";
	cin >> r;
	i = v / r;
	cout << "The current is: " << i << " amps" << '\n';
	cout << '\n';
	return 0;
}

int force() {
	double mass, acceleration, force;
	cout << "What is the mass?";
	cin >> mass;
	cout << "what is the acceleration?";
	cin >> acceleration;
	force = mass * acceleration;
	cout << "The force is " << force << " newtons" << '\n';
	cout << '\n';
	return 0;
}

int energy() {
	double e, m;
	int c;
	c = 299792458;
	cout << "What is the mass?";
	cin >> m;
	e = m * (c * c);
	cout << "Using Einstein's energy equation, e = " << e << '\n';
	cout << '\n';
	return 0;
}

int law() {
	const double baserate = 130;
	const int a = 5;
	double above;
	double cost;
	cout << "How many miles were you above the speed limit?";
	cin >> above;
	cost = baserate + (above * a);
	cout << "The cost will be: $" << cost << '\n';
	cout << '\n';
	return 0;
}

int main()
{
	int choice;
	
	string ans;
	do {
		cout << "Enter choice:\n" <<
			"1: Transportation\n" <<
			"2: Ellipse\n" <<
			"3: Degrees to Radians\n" <<
			"4: MPH to FPS\n" <<
			"5: Finance\n" <<
			"6: Electricity\n" <<
			"7: Force\n" <<
			"8: Energy\n" <<
			"9: Law Enforcement\n" <<
			"0: Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			transportation();
		}
		if (choice == 2)
		{
			ellipse();
		}
		if (choice == 3)
		{
			degree();
		}
		if (choice == 4)
		{
			miles();
		}
		if (choice == 5)
		{
			finance();
		}
		if (choice == 6)
		{
			electricity();
		}
		if (choice == 7)
		{
			force();
		}
		if (choice == 8)
		{
			energy();
		}
		if (choice == 9)
		{
			law();
		}

	} while (choice != 0);
	return 0;
}



