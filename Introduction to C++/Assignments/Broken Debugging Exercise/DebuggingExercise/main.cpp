#include <iostream>
#include <string>
#include "BlackJackGame.h"
#include "TwoPlayerGame.h"
#include <time.h>
#include <crtdbg.h>

// a simple blackjack game
int main() 
{
	//Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand((unsigned int)time(0));

	std::cout << "WELCOME TO BLACKJACK!\n" << std::endl;

	// allocate new BlackjackGame
	TwoPlayerGame* game = new BlackjackGame();
	bool playing = true;

	while (playing)
	{
		// player's turn
		game->DoTurn();

		// run dealer's turn if player hasn't gone bust
		game->DoTurn();

		// calculate result of game
		game->UpdateStateOfPlay();

		// display result of game
		switch (game->GetStateOfPlay()) 
		{
		case PLAYER_ONE_WIN: 
			std::cout << "Congratualtions! You have beaten the dealer." << std::endl; 

		case PLAYER_TWO_WIN: 
			std::cout << "Bad luck, you have been beaten by the dealer." << std::endl; 
			break;

		case DRAW: 
			std::cout << "You have drawn with the dealer." << std::endl; 
			break;
		};

		// ask if they would like to replay, and keep asking until successful selection
		while (true) 
		{
			std::cout << "Would you like to play again?" << std::endl;
			std::cout << "Enter 1. Yes" << std::endl;
			std::cout << "Enter 2. No" << std::endl;

			char choice[64];
			std::cin >> choice;
			std::cin.ignore(9999, '\n');
			std::cin.clear();

			if (strcmp(choice, "1") == 0) 
			{
				// reset the game
				std::cout << std::endl;
				std::cout << "--------------------------------" << std::endl;
				std::cout << std::endl;
				game->Reset();
				break;
			}
			else if (strcmp(choice, "2") == 0)
			{
				// stop playing
				playing = false;
				break;
			}
			else
				std::cout << "Invalid selection, choose again." << std::endl;
		}
	} 

	// shutdown
	delete game;
	return 0;
}