#ifndef _COMPNUM_H
#define _COMPNUM_H
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include "randgen.h"
using namespace std;

class complexnum {
public: 
	
	complexnum(); //random constructor
	
	complexnum(float a, float b); //fill constructor
	complexnum(string s); //string constructor

	//member functions

	string tostring();
	void add(complexnum c);
	void subtract(complexnum c);
	void multiply(complexnum c);
	void divide(complexnum c);
	void setconj();
	vector<string> split(string str, char breakOn);

	float geta();
	float getb();
	void seta(float a);
	void setb(float b);

private: 
	float mya, myb;
};


#endif

void complexnum::seta(float a) {
	mya = a;
}

void complexnum::setb(float b) {
	myb = b;
}

float complexnum::geta() {
	return mya;
}

float complexnum::getb() {
	return myb;
}

void complexnum::setconj() {
	myb = myb * -1;
}

complexnum::complexnum(string statement) {


	if (strstr(statement.c_str(), "+")) {
		mya = atoi(split(statement, '+')[0].c_str());
		myb = atoi(split(statement, '+')[1].c_str());
	}
	else if (strstr(statement.c_str(), "-")) {
		mya = atoi(split(statement, '-')[0].c_str());
		myb = atoi(split(statement, '-')[1].c_str());
	}
	

}

complexnum::complexnum() {
	RandGen r;
	mya = r.RandInt(1, 30);
	myb = r.RandInt(1, 30);
}

complexnum::complexnum(float a, float b) {
	mya = a;
	myb = b;
}

string complexnum::tostring() {
	return (to_string(mya) + " + " + to_string(myb) + "i");
}

void complexnum::add(complexnum c) {
	mya = mya + c.geta();
	myb = myb + c.getb();
}

void complexnum::subtract(complexnum c) {
	mya = mya - c.geta();
	myb = myb - c.getb();
}

void complexnum::multiply(complexnum c) {
	float a1, a2, b1, b2;
	a1 = mya;
	a2 = c.geta();
	b1 = myb;
	b2 = c.getb();
	mya = (a1 * a2) + (-1 * b1 * b2);
	myb = (a1 * b2) + (a2 * b1);
}

void complexnum::divide(complexnum c) {
	float a1, a2, b1, b2;
	a1 = mya;
	a2 = c.geta();
	b1 = myb;
	b2 = c.getb();
	complexnum c1(a1, b1);
	complexnum conj(a2, -1 * b2);
	float bottom;
	c1.multiply(conj);
	bottom = (a2 * conj.geta()) + (b2 * conj.getb() * -1);
	string bot;

	c1.mya = c1.mya / bottom;
	c1.myb = c1.myb / bottom;

	mya = c1.mya;
	myb = c1.myb;

	//return (c1.tostring() + " / "  + to_string(bottom));
	
}

vector<string> complexnum::split(string str, char breakOn) {
	string statement1 = "";
	string statement2 = "";
	vector<std::string>sVec;
	bool hit = false;

	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) != breakOn && hit == false) {
			statement1 += str.at(i);
		}
		else if (str.at(i) == breakOn) {
			sVec.push_back(statement1);
			hit = true;
		}
		else if (str.at(i) != breakOn && hit == true) {
			statement2 += str.at(i);
		}
	}
	sVec.push_back(statement2);
	return sVec;
}

