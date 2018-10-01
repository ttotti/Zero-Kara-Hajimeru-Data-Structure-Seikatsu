#pragma once

// 이진트리 클래스
// 기본적인 구조에 사용되지 않는 연산들을 모두 제거하였다
// 루트 노드의 포인터인 root는 protected로 선언하여 자식 클래스에서 접근할 수 있도록 하였다
#include "BinaryNode.h"

class BinaryTree
{
protected:
	BinaryNode* root;

public:
	BinaryTree()
		:root(NULL){}
	bool isEmpty() { return root == NULL; }

	void inorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->getLeft() != NULL)
				inorder(node->getLeft());

			node->display();

			if (node->getRight() != NULL)
				inorder(node->getRight());
		}
	}
};