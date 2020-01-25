#ifndef _QUAD_H
#define _QUAD_H
#include <string>
#include "point.h"
#include "lineseg.h"
using namespace std;


class quad {
public:
	quad(); //default
	quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4); //constructor
	string tostring();

	void setl1(lineseg l);
	void setl2(lineseg l);
	void setl3(lineseg l);
	void setl4(lineseg l);

	lineseg getl1();
	lineseg getl2();
	lineseg getl3();
	lineseg getl4();

	int isrect();
	int issq();
	int ispara();
	int isrhomb();
	string getshape();

private:

	lineseg myl1, myl2, myl3, myl4;
	string myshape;
	
};

quad::quad() {

	point p(0, 0);
	lineseg l(p, p);
	myl1 = l;
	myl2 = l;
	myl3 = l;
	myl4 = l;
}

quad::quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4) {

	myl1 = l1;
	myl2 = l2;
	myl3 = l3;
	myl4 = l4;
}

string quad::getshape() {

	quad q(myl1, myl2, myl3, myl4);

	if (q.ispara() == 1) {

		if (q.isrect() == 1) {
			if (q.issq() == 1) {
				return ("Square");
				myshape = "Square";
			}
			else {
				return("Rectangle");
				myshape = "Rectangle";
			}

		}
		else if (q.isrhomb() == 1) {
			return("Rhombus");
			myshape = "Rhombus";
		}
		else {
			return ("Parallelogram");
			myshape = "Parallelogram";
		}

	}
	else {
		return ("Irregular Shape");
	}
}

int quad::ispara() {
	if (myl1.findSlope() == myl3.findSlope() && myl2.findSlope() == myl4.findSlope()){
		return 1;
	}
	else {
		return 0;
	}
}

int quad::isrect() {
	if (myl1.findDist() == myl3.findDist() && myl2.findDist() == myl4.findDist() && myl1.findSlope() == (-1/myl2.findSlope()) && myl3.findSlope() == (-1/myl4.findSlope()) && myl1.findSlope() == myl3.findSlope()) {
		return 1;
	}
	else if (myl1.findDist() == myl3.findDist() && myl2.findDist() == myl4.findDist() && (-1 / myl1.findSlope()) == myl2.findSlope() && (-1 / myl3.findSlope()) == myl4.findSlope() ) {
		return 1;
	}
	else {
		return 0;
	}
}

int quad::isrhomb() {
	if (myl1.findDist() == myl2.findDist() && myl1.findDist() == myl3.findDist() && myl1.findDist() == myl4.findDist()) {
		return 1;
	}
	else {
		return 0;
	}
}

int quad::issq() {
	if (myl1.findDist() == myl2.findDist() && myl1.findDist() == myl3.findDist() && myl1.findDist() == myl4.findDist() && myl1.findSlope() == (-1 / myl2.findSlope()) && myl3.findSlope() == (-1 / myl4.findSlope()) && myl1.findSlope() == myl3.findSlope()) {
		return 1;
	}
	else if (myl1.findDist() == myl2.findDist() && myl1.findDist() == myl3.findDist() && myl1.findDist() == myl4.findDist() && (-1 / myl1.findSlope()) == myl2.findSlope() && (-1 / myl3.findSlope()) == myl4.findSlope()) {
		return 1;
	}
	else {
		return 0;
	}

}

void quad::setl1(lineseg l) {
	myl1 = l;
}

void quad::setl2(lineseg l) {
	myl2 = l;
}

void quad::setl3(lineseg l) {
	myl3 = l;
}

void quad::setl4(lineseg l) {
	myl4 = l;
}

lineseg quad::getl1() {
	return myl1;
}

lineseg quad::getl2() {
	return myl2;
}

lineseg quad::getl3() {
	return myl3;
}

lineseg quad::getl4() {
	return myl4;
}

string quad::tostring() {
	point p1, p2, p3, p4;
	p1 = myl1.GetBP();
	p2 = myl2.GetBP();
	p3 = myl3.GetBP();
	p4 = myl4.GetBP();
	quad q(myl1, myl2, myl3, myl4);
	return(q.getshape() + ": " + p1.ToString() + ", " + p2.ToString() + ", " + p3.ToString() + ", " + p4.ToString());
	
}

#endif