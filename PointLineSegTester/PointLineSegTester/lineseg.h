#ifndef _LINESEG_H
#define _LINESEG_H

#include <math.h>
#include "point.h"
#include <string>
#include <cmath>
using namespace std;

class lineseg
{
public:
	// constructors
	lineseg();                         // default constructor
	lineseg(point bp, point ep);   // copy constructor

		void SetBP(point bp);
		void SetEP(point ep);
		point GetBP();
		point GetEP();
		double findDist();
		string ToString();
		double findSlope();

private:
	point mybp, myep;
};

// default constructor
lineseg::lineseg()
{
	mybp.SetX(0);
	mybp.SetY(0);

	myep.SetX(0);
	myep.SetY(0);
}

// fill constructor
lineseg::lineseg(point bp, point ep)
{
	mybp = bp;
	myep = ep;
}

void lineseg::SetBP(point bp) {
	mybp = bp;
}



void lineseg::SetEP(point ep) {
	myep = ep;
}

point lineseg::GetBP() {
	return mybp;
}

point lineseg::GetEP() {
	return myep;
}

double lineseg::findDist() {
	return (pow(pow((mybp.GetX() - myep.GetX()), 2) + pow((mybp.GetY() - myep.GetY()), 2), 0.5));
}

double lineseg::findSlope() {
	

	if ((mybp.GetX() - myep.GetX()) == 0 || (mybp.GetY() - myep.GetY()) == 0) {
		return abs((mybp.GetY() - myep.GetY()) / (mybp.GetX() - myep.GetX()));
	}
	else {
		return ((mybp.GetY() - myep.GetY()) / (mybp.GetX() - myep.GetX()));
	}
}

string lineseg::ToString() {
	return (mybp.ToString() + ", " + myep.ToString());
}
#endif
