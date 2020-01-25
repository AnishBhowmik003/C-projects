// ComplexNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CompNum.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	char ans;
	do {
		system("CLS");
		char choice;

		cout << "1. Randomly generate" << endl;
		cout << "2. Fill in complex num" << endl;
		cout << "3. String Constructor" << endl;
		cin >> choice;
		system("CLS");
		if (choice == '1') {
			complexnum c1;
			complexnum c2;
			cout << "Comp num 1: " << c1.tostring() << endl;
			cout << "Comp num 2: " << c2.tostring() << endl;
			complexnum m, a, s, d;
			m = c1;
			a = c1;
			s = c1;
			d = c1;
			m.multiply(c2);
			a.add(c2);
			s.subtract(c2);
			d.divide(c2);
			cout << "Multiply: " << m.tostring() << endl;
			cout << "Addition: " << a.tostring() << endl;
			cout << "subtraction: " << s.tostring() << endl;
			cout << "Division: " << d.tostring() << endl;

		}

		else if (choice == '2') {
			float a1, a2, b1, b2;
			cout << "Enter 'A' for c1: ";
			cin >> a1;
			cout << "Enter 'B' for c1; ";
			cin >> b1;
			cout << "Enter 'A' for c2: ";
			cin >> a2;
			cout << "Enter 'B' for c2; ";
			cin >> b2;
			complexnum c1(a1, b1);
			complexnum c2(a2, b2);

			cout << "complex number 1: " << c1.tostring() << endl << "complex number 2: " << c2.tostring() << endl;

			
			complexnum m, a, s, d;
			m = c1;
			a = c1;
			s = c1;
			d = c1;
			m.multiply(c2);
			a.add(c2);
			s.subtract(c2);
			d.divide(c2);
			cout << "Multiply: " << m.tostring() << endl;
			cout << "Addition: " << a.tostring() << endl;
			cout << "subtraction: " << s.tostring() << endl;
			cout << "Division: " << d.tostring() << endl;

			
		}
		else if (choice == '3') {
			string compnum, compnum2;
			cout << "Enter 1st complex number: ";
			cin >> compnum;
			cout << "Enter 2nd complex number: ";
			cin >> compnum2;
			complexnum c1(compnum), c2(compnum2);
			cout << "complex number 1: " << c1.tostring() << endl << "complex number 2: " << c2.tostring() << endl;


			complexnum m, a, s, d;
			m = c1;
			a = c1;
			s = c1;
			d = c1;
			m.multiply(c2);
			a.add(c2);
			s.subtract(c2);
			d.divide(c2);
			cout << "Multiply: " << m.tostring() << endl;
			cout << "Addition: " << a.tostring() << endl;
			cout << "subtraction: " << s.tostring() << endl;
			cout << "Division: " << d.tostring() << endl;

		}
		
		else {
			cout << "Invalid input" << endl;
		}
		cout << "Run again? (y/n) ";
		cin >> ans;
	} while (ans == 'y');
	

    return 0;
}

