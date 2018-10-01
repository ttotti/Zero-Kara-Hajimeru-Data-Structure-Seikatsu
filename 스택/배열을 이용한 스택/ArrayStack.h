#pragma once
#include <cstdio>
#include <cstdlib>

#include "Student.h"

inline void error(char* message)
{
	printf("%s\n", message);
	exit(1);
}

// ������ �ִ� ũ��
const int MAX_STACK_SIZE = 20;

class ArrayStack
{
private:
	int top; // ����� ����
	Student date[MAX_STACK_SIZE]; // ����� �迭 // �л��� ������ ������ Student ��ü�� �迭�� �����Ѵ�

public:
	// ������ // �迭�� 0���� �����ϹǷ� �ʱⰪ�� -1�ϰ� �߰��� +1�� �Ѵ�
	ArrayStack() { top = -1; }
	~ArrayStack() {}

	bool isEmpty() { return top == -1; } // ����� ������ top�� -1�̸� ���ÿ� �ƹ��͵� �ȵ���ִٴ°�
	bool isFull() { return top == MAX_STACK_SIZE - 1; } // ����� ������ top�� �ִ�ũ��-1 ��ŭ ����ִٸ� ������ �� ���ִٴ� ��

	// �����͸� �����Ѵ�
	// Student Ÿ���� �����͸� �����Ѵ� // �����Ͱ� ũ�ٸ� �����ͳ� ���۷����� �Ѱܵ� �ȴ�
	void push(Student e)
	{
		// ���ð����� �� ���ִٸ� ������ �հ� �����Ѵ�
		if (isFull())
			error("���� ���� ����");

		// ������ �Ȼվ��ٸ� top�� ���� +1 �ϰ� �迭�� �����͸� �����Ѵ�
		date[++top] = e;
	}
	
	// �� ���� �����͸� �����ϰ� ��ȯ�Ѵ�
	// Student Ÿ���� �����͸� ��ȯ�Ѵ� // �̰� ���� �����ͳ� ���۷����� ó���Ҽ��ִ�
	Student pop()
	{
		// ���ð����� ����ִٸ� ������ �մ´�
		if (isEmpty())
			error("���� ���� ����");

		// ������ �� �վ��ٸ� �����͸� ��ȯ���� top�� -1 �Ѵ�
		return date[top--];
	}

	// �� ���� �����͸� �������� �ʰ� ��ȯ�Ѵ�
	Student peek()
	{
		if (isEmpty())
			error("���� ���� ����");

		// �����͸� ��ȯ�ϰ� top�� �������д�
		return date[top];
	}

	// ���ð����ȿ� �ִ� �����͸� ����Ѵ�
	// �� �л��� ������ Student Ŭ������ ����Լ��� ����Ѵ�
	void display()
	{
		printf("[��ü �л��� �� = %2d] ==> \n", top + 1); // top�� -1���� ���������Ƿ� ����� +1�� �Ѵ�
		for (int i = 0; i <= top; i++) // i<top�� �ϸ� top-1��ŭ �����ϱ� ������ <= ���� �����Ѵ�
			date[i].display();
		printf("\n");
	}
};