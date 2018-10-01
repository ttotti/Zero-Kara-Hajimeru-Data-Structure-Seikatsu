#pragma once

#include <cstdio>
#include <cstdlib>
#include "Location.h"

#define MAX_COUNT 20

void error(char* message)
{
	printf("%s", message);
	exit(1);
}

class stack
{
public:
	int top;
	Location map[MAX_COUNT];

	stack() { top = -1; }
	
	bool isFull() { return top == MAX_COUNT - 1; }
	bool isEmpty() { return top == -1; }

	void push(Location& e)
	{
		if (isFull())
			error("������ ������ �� á���ϴ�");

		map[++top] = e;
	}

	Location pop()
	{
		if (isEmpty())
			error("������ ������ �����Ͱ� �����ϴ�");

		return map[top--];
	}

	Location peek()
	{
		if (isEmpty())
			error("������ ������ �����Ͱ� �����ϴ�");

		return map[top];
	}
};