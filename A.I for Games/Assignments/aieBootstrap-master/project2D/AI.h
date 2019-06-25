#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
#include <vector>
#include "Grid.h"
#include "Node.h"
#include "Input.h"
#include "Texture.h"

enum EAIState {
	EAISTATE_WANDER,
	EAISTATE_CHASE,
	EAISTATE_FLEE
};

class Grid;

class AI {
public:
	AI(Grid* pGrid);
	~AI();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	void Wander(float deltaTime);
	void Chase(float deltaTime);
	void Flee(float deltaTime);

	Vector2 m_v2Position;
	float m_fRotation;

	aie::Texture* m_texture;

	Vector2 m_v2StartPos;
	Vector2 m_v2EndPos;
	std::vector<Vector2> m_Path;

	Grid* m_pGrid;
	bool m_bRecalculate = true;

	EAIState m_eCurrentState;
};

