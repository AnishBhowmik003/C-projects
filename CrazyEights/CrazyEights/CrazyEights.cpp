// CrazyEights.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "randgen.h"
#include <string>
#include <fstream>
using namespace std;

struct card {
	int v;
	int s;
	string strs;
	string strv;
	int pos;
	
};

struct deck {
	card cards[52];
	card top;
	int remaining;
};

struct player {
	card hand[100];
	int numcards;
};


void fill(deck& deck);
void shuffle(deck& deck);
void getstring(deck& deck);
void print(card card);
void replace(deck& deck, player& player, int choice);
void draw(player& target, int num, deck& deck, int& f);

int main()
{
	char ans;
	do {
		int turns;
		RandGen r;
		player player1;
		player bot1;
		player1.numcards = 0;
		bot1.numcards = 0;
		deck deck;
		fill(deck);
		shuffle(deck);
		getstring(deck);
		//deals starting cards to player and bots

		for (int i = 1; i <= 7; i++) {
			player1.hand[i] = deck.cards[i];
			player1.numcards = player1.numcards + 1;
			bot1.hand[i] = deck.cards[i + 7];
			bot1.numcards = bot1.numcards + 1;
		}
		deck.top = deck.cards[15];
		int f = 15;
		//prints out cards
		
		int valid;
		int win = 0;
		turns = 1;
		do {
			if (turns % 2 != 0) { //player1's turn
				
				do {
					cout << "Your hand: ";
					for (int i = 1; i <= player1.numcards; i++) {
						print(player1.hand[i]);
					}
					cout << endl << "Top card: ";
					print(deck.top);
					cout << endl;
					cout << "Choose card (0 = draw card): ";

					int choice;
					cin >> choice;

					if (choice == 0) {
						f = f + 1;
						player1.hand[player1.numcards + 1] = deck.cards[f];
						player1.numcards = player1.numcards + 1;
						valid = 0;
					}
					else if (player1.hand[choice].v == 8) {
						int s;
						cout << "What suit do you want? h(3), d(4), c(5), s(6): ";
						cin >> s;
						player1.hand[choice].s = s;
						player1.hand[choice].strs = (char)(s);
						replace(deck, player1, choice);
						valid = 1;
					}

					else {
						if (player1.hand[choice].strv == deck.top.strv || player1.hand[choice].strs == deck.top.strs) {
							switch (player1.hand[choice].v) {
							case 11:
								cout << "bot skips turn" << endl;
								replace(deck, player1, choice);
								turns = turns + 1;
								break;
							case 12:
								cout << "bot draws 1" << endl;
								replace(deck, player1, choice);
								draw(bot1, 1, deck, f);
								turns = turns + 1;
								break;
							case 13:
								cout << "bot draws 2" << endl;
								replace(deck, player1, choice);
								draw(bot1, 2, deck, f);
								turns = turns + 1;
								break;
							default: replace(deck, player1, choice); break;
							}
							
							valid = 1;
						}
						
					}
					
				} while (valid == 0);
			}

			else { //bot1's turn
				
				valid = 0;
				card working;
				int choice;
				int works = 0;
				
				do {
					for (int i = 1; i <= bot1.numcards; i++) {
						if (bot1.hand[i].v == deck.top.v || bot1.hand[i].s == deck.top.s || bot1.hand[i].v == 8) {
							working = bot1.hand[i];
							choice = i;
							works = 1;
						}
					}
					if (works == 0) {
						f = f + 1;
						bot1.hand[bot1.numcards + 1] = deck.cards[f];
						bot1.numcards = bot1.numcards + 1;
						valid = 0;
					}
					else if (works == 1) {
						valid = 1;
						if (working.v == 8) {
							int o = r.RandInt(3, 6);
							bot1.hand[choice].s = o;
							bot1.hand[choice].strs = (char)(o);
							replace(deck, bot1, choice);
						}

						else {
							switch (working.v) {
							case 11:
								cout << "your turn is skipped" << endl;
								replace(deck, bot1, choice);
								turns = turns + 1;
								break;
							case 12:
								cout << "you draw 1" << endl;
								replace(deck, bot1, choice);
								draw(player1, 1, deck, f);
								turns = turns + 1;
								break;
							case 13:
								cout << "you draw 2" << endl;
								replace(deck, bot1, choice);
								draw(player1, 2, deck, f);
								turns = turns + 1;
								break;
							default: replace(deck, bot1, choice); break;
							}
						}
					}
				} while (valid == 0);
				
			}
			
			

			if (f > 52) {
				cout << endl <<"IT'S A TIE";
			}
			if (player1.numcards == 0) {
				cout << endl << "YOU WIN!";
				win = 1;
			}
			else if (bot1.numcards == 0) {
				cout << endl << "YOU LOSE!";
				win = 1;
			}
			turns = turns + 1;
		} while (win == 0);
		
		


		cout << "Run again? (y/n)";
		cin >> ans;
	} while (ans == 'y');
    return 0;
}

void fill(deck& deck) {
	int f = 1;
	for (int i = 3; i <= 6; i++) {
		for (int a = 1; a <= 13; a++) {
			deck.cards[f].v = a;
			deck.cards[f].s = i;
			f = f + 1;
		}

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
		deck.cards[i].pos = i;
		
	}
}

void getstring(deck& deck) {
	for (int i = 1; i <= 52; i++) {
		switch (deck.cards[i].v) {
		case 1: deck.cards[i].strv = "a"; break;
		case 10: deck.cards[i].strv = "10"; break;
		case 11: deck.cards[i].strv = "j"; break;
		case 12: deck.cards[i].strv = "q"; break;
		case 13: deck.cards[i].strv = "k"; break;
		default: deck.cards[i].strv = '0' + deck.cards[i].v; break;
		}
		deck.cards[i].strs = (char)(deck.cards[i].s);
	}
}

void print(card card) {
	cout <<setiosflags(ios::left) << setfill(' ') << setw(1) << "[" << setw(3) << card.strv << setw(3) << card.strs << card.strv << "]" << "   ";
}

void replace(deck& deck, player& player, int choice) {
	deck.top = player.hand[choice];
	player.numcards = player.numcards - 1;
	for (int i = choice; i <= 50; i++) {
		player.hand[i] = player.hand[i + 1];
		
	}
	
}

void draw(player& target, int num, deck& deck, int& f) {
	
	for (int i = 1; i <= num; i++) {
		f = f + 1;
		target.hand[target.numcards + i] = deck.cards[f];
		target.numcards = target.numcards + 1;
	}
}