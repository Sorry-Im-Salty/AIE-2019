#pragma once
#include "Renderer2D.h"
#include "Vector2.h"

struct Node;

class Grid
{
public:
	Grid(int nWidth, int nHeight);
	~Grid();

	void Draw(aie::Renderer2D* pRenderer);

	Node* GetNodeByPos(Vector2 v2Pos);

private:
	Node*** m_pNodeList;


	int m_nWidth;
	int m_nHeight;
};

