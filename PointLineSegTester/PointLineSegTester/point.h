#ifndef _POINT_H
#define _POINT_H
#include <string>
using namespace std;

class point
{
public:
	// constructors
	point();                         // default constructor
	point(double x, double y);           // copy constructor

									  // member functions
	void   SetX(double);
	void   SetY(double);
	double   GetX();
	double   GetY();
	string ToString();
	

private:
	// data
	double myx, myy;
};


point::point(double x, double y) {
	myx = x;
	myy = y;
}

point::point() {
	myx = 0;
	myy = 0;
}

//method to get x value
double point::GetX() {
	return myx;
}
//method to get y value;
double point::GetY() {
	return myy;
}
//method to set y
void point::SetX(double x) {
	myx = x;
}
//method to set x
void point::SetY(double y) {
	myy = y;
}
//method tostring

string point::ToString() {
	return ("(" + to_string(myx) + ", " + to_string(myy) + ")");
}





#endif
