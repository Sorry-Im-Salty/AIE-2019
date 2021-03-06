#pragma once
#include "Vector2.h"

#define NEIGHBOUR_COUNT 8

struct Node
{
	Node(Vector2 v2Pos, int nIndexX, int nIndexY);
	~Node();

	Vector2 m_v2Position;
	int m_nIndexX;
	int m_nIndexY;

	Node* m_pPrev;

	int m_nGScore;
	int m_nFScore;
	int m_nHScore;

	Node* m_apNeighbours[NEIGHBOUR_COUNT];
	int m_anCosts[NEIGHBOUR_COUNT];

	bool m_bBlocked;
};

