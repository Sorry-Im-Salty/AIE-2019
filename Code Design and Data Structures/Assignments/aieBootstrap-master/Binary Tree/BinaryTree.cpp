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
	removePrivate(a_nValue, m_pRoot);

}

void BinaryTree::removePrivate(int a_nValue, TreeNode* Parent) {
	if (m_pRoot != nullptr) {
		if (m_pRoot->getData() == a_nValue) {
			remRootMatch();
		}
		else {
			if (a_nValue < Parent->getData() && Parent->getLeft() != nullptr) {
				Parent->getLeft()->getData() == a_nValue ?
				remMatch(Parent, Parent->getLeft(), true) :
				removePrivate(a_nValue, Parent->getLeft());
			}
			else if (a_nValue > Parent->getData() && Parent->getRight() != nullptr) {
				Parent->getRight()->getData() == a_nValue ?
					remMatch(Parent, Parent->getRight(), false) :
					removePrivate(a_nValue, Parent->getRight());
			}
			else {
				return;
			}
		}
	}
	else {
		return;
	}
}

void BinaryTree::remRootMatch() {
	if (m_pRoot != nullptr) {
		TreeNode* delPtr = m_pRoot;
		int rootKey = m_pRoot->getData();
		int smallestRightSubTree;

		// 0 children
		if (m_pRoot->getLeft() == nullptr && m_pRoot->getRight() == nullptr) {
			m_pRoot = nullptr;
			delete delPtr;
		}

		// 1 child
		else if (m_pRoot->getLeft() == nullptr && m_pRoot->getRight() != nullptr) {
			m_pRoot = m_pRoot->getRight();
			delPtr->setRight(nullptr);
			delete delPtr;
		}
		else if (m_pRoot->getLeft() != nullptr && m_pRoot->getRight() == nullptr) {
			m_pRoot = m_pRoot->getLeft();
			delPtr->setLeft(nullptr);
			delete delPtr;
		}

		// 2 Children
		else {
			smallestRightSubTree = findSmallestPrivate(m_pRoot->getRight());
			removePrivate(smallestRightSubTree, m_pRoot);
			m_pRoot->setData(smallestRightSubTree);
		}
	}
	else {
		return;
	}
}

void BinaryTree::remMatch(TreeNode* parent, TreeNode* match, bool left) {
	if (m_pRoot != nullptr) {
		TreeNode* delPtr;
		int matchKey = match->getData();
		int smallestInRightSubtree;

		// 0 children
		if (match->getLeft() == nullptr && match->getRight() == nullptr) {
			delPtr = match;
			left == true ? parent->setLeft(nullptr) : parent->setRight(nullptr);
			delete delPtr;
		}

		// 1 child
		else if (match->getLeft() == nullptr && match->getRight() != nullptr) {
			left == true ? parent->setLeft(match->getRight()) : parent->setRight(match->getRight());
			match->setRight(nullptr);
			delPtr = match;
			delete delPtr;
		}
		else if (match->getLeft() != nullptr && match->getRight() == nullptr) {
			left == true ? parent->setLeft(match->getLeft()) : parent->setRight(match->getLeft());
			match->setLeft(nullptr);
			delPtr = match;
			delete delPtr;
		}

		// 2 children
		else {
			smallestInRightSubtree = findSmallestPrivate(match->getRight());
			removePrivate(smallestInRightSubtree, match);
			match->setData(smallestInRightSubtree);
		}
	}
	else {
		return;
	}
}

int BinaryTree::findSmallestPrivate(TreeNode* Ptr) {
	if (m_pRoot == nullptr) {
		return -1000;
	}
	else {
		if (Ptr->getLeft() != nullptr) {
			return findSmallestPrivate(Ptr->getLeft());
		}
		else {
			return Ptr->getData();
		}
	}
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