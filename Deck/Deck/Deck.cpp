// Deck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "randgen.h"
#include <string>
#include <clocale>
using namespace std;

struct card {
	int value;
	int suit;
	string cv;
	string cs;
};

struct deck {
	card cards[53];
};

void fill(deck& deck);
void shuffle(deck& deck);
void getstring(deck& deck);
void print(deck deck);

int main()
{
	char ans;
	do {
		deck deck1;
		fill(deck1);
		getstring(deck1);
		shuffle(deck1);
		print(deck1);
		
		
		cout << "Do you want to run again? (y/n)";
		cin >> ans;
	} while (ans == 'y');
	
    return 0;
}

void fill(deck& deck) {
	int f = 1;
	for (int i = 3; i <= 6; i++) {
		for (int a = 1; a <= 13; a++) {
			deck.cards[f].value = a;
			deck.cards[f].suit = i;
			f = f + 1;
		}
		
	}
}

void getstring(deck& deck) {
	for (int i = 1; i <= 52; i++) {
		switch (deck.cards[i].value) {
		case 1: deck.cards[i].cv = "a"; break;
		case 10: deck.cards[i].cv = "10"; break;
		case 11: deck.cards[i].cv = "j"; break;
		case 12: deck.cards[i].cv = "q"; break;
		case 13: deck.cards[i].cv = "k"; break;
		
		default: deck.cards[i].cv = deck.cards[i].value + '0'; break;
		}
		
		deck.cards[i].cs = (char)(deck.cards[i].suit);
		
	}
}

void shuffle(deck& deck) {
	RandGen r;
	for (int i = 1; i <= 52; i++) {
		int a = r.RandInt(1, 52);
		card temp;
		temp = deck.cards[i];
		deck.cards[i] = deck.cards[a];
		deck.cards[a] = temp;

	}
}

void print(deck deck) {
	for (int i = 1; i <= 52; i++) {
		cout << deck.cards[i].cv << (deck.cards[i].cs) << endl;
	}
}

