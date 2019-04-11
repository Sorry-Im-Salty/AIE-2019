#include "Deck.h"
#include "Card.h"
#include <iostream>

Deck::Deck() 
{
	m_nAvailableCount = 0;

	// populate deck with unique cards
	for (int i = 0; i < SUIT_COUNT; ++i)
	{
		for (int j = 0; j < RANK_COUNT; ++j)
		{
			// create card and add to the deck
			Card* pCard = new Card((ECardSuit)i, (ECardRank)j);
			m_pAvailable[m_nAvailableCount] = pCard;
			++m_nAvailableCount;
		}
	}

	// randomise
	Shuffle();
}

Deck::~Deck()
{
	int nCardCount = SUIT_COUNT * RANK_COUNT;
	for (int i = 0; i < nCardCount; ++i)
	{
		delete m_pAvailable[i];
		m_pAvailable[i] = nullptr;
	}
}

void Deck::Shuffle() 
{
	// put drawn cards back in the deck
	m_nAvailableCount = 52;

	// randomise available cards using a bubble sort approach (not great)
	for (int i = 0; i < m_nAvailableCount - 1; ++i)
	{
		for (int j = 0; j < m_nAvailableCount - 1; ++j)
		{
			int swap = rand() % 2;
			if (swap == 1)
			{
				Card* pTemp = m_pAvailable[j];
				m_pAvailable[j] = m_pAvailable[j + 1];
				m_pAvailable[j + 1] = pTemp;
			}
		}
	}
}

Card* Deck::Draw() 
{
	--m_nAvailableCount;
	return m_pAvailable[m_nAvailableCount];
}