#include "PathHeap.h"
#include "Node.h"
PathHeap::PathHeap() {

}

PathHeap::~PathHeap() {

}

void PathHeap::Push(Node* pNode) {
	m_Heap.push_back(pNode);
	int nCurrent = m_Heap.size() - 1;
	int nParent = GetParent(nCurrent);

	while (m_Heap[nCurrent]->m_nGScore < m_Heap[nParent]->m_nGScore) {
		Node* pSwap = m_Heap[nCurrent];
		m_Heap[nCurrent] = m_Heap[nParent];
		m_Heap[nParent] = pSwap;

		nCurrent = nParent;
		nParent = GetParent(nCurrent);
	}
}

Node* PathHeap::Pop() {
	Node* pNode = m_Heap[0];

	int nLast = m_Heap.size() - 1;

	int nCurrent = 0;
	m_Heap[nCurrent] = m_Heap[nLast];

	int nChild1Index = GetChild(0, 1);
	int nChild2Index = GetChild(0, 2);

	int nCheapestIndex = nChild1Index;
	if (m_Heap[nChild2Index]->m_nGScore < m_Heap[nCheapestIndex]->m_nGScore)
		nCheapestIndex = nChild2Index;

	while (m_Heap[nCheapestIndex]->m_nGScore < m_Heap[nCurrent]->m_nGScore) {
		Node* pSwap = m_Heap[nCheapestIndex];
		m_Heap[nCheapestIndex] = m_Heap[nCurrent];
		m_Heap[nCurrent] = pSwap;

		nCurrent = nCheapestIndex;
		nChild1Index = GetChild(nCurrent, 1);
		nChild2Index = GetChild(nCurrent, 2);

		nCheapestIndex = nChild1Index;
		if (m_Heap[nChild2Index]->m_nGScore < m_Heap[nCheapestIndex]->m_nGScore)
			nCheapestIndex = nChild2Index;
	}
	return pNode;
}

int PathHeap::GetParent(int nIndex) {
	return (nIndex - 1) / 2;
}

int PathHeap::GetChild(int nIndex, int nChild) {
	return (2 * nIndex) + nChild;
}

int PathHeap::GetCount() {
	return m_Heap.size();
}