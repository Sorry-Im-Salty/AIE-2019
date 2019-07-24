#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "BinaryTree.h"
#include "TreeNode.h"

class Binary_TreeApp : public aie::Application {
public:

	Binary_TreeApp();
	virtual ~Binary_TreeApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	BinaryTree			m_binaryTree;
	TreeNode*			m_selectedNode;
};