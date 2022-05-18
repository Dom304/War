#pragma once
#include <string>
#include <vector>
#include <stack>
#include "Card.h"

using namespace std;

class Deck
{
public:
	Deck();
	~Deck();
	Card* draw();
	void shuffle();


protected:

	//An array with Card pointer. Using pointers is benifical here b/c
	std::vector<Card*> deck;
	std::stack<Card*> temp;


};