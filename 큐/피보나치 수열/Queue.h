#pragma once

#include "F_value.h"
#include <iostream>

using namespace std;

#define MAX_VALSE 20

void error(const char* message)
{
	printf("%s", message);
	exit(0);
}

class Queue
{
public:
	int front;
	int rear;
	F_value F[MAX_VALSE];

public:
	Queue() { front = rear = 0; }
	~Queue(){}

	bool isEmpty() { return front == rear; }
	bool isFull() { return front == (rear + 1) % MAX_VALSE; }

	void push(F_value data)
	{
		if (isFull())
			error("ť�� ������ �� á���ϴ�");

		rear = (rear + 1) % MAX_VALSE;
		F[rear] = data;
	}

	F_value pop()
	{
		if (isEmpty())
			error("ť�� ������ �����Ͱ� �����ϴ�");

		front = (front + 1) % MAX_VALSE;

		return F[front];
	}

	F_value peek()
	{
		if (isEmpty())
			error("ť�� ������ �����Ͱ� �����ϴ�");

		return F[(front + 1) % MAX_VALSE];
	}
};