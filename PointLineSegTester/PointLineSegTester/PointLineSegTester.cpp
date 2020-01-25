#include "stdafx.h"
#include <iostream>
#include "point.h"
#include "lineseg.h"
#include "quad.h"
using namespace std;

int main()
{
	char ans;
	do {

		double x1, x2, x3, x4;
		double y1, y2, y3, y4;

		cout << "Enter x of p1: ";
		cin >> x1;

		cout << "Enter y of p1: ";
		cin >> y1;

		cout << "Enter x of p2: ";
		cin >> x2;

		cout << "Enter y of p2: ";
		cin >> y2;

		cout << "Enter x of p3: ";
		cin >> x3;

		cout << "Enter y of p3: ";
		cin >> y3;

		cout << "Enter x of p4: ";
		cin >> x4;

		cout << "Enter y of p4: ";
		cin >> y4;

		point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
		lineseg l1(p1, p2), l2(p2, p3), l3(p3, p4), l4(p4, p1);
		quad q(l1, l2, l3, l4);

		cout << endl << "Slopes: " << endl << l1.findSlope() << endl << (l2.findSlope()) << endl << l3.findSlope() << endl << (l4.findSlope()) << endl;
		cout << endl << "Distances: " << endl << l1.findDist() << endl << l2.findDist() << endl << l3.findDist() << endl << l4.findDist() << endl;
		cout << endl << "Shape: " << q.getshape() << endl;

		
		cout << endl << "Checking for each type of shape:" << endl;
		cout << "Parallelogram: " << q.ispara() << endl;
		cout << "Rhombus: " << q.isrhomb() << endl;
		cout << "Rectangle: " << q.isrect() << endl;
		cout << "Square: " << q.issq() << endl;

		cout << endl << "Getting most specific shape: " << q.getshape() << endl;

		cout << endl << "ToString function for quad: " << endl << q.tostring() << endl;
		cout << endl << "ToString function for linesegs: " << endl;
		cout << l1.ToString() << endl;
		cout << l2.ToString() << endl;
		cout << l3.ToString() << endl;
		cout << l4.ToString() << endl;
		cout << endl << "ToString function for points: " << endl;
		cout << p1.ToString() << endl;
		cout << p2.ToString() << endl;
		cout << p3.ToString() << endl;
		cout << p4.ToString() << endl;
		

		cout << endl << "Run again? ";
		cin >> ans;

	} while (ans == 'y');
	system("Pause");
    return 0;
}

