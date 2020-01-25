#ifndef _QUAD_H
#define _QUAD_H
#include <string>
#include "PointLineSegTester\lineseg.h"
#include "PointLineSegTester\point.h"
using namespace std;


class quad {
public:
	quad(); //dafault
	quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4); //constructor
	string tostring;

	void setl1(lineseg l);
	void setl2(lineseg l);
	void setl3(lineseg l);
	void setl4(lineseg l);

	lineseg getl1();
	lineseg getl2();
	lineseg getl3();
	lineseg getl4();

	int isrect(quad q);
	int issq(quad q);
	int ispara(quad q);
	int isrhomb(quad q);

private:

	lineseg myl1, myl2, myl3, myl4;
	
};

quad::quad() {

	point p(0, 0);
	myl1.SetBP(p);
	myl1.SetEP(p);
	myl2.SetBP(p);
	myl2.SetEP(p);
	myl3.SetBP(p);
	myl3.SetEP(p);
	myl4.SetBP(p);
	myl4.SetEP(p);
}

quad::quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4) {

	myl1 = l1;
	myl2 = l2;
	myl3 = l3;
	myl4 = l4;
}

int quad::ispara(quad q) {

}

int quad::isrect(quad q) {

}

int quad::isrhomb(quad q) {

}

int quad::issq(quad q) {

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
	return ();
}
#endif