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
			error("큐의 공간이 꽉 찼습니다");
		else
		{
			rear = (rear + 1) % MAX_Queue;

			data[rear] = C_data;
		}
	}

	Customer dequeue()
	{
		if (isEmpty())
			error("큐의 공간에 데이터가 없습니다");
		else
		{
			front = (front + 1) % MAX_Queue;

			return data[front];
		}
	}

	Customer peek()
	{
		if (isEmpty())
			error("큐의 공간에 데이터가 없습니다");
		else
		{
			return data[(front + 1) % MAX_Queue];
		}
	}
};