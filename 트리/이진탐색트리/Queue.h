#pragma once

#include "BinaryNode.h"

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

	void enqueue(BinaryNode* node)
	{
		if (isEmpty())
			front = rear = node;
		else
		{
			rear->SetLink(node);
			rear = node;
		}
	}

	BinaryNode* dequeue()
	{
		if (isEmpty())
			return NULL;

		BinaryNode* p = front;

		front = p->GetLink();

		if (front == NULL)
			rear = NULL;

		return p;
	}
};