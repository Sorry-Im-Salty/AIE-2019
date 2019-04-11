#pragma once

#include "Deck.h"
#include "TwoPlayerGame.h"

class Player;

class BlackjackGame : public TwoPlayerGame 
{
public:
	BlackjackGame();
	virtual ~BlackjackGame();

	// resets the game state to beginning of play
	virtual void Reset();

	// checks if someone has won
	virtual void UpdateStateOfPlay();

protected:
	// executes correct player's turn
	virtual void RunTurn(EPlayer player);
	void RunPlayersTurn();
	void RunDealersTurn();

	// the card deck and two players' hands
	Deck* m_pDeck;
	Player* m_apPlayers[PLAYER_COUNT];
};