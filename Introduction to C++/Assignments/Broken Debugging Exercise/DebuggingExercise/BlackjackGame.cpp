#include "BlackJackGame.h"
#include <iostream>
#include "Deck.h"
#include "Player.h"

BlackjackGame::BlackjackGame() 
{
	// allocate Deck
	m_pDeck = new Deck();

	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		m_apPlayers[i] = new Player();
	}

	Reset();
}

BlackjackGame::~BlackjackGame() 
{
	//Delete players;
	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		delete m_apPlayers[i];
		m_apPlayers[i] = nullptr;
	}

	// deallocate Deck
	delete m_pDeck;
	m_pDeck = nullptr;
}

void BlackjackGame::Reset() 
{
	// clear hands
	for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		m_apPlayers[i]->Reset();
	}

	// shuffle deck
	m_pDeck->Shuffle();

	// reset state of play and current player
	m_eCurrentPlayer = PLAYER_ONE;
	m_eStateOfPlay = IN_PROGRESS;
}

void BlackjackGame::RunTurn(EPlayer player) 
{
	if (player == PLAYER_ONE)
		RunPlayersTurn();
	else
		RunDealersTurn();
}

void BlackjackGame::UpdateStateOfPlay() 
{
	// if a player hasn't received a hand then the game is still in progress
	if (m_eStateOfPlay == IN_PROGRESS && (m_apPlayers[PLAYER_ONE]->GetCardCount() == 0 || m_apPlayers[PLAYER_TWO]->GetCardCount() == 0))
		return;

	// calculate scores to compare
	int player = m_apPlayers[PLAYER_ONE]->GetScore();
	int dealer = m_apPlayers[PLAYER_TWO]->GetScore();

	// if player one is over 21 then dealer wins
	if (player > 21)
		m_eStateOfPlay = PLAYER_TWO_WIN;

	// player wins if dealer over 21 or player higher than dealer
	else if (dealer > 21 || player > dealer)
		m_eStateOfPlay = PLAYER_ONE_WIN;

	// if a draw then it depends if someone got "blackjack"
	else if (player == dealer) 
	{
		// check for blackjack (21 with 2 cards)
		if (m_apPlayers[PLAYER_ONE]->GetCardCount() == 2)
		{
			if (m_apPlayers[PLAYER_TWO]->GetCardCount() != 2)
			{
				m_eStateOfPlay = PLAYER_ONE_WIN;
			}
		}
		else if (m_apPlayers[PLAYER_TWO]->GetCardCount() == 2)
		{
			m_eStateOfPlay = PLAYER_TWO_WIN;
		}
		// no blackjack so it's a draw
		m_eStateOfPlay = DRAW;
	}

	// otherwise dealer wins
	else
		m_eStateOfPlay = PLAYER_TWO_WIN;
}

void BlackjackGame::RunPlayersTurn() 
{
	// draw first two cards
	m_apPlayers[PLAYER_ONE]->AddToHand(m_pDeck->Draw());
	m_apPlayers[PLAYER_ONE]->AddToHand(m_pDeck->Draw());

	// display the current hand and display current score
	std::cout << "Player's cards:" << std::endl;
	m_apPlayers[PLAYER_ONE]->DisplayHand();

	// ask to hit or stand
	bool stand = false;
	while (!stand)
	{
		// loop until correct choice is made
		while (true) 
		{
			std::cout << "Would you like to hit or stand?" << std::endl;
			std::cout << "Enter 1. Hit" << std::endl;
			std::cout << "Enter 2. Stand" << std::endl;

			char choice[64];
			std::cin >> choice;
			std::cin.ignore(99999, '\n');
			std::cin.clear();

			if (strcmp(choice, "1") == 0) 
			{
				// draw another card
				m_apPlayers[PLAYER_ONE]->AddToHand(m_pDeck->Draw());

				// display current hand
				std::cout << "HIT!\n\nYour new hand:" << std::endl;
				m_apPlayers[PLAYER_ONE]->DisplayHand();
				break;
			}
			else if (strcmp(choice, "2") == 0) 
			{
				std::cout << "STAND!" << std::endl;
				stand = true;
				break;
			}
			else
				std::cout << "Invalid selection, choose again." << std::endl;
		}

		// check if bust, and exit if they stood
		int nScore = m_apPlayers[PLAYER_ONE]->GetScore();
		if (nScore > 21)
		{
			std::cout << "BUST!" << std::endl;
			m_eStateOfPlay = PLAYER_TWO_WIN;
			break;
		}
	} 

	std::cout << std::endl;
}

void BlackjackGame::RunDealersTurn() 
{
	if (m_eStateOfPlay == PLAYER_TWO_WIN)
		return;

	// dealer keeps drawing until above player or bust
	int nScore = 0;
	while (nScore < m_apPlayers[PLAYER_ONE]->GetScore())
	{
		m_apPlayers[PLAYER_TWO]->AddToHand(m_pDeck->Draw());
		nScore = m_apPlayers[PLAYER_TWO]->GetScore();
	} 

	// display dealer's cards
	std::cout << "Dealers cards:" << std::endl;
	m_apPlayers[PLAYER_TWO]->DisplayHand();

	if (nScore > 21)
	{
		std::cout << "BUST!" << std::endl;
		m_eStateOfPlay = PLAYER_ONE_WIN;
	}

	std::cout << std::endl;
}