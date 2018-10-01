#pragma once

#include "Customer.h"
#include <cstdio>
#include <cstdlib>

#define MAX_Queue 100

void error(char* message)
{
	printf("%s", message);
	exit(0);
}

class CustomerQueue
{
public:
	int front;
	int rear;
	Customer data[MAX_Queue];

	CustomerQueue() { front = rear = 0; }

	bool isEmpty() { return front == rear; }
	bool isFull() { return front == (rear + 1) % MAX_Queue; }

	void enqueue(Customer C_data)
	{
		if (isFull())
			error("ť�� ������ �� á���ϴ�");
		else
		{
			rear = (rear + 1) % MAX_Queue;

			data[rear] = C_data;
		}
	}

	Customer dequeue()
	{
		if (isEmpty())
			error("ť�� ������ �����Ͱ� �����ϴ�");
		else
		{
			front = (front + 1) % MAX_Queue;

			return data[front];
		}
	}

	Customer peek()
	{
		if (isEmpty())
			error("ť�� ������ �����Ͱ� �����ϴ�");
		else
		{
			return data[(front + 1) % MAX_Queue];
		}
	}
};