// ZellerFormula.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <iomanip>
using namespace std;
#include <math.h>

int main()
{
	int k;
	int year, c, d;
	int m;
	int f;
	int day;
	cout << "Enter the day: ";
	cin >> k;
	cout << "Enter the month: ";
	cin >> m;
	cout << "Enter the year: ";
	cin >> year;
	c = (int)(year / 100);
	d = (int)(year % 100);

	f = k + ((int)((13 * m - 1) / 5)) + d + ((int)(d / 4)) + ((int)(c / 4)) - (2 * c);
	day = f - (7 * (int)(f / 7));
	cout << "the day is " << day << endl;

    return 0;
	system("pause");
}

