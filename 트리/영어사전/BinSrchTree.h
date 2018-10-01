#pragma once

// 이진 탐색 트리 클래스는 기본적인 틀과 유사하지만 노드에 저장되는 자료형이 달라졌으므로 변경이 필요하다
// 특히 키 값을 이용한 탐색 연산인 search()와 삭제 연산 remove()에서 int 가 char* 로 변경된 것에 유의하라
#include "BinaryTree.h"

class BinSrehTree :public BinaryTree
{
public:
	BinaryNode* search(char* key) { return searchRecur(root, key); }
	BinaryNode* searchRecur(BinaryNode* n, char* key)
	{
		if (n == NULL)
			return NULL;
		
		if (n->compare(key) == 0)
			return n;
		else if (n->compare(key) < 0)
			return searchRecur(n->getLeft(), key);
		else
			return searchRecur(n->getRight(), key);
	}

	void insert(BinaryNode* n)
	{
		if (n == NULL)
			return;
		if (isEmpty())
			root = n;
		else
			insertRecur(root, n);
	}
	void insertRecur(BinaryNode* r, BinaryNode* n)
	{
		if (n->compare(r) == 0)
			return;
		else if (n->compare(r) > 0)
		{
			if (r->getLeft() == NULL)
				r->setLeft(n);
			else insertRecur(r->getLeft(), n);
		}
		else
		{
			if (r->getRight() == NULL)
				r->setRight(n);
			else
				insertRecur(r->getRight(), n);
		}
	}
	
	void remove(char* data)
	{
		if (isEmpty())
			return;
		BinaryNode* parent = NULL;
		BinaryNode* node = root;

		while (node != NULL && node->compare(data) != 0)
		{
			parent = node;
			node = (node->compare(data) < 0) ? node->getLeft() : node->getRight();
		}

		if (node != NULL)
			remove(parent, node);
	}
	void remove(BinaryNode* parent, BinaryNode* node)
	{
		if (node->isLeaf())
		{
			if (parent == NULL)
				root = NULL;
			else
			{
				if (parent->getLeft() == NULL)
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}
		else if (node->getLeft() == NULL || node->getRight() == NULL)
		{
			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

			if (node == root)
				root = child;
			else
			{
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);

			}
		}
		else
		{
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();

			while (succ->getLeft() != NULL)
			{
				succp = succ;
				succ = succ->getLeft();
			}

			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node = succ;
		}

		delete node;
	}
};