#pragma once

// Base implementation for any two-player game with win / draw / loss conditions
// Specific games derive off of it and implement how player turns are run and 
// how the state of play is worked out

enum EPlayer 
{
	PLAYER_ONE,
	PLAYER_TWO,

	PLAYER_COUNT
};

enum EStateOfPlay 
{
	IN_PROGRESS,
	PLAYER_ONE_WIN,
	PLAYER_TWO_WIN,
	DRAW
};

class TwoPlayerGame 
{
public:
	TwoPlayerGame();
	virtual ~TwoPlayerGame();

	EStateOfPlay GetStateOfPlay();

	// Resets state of play and sets current player to player one.
	// Derived classes should overload this and call it once they
	// have implemented their own reset code.
	virtual void Reset();

	// updates the state of play based on game rules
	virtual void UpdateStateOfPlay() = 0;

	// runs current player's turn and then switches player
	void DoTurn();

protected:
	// simply switches who the current player is
	void SwitchPlayer();

	// derived games override this to implement how the game runs
	virtual void RunTurn(EPlayer player) = 0;

	// tracks current player and state of play
	EPlayer m_eCurrentPlayer;
	EStateOfPlay m_eStateOfPlay;
};
