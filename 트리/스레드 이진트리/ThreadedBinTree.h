#pragma once

#include "ThreadedBinNode.h"
#include <cstdio>

class ThreadedBinTree
{
	ThreadedBinNode* root;

public:
	ThreadedBinTree()
		:root(NULL){}

	void setRoot(ThreadedBinNode* node) { root = node; }
	ThreadedBinNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }

	void threadedInorder()
	{
		if (!isEmpty())
		{
			printf("스레드 이진트리: ");

			ThreadedBinNode* q = root;

			while (q->getLeft())
				q = q->getLeft();

			do
			{
				printf("%c ", q->getData());
				q = findSuccessor(q);
			} while (q);

			printf("\n");
		}
	}

	ThreadedBinNode* findSuccessor(ThreadedBinNode* p)
	{
		ThreadedBinNode* q = p->getRight();

		if (q == NULL || p->bThread)
			return q;

		while (q->getLeft() != NULL)
			q = q->getLeft();

		return q;
	}
};