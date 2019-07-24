#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree() {
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected) {
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected) {
	horizontalSpacing /= 2;

	if (pNode) {
		if (pNode->hasLeft()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}

		if (pNode->hasRight()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}

		pNode->draw(renderer, x, y, (selected == pNode));
	}
}

bool BinaryTree::isEmpty() const {
	if (m_pRoot == nullptr)
		return true;
	else
		return false;
}

void BinaryTree::insert(int a_nValue) {
	TreeNode* newNode = new TreeNode(a_nValue);

	if (isEmpty() == true) {
		m_pRoot = newNode;
		return;
	}

	TreeNode* currNode = m_pRoot;
	TreeNode* parentNode = nullptr;

	while (currNode != nullptr) {
		if (newNode->getData() < currNode->getData()) {
			if (currNode->getLeft() == nullptr) {
				currNode->setLeft(newNode);
				break;
			}
			else {
				parentNode = currNode;
				currNode = currNode->getLeft();
			}
		}
		if (newNode->getData() > currNode->getData()) {
			if (currNode->getRight() == nullptr) {
				currNode->setRight(newNode);
				break;
			}
			else {
				parentNode = currNode;
				currNode = currNode->getRight();
			}
		}
		if (newNode->getData() == currNode->getData()) {
			break;
		}
	}
}

void BinaryTree::remove(int a_nValue) {
	TreeNode* currNode = m_pRoot;
	TreeNode* miniNode = nullptr;
	TreeNode* parentNode = nullptr;

	while (miniNode = nullptr) {
		if (currNode->hasRight()) {
			currNode = currNode->getRight();
		}
		while (currNode->hasLeft()) {
			currNode = currNode->getLeft();
		}
		if (currNode->hasLeft() == false) {
			miniNode = currNode;
			currNode = m_pRoot;
		}
	}

	while (parentNode = nullptr) {
		if (currNode->hasRight()) {
			currNode = currNode->getRight();
		}
		while (currNode->hasLeft() && currNode->getLeft() != miniNode) {
			currNode = currNode->getLeft();

		}
		parentNode = currNode;
	}

	return;
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent) {
	TreeNode* searchNode = new TreeNode(a_nSearchValue);
	TreeNode* currNode = m_pRoot;
	TreeNode* parentNode = nullptr;
	while (currNode != nullptr) {
		if (searchNode->getData() == currNode->getData()) {
			*ppOutNode = currNode;
			*ppOutParent = parentNode;
			return true;
		}
		else
			if (searchNode->getData() < currNode->getData()) {
				parentNode = currNode;
				currNode = currNode->getLeft();
			}
			else {
				parentNode = currNode;
				currNode = currNode->getRight();
			}
	}
	*ppOutNode = nullptr;
	*ppOutParent = nullptr;
	return false;
}

TreeNode* BinaryTree::find(int a_nValue) {
	TreeNode* ppOutNode = nullptr;
	TreeNode* ppOutParent = nullptr;
	TreeNode* currNode = m_pRoot;


	findNode(a_nValue, &ppOutNode, &ppOutParent);
	return currNode;
}