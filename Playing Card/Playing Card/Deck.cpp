#include "Deck.h"
#include<cstdlib>
#include<algorithm>
#include<random>
#include<iostream> 
#include<iomanip> 
#include<cstdlib> 
#include<ctime>


Deck::Deck()
{
	
	//Looping through card suits
	for (int i = 1; i <= Card::suit::Spade; i++) {
		//looping through card values
		for (int k = 1; k <= Card::value::Ace; k++) {
			//Here create a card with every suit and value combo
			Card *newCard = new Card(i, k);
			this->deck.push_back(newCard);
		}
	}

	for (int i = 0; i < this->deck.size(); i++)
	{
		this->temp.push(this->deck[i]);
	}
}

Deck::~Deck()
{
	for (int i = 0; i < this->deck.size(); i++)
	{
		delete this->deck[i];
	}
}

/*A draw method will allow the caller to receive a pointer to the Card on the top of the shuffled deck.
The Card will be popped from the stack.
*/
Card* Deck::draw()
{
		//get value
		Card* tempCard;
		//to remove
		tempCard = this->temp.top();
		this->temp.pop();
		return tempCard;
}

/*
A shuffle method will shuffle the Card pointers into an STL stack. 
Note that only the pointers will be added to the stack.  
Shuffle may be called at any time to "reshuffle".  
Reshuffling clears the stack and repopulates with the full deck.

*/
void Deck::shuffle()
{
	//empty the stack
	while (!temp.empty())
	{
		temp.pop();
	 }

	//Transferring Deck to Stack
	//Build-it random shuffle
	srand(time(NULL));
	random_shuffle(this->deck.begin(), this->deck.end());

	//pop deck into temp
	for (int i = 0; i < this->deck.size(); i++)
	{
		this->temp.push(this->deck[i]);
	}
}