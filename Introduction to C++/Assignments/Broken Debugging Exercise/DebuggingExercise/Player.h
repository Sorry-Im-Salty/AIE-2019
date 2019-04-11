#pragma once
class Card;

#define MAX_HAND_SIZE 16

class Player
{
public:
	Player();
	~Player();

	void Reset();
	void AddToHand(Card* pCard);
	int GetScore();
	int GetCardCount();
	void DisplayHand();

private:
	Card* m_apHand[MAX_HAND_SIZE];
	int m_nCardCount;
};

