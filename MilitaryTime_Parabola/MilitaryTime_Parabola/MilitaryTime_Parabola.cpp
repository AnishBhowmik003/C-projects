// MilitaryTime_Parabola.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int military() {
	int ftime, stime;
	int difhour, difmin;
	int hours, min;
	int fchours, fcmin;
	int schours, scmin;
	cout << "What is the first time?  ";
	cin >> ftime;
	cout << "What is the second time? ";
	cin >> stime;
	fchours = (int)(ftime / 100);
	fcmin = (int)(ftime % 100);
	schours = (int)(stime / 100);
	scmin = (int)(stime % 100);

	if (ftime > stime) {


		if (fcmin > scmin) {
			difmin = 60 - fcmin + scmin;
			difhour = 24 - fchours + schours - 1;
		}
		else if (fcmin <= scmin) {
			difmin = scmin - fcmin;
			difhour = 24 - fchours + schours;
		}
	}

	else if (ftime < stime) {
		if (fcmin > scmin) {
			difhour = schours - fchours - 1;
			difmin = 60 - fcmin + scmin;
		}
		else if (fcmin <= scmin) {
			difhour = schours - fchours;
			difmin = scmin - fcmin;
		}
	}
	else {
		difhour = 0;
		difmin = 0;
	}
	cout << "Hours: " << difhour << '\n';
	cout << "Minutes: " << difmin << '\n';
	return 0;
}

int parabola() {
	cout << "Enter A, B, and C: ";
	double r1, r2;
	double discriminant;
	double a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	discriminant = (b*b) - (4 * a * c);
	if (discriminant == 0) {
		r1 = (-b + sqrt(discriminant)) / (2 * a);
		r2 = r1;
		cout << "Root 1: " << r1 << endl;
		cout << "Root 2: " << r2 << endl;
	}
	else if (discriminant > 0) {
		r1 = (-b + sqrt(discriminant)) / (2 * a);
		r2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "Root 1: " << r1 << endl;
		cout << "Root 2: " << r2 << endl;
	}
	else if (discriminant < 0) {
		double real, imaginary;
		real = -b / (2 * a);
		imaginary = sqrt(-1 * discriminant) / (2 * a);
		cout << "Root 1: " << real << " + i" << imaginary << endl;
		cout << "Root 2: " << real << " - i" << imaginary << endl;


	}
	cout << "Enter X1 and Y1: ";
	double x1, y1, x2, y2;
	double m, d;
	cin >> x1;
	cin >> y1;
	cout << "\nEnter X2 and Y2: ";
	cin >> x2;
	cin >> y2;
	m = (x2 - x1) / (y2 - y1);
	d = y1 - (m * x1);
	//y = mx + b
	// b= y - m * x
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) << "Slope: " << resetiosflags(ios::left) << setw(5) << m << endl;
	cout << setiosflags(ios::left) << setfill(' ') << setw(15) << "Y intercept: " << resetiosflags(ios::left) << setw(5) << d << endl;

	double X, X2;
	double A, B, C;
	double Y, Y2;
	A = a;
	B = (b - m);
	C = (c - d);
	double disc2;
	disc2 = (B*B) - (4 * A * C);
	if (disc2 < 0) {
		cout << "\nThere are no intersections" << endl;
	}
	else if (disc2 >= 0) {
		X = (-B + sqrt(disc2)) / (2 * A);
		X2 = (-B - sqrt(disc2)) / (2 * A);
		Y = (A * (X * X)) + (B * X) + C;
		Y2 = (A * (X2 * X2)) + (B * X2) + C;
		cout << "\nThe points of intersections are: " << X << ", " << Y << "and " << X2 << ", " << Y2;

	}

	return 0;
}

int main() {
	int ans;
	char yesno;
	do {
		
		cout << "1: Military Time\n" << "2: Parabola\n";
		cin >> ans;
		if (ans == 1) {
			military();
		}
		else if (ans == 2) {
			parabola();
		}
		cout << "\nDo you want to run again? (y/n)";
		cin >> yesno;

	} while (yesno == 'y');
	return 0;
}
