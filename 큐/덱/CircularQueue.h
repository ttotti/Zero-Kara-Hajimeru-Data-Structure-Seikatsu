#pragma once

#include <cstdio>
#include <cstdlib>

#define MAX_QUEUE_SIZE 100

inline void error(char* message)
{
	printf("%s", message);
	exit(1);
}

class CircularQueue
{
protected:
	int front; // ù ��° ����� ���� ��ġ
	int rear; // ������ ��� ��ġ
	int data[MAX_QUEUE_SIZE]; // ����� �迭

public:
	CircularQueue() { front = rear = 0; } // front == rear �� �Ǹ� �������

	bool isEmpty() { return front == rear; } // front == rear �� �Ǹ� �������
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; } // front�� rear���� ��ĭ �տ� ������ ��ȭ����

	void enqueue(int val) // ť�� ����
	{
		if (isFull())
			error("ť�� ��ȭ�����Դϴ�");
		else
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	int dequeue() // ù �׸��� ť���� ���� ��ȯ
	{
		if (isEmpty())
			error("ť�� �����Ͱ� �����ϴ�");
		else
		{
			front = (front + 1) % MAX_QUEUE_SIZE;

			return data[front];
		}
	}

	int peek() // ù �׸��� ť���� ���� �ʰ� ��ȯ
	{
		if (isEmpty())
			error("ť�� �����Ͱ� �����ϴ�");
		else
		{
			data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}

	void display()
	{
		printf("ť ����");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

		for (int i = front + 1; i <= maxi; i++)
			printf("[%d] ", data[i%MAX_QUEUE_SIZE]);

		printf("\n");
	}
};