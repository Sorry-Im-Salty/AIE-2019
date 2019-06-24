#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
#include <vector>
#include "Grid.h"
#include "Node.h"
#include "Input.h"
#include "Texture.h"

class AI {
public:
	AI(Grid* pGrid);
	~AI();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	Vector2 m_v2Position;
	aie::Texture* m_texture;

	Vector2 m_v2StartPos;
	Vector2 m_v2EndPos;
	std::vector<Vector2> m_Path;

	Grid* m_pGrid;
	bool m_bRecalculate = true;
};

