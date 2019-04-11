#include "Card.h"
#include <iostream>

Card::Card(ECardSuit suit, ECardRank rank)
{
	m_eSuit = suit;
	m_eRank = rank;
	CreateName();
}

Card::~Card()
{
}

void Card::CreateName()
{
	switch (m_eRank)
	{
	case TWO:
		strcpy_s(m_szCardName, 32, "Two of ");
		break;

	case THREE:
		strcpy_s(m_szCardName, 32, "Three of ");
		break;

	case FOUR:
		strcpy_s(m_szCardName, 32, "Four of ");
		break;

	case FIVE:
		strcpy_s(m_szCardName, 32, "Five of ");
		break;

	case SIX:
		strcpy_s(m_szCardName, 32, "Six of ");
		break;

	case SEVEN:
		strcpy_s(m_szCardName, 32, "Seven of ");
		break;

	case EIGHT:
		strcpy_s(m_szCardName, 32, "Eight of ");
		break;

	case NINE:
		strcpy_s(m_szCardName, 32, "Nine of ");
		break;

	case TEN:
		strcpy_s(m_szCardName, 32, "Ten of ");
		break;

	case JACK:
		strcpy_s(m_szCardName, 32, "Jack of ");
		break;

	case QUEEN:
		strcpy_s(m_szCardName, 32, "Queen of ");
		break;

	case KING:
		strcpy_s(m_szCardName, 32, "King of ");
		break;

	case ACE:
		strcpy_s(m_szCardName, 32, "Ace of ");
		break;
	};

	switch (m_eSuit)
	{
	case CLUBS:
		strcat_s(m_szCardName, 32, "Clubs");
		break;

	case DIAMONDS:
		strcat_s(m_szCardName, 32, "Diamonds");
		break;

	case HEARTS:
		strcat_s(m_szCardName, 32, "Hearts");
		break;

	case SPADES:
		strcat_s(m_szCardName, 32, "Spades");
		break;
	};
}

const char* Card::GetName()
{
	return m_szCardName;
}

ECardSuit Card::GetSuit()
{
	return m_eSuit;
}

ECardRank Card::GetRank()
{
	return m_eRank;
}
