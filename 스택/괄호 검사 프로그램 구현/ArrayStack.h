#pragma once

#include <cstdio>
#include <cstdlib>

void error(char* message)
{
	printf("%s", message);
	exit(1);
}

#define MAX_STACK 20

class ArrayStack
{
private:
	int top; // 요소 개수
	int date[MAX_STACK]; // 요소 배열

public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK - 1; }

	void push(int e)
	{
		if (isFull())
			error("공간이 꽉 찼습니다!");

		date[++top] = e;
	}

	int pop()
	{
		if (isEmpty())
			error("공간이 비어있습니다");

		return date[top--];
	}

	int peek()
	{
		if (isEmpty())
			error("공간이 이미 비어있습니다");

		return date[top];
	}

	void display()
	{
		printf("[스택 저장 수 = %d]", top + 1);
		for (int i = 0; i <= top; i++)
		{
			printf(" <%d>", date[i]);
		}
		printf("\n");
	}
};