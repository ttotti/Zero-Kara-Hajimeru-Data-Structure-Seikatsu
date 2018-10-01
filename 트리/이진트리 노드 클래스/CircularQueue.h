#pragma once

#include "BinaryNode.h"
#include <stdlib.h>

inline void error(const char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}

class CircularQueue
{
	BinaryNode* front;
	BinaryNode* rear;

public:
	CircularQueue()
		:rear(NULL), front(NULL){}

	~CircularQueue()
	{
		delete dequeue();
	}

	bool isEmpty() { return front == NULL; }

	void enqueue(BinaryNode* d)
	{
		if (isEmpty())
			rear = front = d;
		else
		{
			rear->setlink(d);
			rear = d;
		}
	}

	BinaryNode* dequeue()
	{
		if (isEmpty())
		{
			//error("데이터가 없습니다");
			return NULL;
		}

		BinaryNode* p = front;
		front = p->getlink();

		if (front == NULL)
			rear = NULL;

		return p;
	}
};