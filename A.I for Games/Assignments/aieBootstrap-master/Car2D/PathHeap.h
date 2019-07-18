#pragma once
#include <vector>
#include <algorithm>

struct Node;

class PathHeap {
public:
	PathHeap();
	~PathHeap();

	void Push(Node* pNode);
	Node* Pop();
	int GetCount();
	void Clear();

	bool Find(Node* pNode);

private:
	int GetParent(int nIndex);
	int GetChild(int nIndex, int child);

	std::vector<Node*> m_Heap;

};