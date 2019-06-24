#include "Grid.h"
#include "Node.h"
#include <cmath>

#define SQUARE_SIZE 50.0f
#define GRID_POSX 45
#define GRID_POSY 35

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
			pos.x = x * SQUARE_SIZE + GRID_POSX;
			pos.y = y * SQUARE_SIZE + GRID_POSY;

			m_pNodeList[x][y] = new Node(pos, x, y);
		}
	}

	// Connect the nodes to their neighbours
	// |7|2|6|
	// |1|C|3|
	// |4|0|5|
	for (int x = 0; x < m_nWidth; ++x) {
		for (int y = 0; y < m_nHeight; ++y) {
			if (y > 0) 
				m_pNodeList[x][y]->m_apNeighbours[0] = m_pNodeList[x][y - 1];

			if (x > 0)
				m_pNodeList[x][y]->m_apNeighbours[1] = m_pNodeList[x - 1][y];
			
			if (y < m_nHeight - 1)
				m_pNodeList[x][y]->m_apNeighbours[2] = m_pNodeList[x][y + 1];

			if (x < m_nWidth - 1)
				m_pNodeList[x][y]->m_apNeighbours[3] = m_pNodeList[x + 1][y];

			if (y > 0 && x > 0)
				m_pNodeList[x][y]->m_apNeighbours[4] = m_pNodeList[x - 1][y - 1];

			if (y > 0 && x < m_nWidth - 1)
				m_pNodeList[x][y]->m_apNeighbours[5] = m_pNodeList[x + 1][y - 1];

			if (y < m_nHeight - 1 && x < m_nWidth - 1)
				m_pNodeList[x][y]->m_apNeighbours[6] = m_pNodeList[x + 1][y + 1];

			if (y < m_nHeight - 1 && x > 0)
				m_pNodeList[x][y]->m_apNeighbours[7] = m_pNodeList[x - 1][y + 1];

			m_pNodeList[x][y]->m_anCosts[0] = 10;
			m_pNodeList[x][y]->m_anCosts[1] = 10;
			m_pNodeList[x][y]->m_anCosts[2] = 10;
			m_pNodeList[x][y]->m_anCosts[3] = 10;
			m_pNodeList[x][y]->m_anCosts[4] = 14;
			m_pNodeList[x][y]->m_anCosts[5] = 14;
			m_pNodeList[x][y]->m_anCosts[6] = 14;
			m_pNodeList[x][y]->m_anCosts[7] = 14;
		}
	}

	// Create the closed list
	m_bClosedList = new bool[m_nWidth * m_nHeight];
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

			/*for (int n = 0; n < NEIGHBOUR_COUNT; ++n) {
				if (m_pNodeList[x][y]->m_apNeighbours[n]) {
					Vector2 v2NeighbourPos = m_pNodeList[x][y]->m_apNeighbours[n]->m_v2Position;
					pRenderer->setRenderColour(1.0f, 0.0f, 0.0f);
					pRenderer->drawLine(v2Pos.x, v2Pos.y, v2NeighbourPos.x, v2NeighbourPos.y);
				}
			}*/
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

//void Grid::SortOpenList() {
//	for (int i = 0; i < m_OpenList.size() - 1; ++i) {
//		for (int j = 0; j < m_OpenList.size() - 1 - i; ++j) {
//			if (m_OpenList[j]->m_nGScore < m_OpenList[j + 1]->m_nGScore) {
//				Node* pSwap = m_OpenList[j];
//				m_OpenList[j] = m_OpenList[j + 1];
//				m_OpenList[j + 1] = pSwap;
//			}
//		}
//	}
//}

bool Grid::FindPath(Vector2 v2Start, Vector2 v2End, std::vector<Vector2>& path) {
	// Find start and end nodes
	path.clear();
	Node* pStartNode = GetNodeByPos(v2Start);
	Node* pEndNode = GetNodeByPos(v2End);

	if (!pStartNode || !pEndNode)
		return false;

	if (pStartNode == pEndNode)
		return false;

	if (pStartNode->m_bBlocked || pEndNode->m_bBlocked)
		return false;

	// Initialisation
	m_OpenList.Clear();
	memset(m_bClosedList, 0, sizeof(bool) * m_nWidth * m_nHeight);
	bool bFoundPath = false;

	pStartNode->m_pPrev = nullptr;
	pStartNode->m_nGScore = 0;
	pStartNode->m_nHScore = CalculateHeuristic(pStartNode, pEndNode);
	pStartNode->m_nFScore = pStartNode->m_nGScore + pStartNode->m_nHScore;

	m_OpenList.Push(pStartNode);

	// Algorithm
	while (m_OpenList.GetCount() > 0) {
		// Sort the open list
		//SortOpenList();
		
		// Get lowest cost node off the open list
		Node* pCurrent = m_OpenList.Pop();

		// Add to closed list
		int nIndex = pCurrent->m_nIndexY * m_nWidth + pCurrent->m_nIndexX;
		m_bClosedList[nIndex] = true;

		// Check for completed path
		if (pCurrent == pEndNode) {
			bFoundPath = true;
			break;
		}

		for (int i = 0; i < NEIGHBOUR_COUNT; ++i) {
			Node* pNeighbour = pCurrent->m_apNeighbours[i];

			if (!pNeighbour)
				continue;

			if (pNeighbour->m_bBlocked)
				continue;

			int nNeighbourIndex = pNeighbour->m_nIndexY * m_nWidth + pNeighbour->m_nIndexX;
			if (m_bClosedList[nNeighbourIndex])
				continue;

			if (!m_OpenList.Find(pNeighbour)) {
				// Not in open list
				pNeighbour->m_pPrev = pCurrent;
				pNeighbour->m_nGScore = pCurrent->m_nGScore + pCurrent->m_anCosts[i];
				pNeighbour->m_nHScore = CalculateHeuristic(pNeighbour, pEndNode);
				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;
				m_OpenList.Push(pNeighbour);
			}
			else {
				// Is in open list, check if better path
				int nCost = pCurrent->m_nFScore + pCurrent->m_anCosts[i];
				if (nCost < pNeighbour->m_nFScore) {
					pNeighbour->m_nGScore = pCurrent->m_nGScore + pCurrent->m_anCosts[i];
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;
					pNeighbour->m_pPrev = pCurrent;
				}
			}
		}
	}

	if (bFoundPath) {
		Node* pCurrent = pEndNode;
		while (pCurrent) {
			path.insert(path.begin(), pCurrent->m_v2Position);
			pCurrent = pCurrent->m_pPrev;
		}
		return true;
	}
	return false;
}

int Grid::CalculateHeuristic(Node* pNode, Node* pEnd) {
	int distX = abs(pNode->m_nIndexX - pEnd->m_nIndexX);
	int distY = abs(pNode->m_nIndexY - pEnd->m_nIndexY);

	if (distX > distY)
		return (14 * distY) + 10 * (distX - distY);
	else
		return (14 * distX) + 10 * (distY - distX);
}