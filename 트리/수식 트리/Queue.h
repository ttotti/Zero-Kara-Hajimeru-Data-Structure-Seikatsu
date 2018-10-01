#pragma once

#include "BinaryNode.h"
#include <cstdio>

class Queue
{
	BinaryNode* front;
	BinaryNode* rear;

public:
	Queue()
		:front(NULL), rear(NULL)
	{

	}
	~Queue()
	{
		while (!isEmpty())
		{
			delete dequeue();
		}
	}

	bool isEmpty() { return front == NULL; }

	void enqueue(BinaryNode* data)
	{
		if (isEmpty())
			front = rear = data;
		else
		{
			rear->setlink(data);
			rear = data;
		}
	}

	BinaryNode* dequeue()
	{
		if (isEmpty())
			return NULL;

		BinaryNode* p = front;

		front = p->getlink();

		if (front == NULL)
			rear = NULL;

		return p;
	}
};