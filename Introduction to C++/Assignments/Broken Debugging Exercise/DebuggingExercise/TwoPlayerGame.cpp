#include "TwoPlayerGame.h"

TwoPlayerGame::TwoPlayerGame() 
{
	Reset();
}

TwoPlayerGame::~TwoPlayerGame()
{
}

void TwoPlayerGame::Reset() 
{
	m_eCurrentPlayer = PLAYER_ONE;
	m_eStateOfPlay = IN_PROGRESS;
}

void TwoPlayerGame::DoTurn() 
{
	RunTurn(m_eCurrentPlayer);
	SwitchPlayer();
}

void TwoPlayerGame::SwitchPlayer() 
{
	if (m_eCurrentPlayer == PLAYER_ONE)
		m_eCurrentPlayer = PLAYER_TWO;
	else
		m_eCurrentPlayer = PLAYER_ONE;
}

EStateOfPlay TwoPlayerGame::GetStateOfPlay()
{ 
	return m_eStateOfPlay; 
}