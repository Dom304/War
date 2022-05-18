#include <iostream>
#include <vector>
# include "War.h"



War::War()
{

}

War::~War()
{

}

void War::play()
{
	std::string playername;
	std::cout << "Welcome to the game of War!, what is your name?: ";
	std::cin >> playername;
	std::cout << "Hello " << playername << "! I hope you enjoy!" << "\n";
	std::cout << "------------------------------------------------------------" << "\n";
	//Setting up our deck and players hands
	deck.shuffle();
	deal();

	//Here we are going to keep camparing the cards til either there is a win or player forefeits
	bool gameOver = false;
	int output;
	int playerIndex = 25;
	int cpuIndex = 25;
	while (gameOver == false) 
	{
		std::cout << "------------------------------------------------------------" << "\n";
		std::cout << "*cards are flipped*" << "\n";
		Card player = *hand_Player[hand_Player.size()-1];
		Card CPU = *hand_CPU[hand_CPU.size() - 1];
		std::cout << playername << "'s: " << player.printCard(player) << "\n";
		std::cout << "CPU's: " << CPU.printCard(CPU) << "\n";
		int compare = player.valuecompare(player, CPU);

		//In war, and both player and CPU's cards are equal (tied values)
		if (compare == 0) 
		{
			//start war
			std::cout << "The cards are tied!" << "\n";
			std::cout << "War ensues!" << "\n";
			
			//Player and cpu must have atleast 4 cards in hand, otherwise they lose
			//Check players hand size for <=4
			if (hand_Player.size() <= 4)
			{
				//Checking to see if cpu has less cards, if so techinally they lost first
				if (hand_CPU.size() < hand_Player.size())
				{
					std::cout << playername << " has won the game!" << "\n";
					std::cout << "------------------------------------------------------------" << "\n";
					gameOver = true;
					exit;
				}
				//player has <= 4 and cpu does not
				std::cout << "CPU has won the game!" << "\n";
				std::cout << "------------------------------------------------------------" << "\n";
				gameOver = true;
				exit;
			}

			//Check if cpu <=4
			if (hand_CPU.size() < 4)
			{
				std::cout << playername << " has won the game!" << "\n";
				std::cout << "------------------------------------------------------------" << "\n";
				gameOver = true;
				exit;
			}
			//Both cpu and player have equal to or more than 4 cards in hand
			
			//Compare player and cpu's n-4 card (use size-1 b/c vector begins with 0 not 1)
			Card playerFourth = *hand_Player[(hand_Player.size()-1) - 4];
			Card cpuFourth = *hand_CPU[(hand_CPU.size()-1) - 4];
			//Return value for the card compare function
			std::cout << playername << "'s war card: "<< playerFourth.printCard(playerFourth) << "\n";
			std::cout <<"CPU's war card: " << cpuFourth.printCard(cpuFourth) << "\n";
			
			int warCompare = playerFourth.valuecompare(playerFourth, cpuFourth);

			//player's fourth down card was greater
			if (warCompare == 1)
			{
				//putting cpu's n through n-4 cards at the begining of player's vector
				for (int i = 0; i <= 4; i++)
				{
					//If cpu has no more card stop
					if (hand_CPU.size() == 0)
					{
						gameOver = true;
						exit;
					}
					//Putting cpu's card at the begining of player's vector (bottom of their deck)
					hand_Player.insert(hand_Player.begin(), hand_CPU[hand_CPU.size()-1]);
					//Removing cpu's card from their hand
					hand_CPU.pop_back();
				}

				//putting player's n through n-4 cards at the begining of their vector (bottom of their deck)
				for (int i = 0; i <= 4; i++)
				{
					//Putting player's card at the begining of player's vector (bottom of their deck)
					hand_Player.insert(hand_Player.begin(), hand_Player[hand_Player.size() -1]);
					//Removing player's card from the top since moved to the back
					hand_Player.pop_back();
				}
				std::cout << playername << " has won the war!" << "\n";
				std::cout << "------------------------------------------------------------" << "\n";
				exit;
			}

			//Both player and cpu's cards were tied again
			if (warCompare == 0)
			{
				bool war = true;
				while (war == true)
				{
					//start war again
					std::cout << "The cards are tied again!" << "\n";
					std::cout << "War has ensued again!" << "\n";
					 
					//Need to see if player and cpu have atleast 4 cards more cards in hand, otherwise they lose
					if (hand_Player.size()-4 <= 4)
					{
						//Here we are checking to see if cpu has less cards, if so techinally they lost first
						if (hand_CPU.size()-4 < hand_Player.size()-4)
						{
							std::cout << "CPU has no more cards, " << playername << " has won the game!" << "\n";
							std::cout << "------------------------------------------------------------" << "\n";
							gameOver = true;
							war = false;
							exit;
						}
						//player has less than 4 and cpu does not
						if (hand_CPU.size()-4 <= 4)
						{
							std::cout << playername << "has no more cards, CPU has won the game!" << "\n";
							std::cout << "------------------------------------------------------------" << "\n";
							gameOver = true;
							war = false;
							exit;
						}
					}

					//See if cpu has atleast 4 or more cards in hand, otherwise they lose
					if (hand_CPU.size()-4 <= 4)
					{
						std::cout << playername << "has no more cards, CPU has won the game!" << "\n";
						std::cout << "------------------------------------------------------------" << "\n";
						gameOver = true;
						war = false;
						exit;
					}

					//Here we compare again
					//Compare player and cpu's n-8 card
					int warCount = 2; //Number of times player and cpu have been at war; helps with knowning what the card is needed for camparison
					Card playerWar = *hand_Player[(hand_Player.size()-1) - 4*warCount];
					Card cpuWar = *hand_CPU[(hand_CPU.size()-1) - 4*warCount];
					int warCompareTwo = playerWar.valuecompare(playerWar, cpuWar);
					std::cout << playername << "'s war card: " << playerWar.printCard(playerWar) << "\n";
					std::cout << "CPU's war card: " << cpuWar.printCard(cpuWar) << "\n";


					//Player's war card was greater
					if (warCompareTwo == 1)
					{
						std::cout << playername << " has won the war!" << "\n";
						std::cout << "------------------------------------------------------------" << "\n";
						//If cpu has no more card stop
						if (hand_CPU.size() <= 4 * warCount)
						{
							gameOver = true;
							war = false;
							exit;
						}
						//putting cpu's n through n*warCount cards at the begining of player's vector
						for (int i = 0; i <= (4 * warCount); i++)
						{
								//Putting cpu's war cards at the begining of player's vector (bottom of their deck)
								hand_Player.insert(hand_Player.begin(), hand_CPU[(hand_CPU.size() - 1)]);
								//Removing cpu's card from their hand
								hand_CPU.pop_back();
							
						}
						//putting player's n through n*warCount cards at the begining of their vector
						for (int i = 0; i <= (4 * warCount); i++)
						{
							//putting player's war cards back to the begining of their vector (bottom of their deck)
							hand_Player.insert(hand_Player.begin(), hand_Player[hand_Player.size() - 1]);
							hand_Player.pop_back();
						}
						//stop war
						war = false;
						exit;
					}

					//Player and cpu's cards were equal; another war ensues
					if (warCompareTwo == 0)
					{
						warCount++;
						war = false;
						std::cout << " the cards are tied for the" << warCount << " time, war ensues again!" << "\n";
						exit;
					}

					//Cpu's war card was greater
					if (warCompareTwo == -1)
					{
						std::cout << "CPU has won the war!" << "\n";
						std::cout << "------------------------------------------------------------" << "\n";
						//If player has no more card stop now
						if (hand_Player.size() <= (4 * warCount))
						{
							gameOver = true;
							war = false;
							exit;
						}
						//putting player's n through n-4*warcount cards at the begining of cpu's vector
						for (int i = 0; i <= (4 * warCount); i++)
						{
							//Putting player's war cards at the begining of cpu's vector (bottom of their deck)
							hand_CPU.insert(hand_CPU.begin(), hand_Player[(hand_Player.size() - 1)]);
							//Removing player's card from their hand
							hand_Player.pop_back();

						}

						for (int i = 0; i <= (4 * warCount) - 1; i++)
						{
							//putting cpu's war cards back to the begining of the their vector (bottom of their deck)
							hand_CPU.insert(hand_CPU.begin(), hand_CPU[(hand_CPU.size() - 1)]);
							hand_CPU.pop_back();
						}
						//stop war
						war = false;
						exit;
					}
				}
			}

			//cpu's card was greater in war
			if (warCompare == -1)
			{
				//putting player's n through n-4 cards at the begining of cpu's vector
				for (int i = 0; i <= 4; i++)
				{
					//If player has no more card stop
					if (hand_Player.size() == 0)
					{
						gameOver = true;
						exit;
					}
					//Puts player's card at the begining of card's vector (bottom of their deck)
					hand_CPU.insert(hand_CPU.begin(), hand_Player[hand_Player.size()-1]);
					hand_Player.pop_back();
				}
				//Puts cpu's n through n-4 card at the begining of their vector (bottom of their deck)
				for (int i = 0; i <= 4; i++)
				{
					hand_CPU.insert(hand_CPU.begin(), hand_CPU[hand_CPU.size()-1]);
					hand_CPU.pop_back();
				}
				std::cout << "CPU has won the war!" << "\n";
				std::cout << "------------------------------------------------------------" << "\n";
			}
		}
		//player's card was greater thus CPU loses a card
		if (compare == 1) 
		{
			std::cout << playername << "'s card was greater!" << "\n";
			//Putting cpu's card at begin of player's vector (bottom of their deck)
			hand_Player.insert(hand_Player.begin(), hand_CPU[hand_CPU.size() - 1]);
			hand_CPU.pop_back();
			//Putting player's current card at the begining of the vector
			hand_Player.insert(hand_Player.begin(), hand_Player[hand_Player.size()-1]);
			hand_Player.pop_back();
		}
		//CPU's card was greater thus player loses a card
		if (compare == -1)
		{
			std::cout << "CPU's card was greater!" << "\n";
			//Putting player's card at begin of cpu's vector (bottom of their deck)
			hand_CPU.insert(hand_CPU.begin(), hand_Player[hand_Player.size() - 1]);
			hand_Player.pop_back();
			//Putting player's current card at the begining of the vector
			hand_CPU.insert(hand_CPU.begin(), hand_CPU[hand_CPU.size() - 1]);
			hand_CPU.pop_back();
		}

		//Checking to see if player and CPU's hands are not less than 1
		//Player has no cards therefore they lose
		if (hand_Player.size() < 1)
		{
			gameOver = true;
			std::cout << playername << "has no more cards, CPU has won the war!" << "\n";
			std::cout << "------------------------------------------------------------" << "\n";
			exit;
		}
		//CPU has no cards therefore they lose
		if (hand_CPU.size() < 1)
		{
			gameOver = true;
			std::cout << "CPU has no more cards, " << playername << " has won the war!" << "\n";
			std::cout << "------------------------------------------------------------" << "\n";
			exit;
		}

		//Giving player chance to opt out
		std::cout << "------------------------------------------------------------" << "\n";
		std::cout << "Would you like to continue?" << "\n" << "Enter 1 for 'Yes' or 0 for 'No'. " << "\n";
		std:: cin >> output;

		//Player wants to forefeit they lose
		if (output == 0) 
		{
			gameOver = true;
			std::cout << "You forefeited,  CPU wins!" << "\n";
			std::cout << "------------------------------------------------------------" << "\n";
			exit;
		}
	}
	exit;
}

void War::deal() 
{
	//Here drawing 26 cards from our passed in deck into player's hand
	for (int i = 0; i < 26; i++) 
	{
		hand_Player.push_back(deck.draw());
	}

	//Here we are drawing 26 more cards from deck into CPU's hand
	for (int i = 0; i < 26; i++) 
	{
		hand_CPU.push_back(deck.draw());
	}
}