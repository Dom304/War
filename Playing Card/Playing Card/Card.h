// Playing Card.h : This file contains declaration. Program execution begins and ends there.
//
#pragma once
#include <string>
using namespace std;
class Card 
{
public:

	//Constructor w/ two parameters suit type and value of the card
	Card(int suit, int value);

	enum suit
	{
		 Club = 1, Diamond, Heart, Spade
	};

	enum value
	{
		Two=1, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
	};

	//This function tests to see if two cards have equavialent suits
	static string suitequality(Card one, Card two);

	//Compares card one to card two; 1 = greater than , 0 = equal, -1 = less than
	static int valuecompare(Card one, Card two);

	//This function prints the suit and value of desired card
	static string printCard(Card card);


protected:

	int suit;
	int value;

};

