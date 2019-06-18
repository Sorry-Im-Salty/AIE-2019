#pragma once
#include <vector>
struct Node;

class PathHeap {
public:
	PathHeap();
	~PathHeap();

	void Push(Node* pNode);
	Node* Pop();
	int GetCount();

private:
	int GetParent(int nIndex);
	int GetChild(int nIndex, int child);

	std::vector<Node*> m_Heap;

};