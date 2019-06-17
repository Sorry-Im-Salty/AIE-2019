#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
#include <vector>
#include <algorithm>

struct Node;

class Grid
{
public:
	Grid(int nWidth, int nHeight);
	~Grid();

	void Draw(aie::Renderer2D* pRenderer);

	Node* GetNodeByPos(Vector2 v2Pos);
	bool FindPath(Vector2 v2Start, Vector2 v2End, std::vector<Vector2>& path);
	void SortOpenList();

private:
	Node*** m_pNodeList;

	std::vector<Node*> m_OpenList;
	bool* m_bClosedList;

	int m_nWidth;
	int m_nHeight;
};

