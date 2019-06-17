#include "Grid.h"
#include "Node.h"

#define SQUARE_SIZE 50.0f
#define GRID_POSX 200
#define GRID_POSY 200

Grid::Grid(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	// Allocate 2D array of pointers that will be used to store nodes.
	m_pNodeList = new Node**[m_nWidth];
	for (int i = 0; i < m_nWidth; ++i) {
		m_pNodeList[i] = new Node*[m_nHeight];
	}

	// Alocate nodes
	for (int x = 0; x < m_nWidth; ++x) {
		for (int y = 0; y < m_nHeight; ++y) {
			Vector2 pos;
			pos.x = x * SQUARE_SIZE - 200;
			pos.y = y * SQUARE_SIZE - 200;

			m_pNodeList[x][y] = new Node(pos, x, y);
		}
	}

	// Connect the nodes to their neighbours
	// | |2| |
	// |1|C|3|
	// | |0| |
	for (int x = 0; x < m_nWidth; ++x) {
		for (int y = 0; y < m_nHeight; ++y) {
			if (y > 0) 
				m_pNodeList[x][y]->m_apNeighbours[0] = m_pNodeList[x][y - 1];

			if (x > 0)
				m_pNodeList[x][y]->m_apNeighbours[1] = m_pNodeList[x - 1][y];
			
			if (y < m_nHeight - 1)
				m_pNodeList[x][y]->m_apNeighbours[2] = m_pNodeList[x][y + 1];

			if (x > m_nWidth - 1)
				m_pNodeList[x][y]->m_apNeighbours[3] = m_pNodeList[x + 1][y];

			m_pNodeList[x][y]->m_anCosts[0] = 10;
			m_pNodeList[x][y]->m_anCosts[1] = 10;
			m_pNodeList[x][y]->m_anCosts[2] = 10;
			m_pNodeList[x][y]->m_anCosts[3] = 10;
		}
	}

}


Grid::~Grid()
{
	for (int x = 0; x < m_nWidth; ++x) {
		for (int y = 0; y < m_nHeight; ++y) {
			delete m_pNodeList[x][y];
			m_pNodeList[x][y] = nullptr;
		}
	}

	for (int i = 0; i < m_nWidth; ++i) {
		delete[] m_pNodeList[i];
		m_pNodeList[i] = nullptr;
	}
}

void Grid::Draw(aie::Renderer2D* pRenderer) {
	for (int x = 0; x < m_nWidth; ++x) {
		for (int y = 0; y < m_nHeight; ++y) {
			Vector2 v2Pos = m_pNodeList[x][y]->m_v2Position;

			// Normal node colour
			pRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

			// Blocked node colour
			if (m_pNodeList[x][y]->m_bBlocked)
				pRenderer->setRenderColour(0.0f, 0.0f, 1.0f, 1.0f);

			pRenderer->drawBox(v2Pos.x, v2Pos.y, SQUARE_SIZE - 5.0f, SQUARE_SIZE - 5.0f);

			for (int n = 0; n < NEIGHBOUR_COUNT; ++n) {
				if (m_pNodeList[x][y]->m_apNeighbours[n]) {
					Vector2 v2NeighbourPos = m_pNodeList[x][y]->m_apNeighbours[n]->m_v2Position;
					pRenderer->setRenderColour(1.0f, 0.0f, 0.0f);
					pRenderer->drawLine(v2Pos.x, v2Pos.y, v2NeighbourPos.x, v2NeighbourPos.y);
				}
			}
		}
	}
}

Node* Grid::GetNodeByPos(Vector2 v2Pos) {
	int x = (int(v2Pos.x - GRID_POSX + (SQUARE_SIZE * 0.5f)) / SQUARE_SIZE);
	int y = (int(v2Pos.y - GRID_POSY + (SQUARE_SIZE * 0.5f)) / SQUARE_SIZE);

	if (x < 0 || y < 0 || x >= m_nWidth || y >= m_nHeight)
		return nullptr;

	return m_pNodeList[x][y];
}