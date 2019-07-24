#pragma once
#include "TreeNode.h"

class BinaryTree {
	struct Node;
public:
	BinaryTree();
	~BinaryTree();

	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);
	TreeNode* find(int a_nValue);
	void draw(aie::Renderer2D* renderer, TreeNode* selected = nullptr);

private:
	bool findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);
	void draw(aie::Renderer2D* renderer, TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);
	void removePrivate(int a_nValue, TreeNode* Parent);
	void remRootMatch();
	void remMatch(TreeNode* parentm, TreeNode* match, bool left);
	int findSmallestPrivate(TreeNode* Ptr);

	TreeNode* m_pRoot;
};

