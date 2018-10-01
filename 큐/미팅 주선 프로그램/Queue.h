#pragma once
#include "Students.h"
#include <iostream>

using namespace std;

#define MAX_STUDENT 100

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
	Students data[MAX_STUDENT];

public:
	Queue() { front = rear = 0; }
	~Queue(){}

	bool isEmpty() { return front == rear; }
	bool isFull() { return front == (rear + 1) % MAX_STUDENT; }

	void q_push(Students d)
	{
		if (isFull())
			error("ť�� ������ �� á���ϴ�");

		rear = (rear + 1) % MAX_STUDENT;

		data[rear] = d;
	}

	Students q_pop()
	{
		if (isEmpty())
			error("ť�� ������ �����Ͱ� �����ϴ�");

		front = (front + 1) % MAX_STUDENT;

		return data[front];
	}

	Students q_peek()
	{
		if (isEmpty())
			error("ť�� ������ �����Ͱ� �����ϴ�");

		return data[(front + 1) % MAX_STUDENT];
	}
};