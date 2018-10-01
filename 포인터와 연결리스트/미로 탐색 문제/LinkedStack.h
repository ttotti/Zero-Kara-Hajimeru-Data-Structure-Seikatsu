#pragma once

#include "Node.h"

class LinkedStack
{
private:
	// 헤드 포인터
	Node* top;

public:
	LinkedStack() { top = NULL; }
	~LinkedStack()
	{
		while (!isEmpty())
		{
			delete pop();
		}
	}

	bool isEmpty() { return top == NULL; }

	void push(Node* data)
	{
		if (isEmpty())
			top = data;
		else
		{
			data->setLink(top);
			top = data;
		}
	}

	Node* pop()
	{
		if (isEmpty())
			return NULL;

		Node* p = top;
		top = top->getLink();

		return p;
	}

	Node* peek()
	{
		return top;
	}

	void display()
	{
		printf("[LinkedStack]\n");

		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();

		printf("\n");
	}
};