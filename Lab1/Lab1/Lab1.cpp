#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const double SQUARE_ROOT_OF_TWO = 1.414214;

	int i;
	long j;
	unsigned long k;
	float n;
	int hundred;
	int neg;
	int bigneg;
	int big;

	const double e = 2.7182818;
	const int light = 3.00 * pow(10, 8);
	const double sound = 340.292;

	i = 3;
	j = -2048111;
	k = 4000000001;
	n = 1.887;
	hundred = 100;
	neg = -1000;
	bigneg = -40000;
	big = 40000;

	//output constant and variables to screen
	cout << SQUARE_ROOT_OF_TWO << '\n';
	cout << i << '\n';
	cout << j << '\n';
	cout << k << '\n';
	cout << n << '\n';
	cout << hundred << '\n';
	cout << neg << '\n';
	cout << bigneg << '\n';
	cout << big << '\n';
	cout << e << '\n';
	cout << light << " m/s" << '\n';
	cout << sound << " m/s" << '\n';

	system("Pause");

	return 0;

}

