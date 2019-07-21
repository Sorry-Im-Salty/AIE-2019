#pragma once
#include "Renderer2D.h"
#include "Font.h"

enum EGameState {
	EGAMESTATE_MENU,
	EGAMESTATE_CONTROLS,
	EGAMESTATE_GAME
};



class Game {
public:
	Game(aie::Renderer2D* renderer, float xPos, float yPos, float Width, float Height);
	~Game();

	void Update();
	
private:
	void Menu(aie::Renderer2D* renderer);
	void Controls(aie::Renderer2D* renderer);
	void GamePlay(aie::Renderer2D* renderer);


	aie::Font* m_fontBold;
	aie::Renderer2D* m_2dRenderer;
	EGameState m_eCurrentState;

	float m_fPosX;
	float m_fPosY;
	float m_fWidth;
	float m_fHeight;
};

