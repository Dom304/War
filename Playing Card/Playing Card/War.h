#pragma once

#include <string>
#include <vector>
#include <stack>
#include "Deck.h"

class War {
public:
	//Constructor for war game
	War();
	//Decontructor for war game
	~War();

public:
	//This will start the game of war >:)
	void play();
	//Deals the deck of cards in half; 26 for player and 26 for CPU
	void deal();

protected:
	//Creating an deck that's lifetime is the start and end of program
	Deck deck;
	//An array w/ Card pointer deck for player
	std::vector<Card*> hand_Player;
	//An array w/ Card pointer deck for CPU
	std::vector<Card*> hand_CPU;
};