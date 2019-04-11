#pragma once

class Card;

// a deck of 52 playing cards
class Deck 
{
public:
	Deck();
	virtual ~Deck();

	// shuffle drawn cards back into the deck and randomise
	void Shuffle();

	// draw first card from the available list and store in drawn
	Card* Draw();

private:
	Card* m_pAvailable[52];
	int m_nAvailableCount;
};