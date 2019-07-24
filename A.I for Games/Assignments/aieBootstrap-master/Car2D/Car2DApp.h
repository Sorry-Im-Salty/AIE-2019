#include "Application.h"
#include "Renderer2D.h"
#include "Grid.h"
#include "AI.h"
#include "Vector2.h"
#include "Game.h"
#include <vector>

class Car2DApp : public aie::Application {
public:

	Car2DApp();
	virtual ~Car2DApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D* m_2dRenderer;
	aie::Texture* m_texture;
	aie::Texture* m_shipTexture;
	aie::Font* m_font;
	Grid* m_pGrid;
	AI* m_pAI;
	AI* m_pAI2;
	Game* m_pGame;

	float m_timer;
};