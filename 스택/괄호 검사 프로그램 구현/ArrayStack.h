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
	int top; // ��� ����
	int date[MAX_STACK]; // ��� �迭

public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK - 1; }

	void push(int e)
	{
		if (isFull())
			error("������ �� á���ϴ�!");

		date[++top] = e;
	}

	int pop()
	{
		if (isEmpty())
			error("������ ����ֽ��ϴ�");

		return date[top--];
	}

	int peek()
	{
		if (isEmpty())
			error("������ �̹� ����ֽ��ϴ�");

		return date[top];
	}

	void display()
	{
		printf("[���� ���� �� = %d]", top + 1);
		for (int i = 0; i <= top; i++)
		{
			printf(" <%d>", date[i]);
		}
		printf("\n");
	}
};