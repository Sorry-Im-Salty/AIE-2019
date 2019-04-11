#include "Player.h"
#include "Card.h"
#include <iostream>

Player::Player()
{
	m_nCardCount = 0;
}

Player::~Player()
{
}

void Player::Reset()
{
	m_nCardCount = 0;
}

void Player::AddToHand(Card* pCard)
{
	m_apHand[m_nCardCount] = pCard;
	++m_nCardCount;
}

int Player::GetScore()
{
	int nScore = 0;
	int nAceCount = 0;

	for (int i = 0; i < m_nCardCount; ++i)
	{
		Card* pCard = m_apHand[i];

		switch (pCard->GetRank())
		{
		case TWO:
		case THREE:
		case FOUR:
		case FIVE:
		case SIX:
		case SEVEN:
		case EIGHT:
		case NINE:
		case TEN:
			nScore += pCard->GetRank() + 1;
			break;

		case JACK:
		case QUEEN:
		case KING:
			nScore += 10;
			break;

		case ACE:
			nAceCount++;
			break;
		};
	}

	// include aces (either 11 or 1, as long as they fit!)
	if (nAceCount > 0)
	{
		// only one ace can be an 11
		if ((nScore + 11 + nAceCount - 1) <= 21)
			nScore += 11 + nAceCount - 1;
		else
			nScore += nAceCount;
	}

	return nScore;
}

int Player::GetCardCount()
{
	return m_nCardCount;
}

void Player::DisplayHand()
{
	std::cout << std::endl;
	for (int i = 0; i < m_nCardCount; ++i)
	{
		Card* pCard = m_apHand[i];
		std::cout << "\t" << pCard->GetName() << std::endl;
	}
	std::cout << std::endl;

	int nScore = GetScore();
	std::cout << "Current score: " << nScore << std::endl;
	std::cout << std::endl;
}

