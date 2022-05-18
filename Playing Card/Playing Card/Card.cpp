// Playing Card.cpp : This file contains implementation. Program execution begins and ends there.

#include <stdio.h>
#include <string>
#include "Card.h"
#pragma once


	Card::Card(int suit, int value) 
	{
		this->suit = suit;
		this->value = value;
	}

string Card::printCard(Card card) {
	string cardVal;
	string cardSuit;
	//switch statment to take the card's value and convert it back to value name
	switch (card.value)
	{
	case 1:
		cardVal = "Two";
		break;
	case 2:
		cardVal = "Three";
		break;
	case 3:
		cardVal = "Four";
		break;
	case 4:
		cardVal = "Five";
		break;
	case 5:
		cardVal = "Six";
		break;
	case 6:
		cardVal = "Seven";
		break;
	case 7:
		cardVal = "Eight";
		break;
	case 8:
		cardVal = "Nine";
		break;
	case 9:
		cardVal = "Ten";
		break;
	case 10:
		cardVal = "Eleven";
		break;
	case 11:
		cardVal = "Twelve";
		break;
	case 12:
		cardVal = "Jack";
		break;
	case 13:
		cardVal = "Queen";
		break;
	case 14:
		cardVal = "King";
		break;
	case 15:
		cardVal = "Ace";
		break;
	}
	//switch statment to take the value of the suit and convert it back to value name
	switch (card.suit)
	{
	case 1:
		cardSuit = "Clubs";
		break;
	case 2:
		cardSuit = "Diamonds";
		break;
	case 3:
		cardSuit = "Hearts";
		break;
	case 4:
		cardSuit = "Spades";
		break;
	}
	return  cardVal + " of " + cardSuit;
}

string Card::suitequality(Card one, Card two) {
	//Getting suit type of each card
	int onesuit = one.suit;
	int twosuit = two.suit;

	//Seeing is equal here
	if (onesuit == twosuit) {
		return "Suits are equal to each other";
	}
	return "Suits are not equal";
}

int Card::valuecompare(Card one, Card two) {
	//Getting values of each card
	int one_value = one.value;
	int two_value = two.value;
	
	//Compare info here (equal to, greater than or less than)
	//"Values are equal."
	if (one_value == two_value) {
		return 0;
	}
	//"Card one is greater than card two."
	if (one_value > two_value) {
		return 1;
	}
	//"Card one is less than card two."
	if (one_value < two_value) {
		return -1;

	}
}
