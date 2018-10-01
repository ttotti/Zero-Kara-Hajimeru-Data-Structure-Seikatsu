#pragma once

#include "Node.h"

class LinkedList
{
private:
	Node org;

public:
	LinkedList()
		:org(0) {}
	~LinkedList() { clear(); }

	Node* getHead() { return org.getLink(); }

	void clear() { while (!isEmpty()) { delete deleteNode(0); } }

	bool isEmpty() { return org.getLink() == NULL; }

	Node* getEntry(int pos)
	{
		Node* prev = &org;

		for (int i = -1; i < pos; i++, prev = prev->getLink())
		{
			if (prev == NULL)
				break;
		}

		return prev;
	}

	void insertNode(int pos, Node* data)
	{
		Node* n = getEntry(pos - 1);

		if (n != NULL)
			n->insertnext(data);
	}

	Node* deleteNode(int pos)
	{
		Node* n = getEntry(pos - 1);

		return n->deletenext();
	}

	int size()
	{
		int count = 0;

		for (Node* n = getHead(); n != NULL; n = n->getLink())
		{
			if (n == NULL)
				break;

			count++;
		}

		return count;
	}

	void replace(int pos, Node* data)
	{
		Node* n = getEntry(pos - 1);

		if (n != NULL)
		{
			delete n->getLink();

			n->insertnext(data);
		}
	}

	void display()
	{
		int add = 0;

		for (Node* n = getHead(); n != NULL; n = n->getLink())
		{
			if (n != NULL)
			{
				n->display();
				add = add + n->getdate();
			}
		}

		printf("\n√— «’∞Ë : %d\n", add);
	}
};