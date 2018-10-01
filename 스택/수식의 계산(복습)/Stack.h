#pragma once
#include <cstdio>

const int count = 20;

void error(char* a)
{
	printf("%c", a);
	exit(1);
}

class Stack
{
public:
	int top;
	double arr[count];

	Stack() { top = -1; }
	~Stack() { }

	bool isFull() { return top == count - 1; }
	bool isEmpty() { return top == -1; }

	void push(double e)
	{
		if (isFull())
		{
			error("스택의 공간이 꽉 차있습니다");
		}

		arr[++top] = e;
	}

	double pop()
	{
		if (isEmpty())
		{
			error("스택의 공간에 데이터가 없습니다");
		}

		return arr[top--];
	}

	double peek()
	{
		if (isEmpty())
		{
			error("스택의 공간에 데이터가 없습니다");
		}

		return arr[top];
	}

	void diplay()
	{
		printf("%4.1f\n", arr[top]);
	}
};