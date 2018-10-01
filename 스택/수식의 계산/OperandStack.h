#pragma once

#include <cstdio>
#include <cstdlib>

void error(char* message)
{
	printf("%s\n", message);
	exit(1);
}

#define MAX_STACK_SIZE 20

class OperandStack
{
private:
	int top;
	double date[MAX_STACK_SIZE];

public:
	OperandStack() { top = -1; }
	~OperandStack() {}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(double d)
	{
		if (isFull())
			error("���� ������ �� á���ϴ�");

		date[++top] = d;
	}

	double pop()
	{
		if (isEmpty())
			error("���� ������ �� ����� �ֽ��ϴ�");

		return date[top--];
	}
};
