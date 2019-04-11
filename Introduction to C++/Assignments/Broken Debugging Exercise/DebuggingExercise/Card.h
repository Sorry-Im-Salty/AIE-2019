#pragma once

enum ECardSuit
{
	HEARTS = 0,
	CLUBS,
	SPADES,
	DIAMONDS,

	SUIT_COUNT
};

enum ECardRank
{
	ACE = 0,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,

	RANK_COUNT
};

class Card
{
public:
	Card(ECardSuit suit, ECardRank rank);
	~Card();

	// returns description of card, i.e. "Ace of Spades"
	const char* GetName();
	ECardSuit GetSuit();
	ECardRank GetRank();

private:
	void CreateName();

	ECardSuit m_eSuit;
	ECardRank m_eRank;

	char m_szCardName[35];
};