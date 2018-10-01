#pragma once

#include <cstdio>
#include <cstdlib>

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
	char arr[MAX_COUNT];

	stack() { top = -1; }
	~stack(){}

	bool isFull() { return top == MAX_COUNT - 1; }
	bool isEmpty() { return top == -1; }

	void push(char c)
	{
		if (isFull())
			error("������ ������ �� á���ϴ�");

		arr[++top] = c;
	}
	char pop()
	{
		if (isEmpty())
			error("������ ������ �����Ͱ� �����ϴ�");

		return arr[top--];
	}
	char peek()
	{
		if (isEmpty())
			error("������ ������ �����Ͱ� �����ϴ�");

		return arr[top];
	}

	void diplay()
	{
		printf("%c", arr[top]);
	}
};