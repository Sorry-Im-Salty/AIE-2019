#pragma once


enum EGameState {
	EGAMESTATE_MENU,
	EGAMESTATE_CONTROLS,
	EGAMESTATE_GAME
};



class Game {
public:
	Game();
	~Game();





private:




	EGameState m_eCurrentState;
};

