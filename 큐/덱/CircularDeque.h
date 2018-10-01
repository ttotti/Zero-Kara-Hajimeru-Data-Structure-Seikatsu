#pragma once

#include "CircularQueue.h"

// ť Ŭ������ ���
// ���� ���ð� ť�� ������ ��� ������ �ִ�
// ���� ��� ���� ����(front)�� ���õ� ����鸸 ����ϸ� ������ �ǰ�
// ������ �Ĵ�(rear) ������ ����(front)�� ����ϸ� ť�� �ȴ�
// �� ���� ���Ḯ��Ʈ�� �����Ҽ��ִµ� ���߿��Ḯ��Ʈ ��� ������ �����ؾ� �Ѵ�
class CircularDeque :public CircularQueue
{
public:
	CircularDeque(){}

	void addRear(int val) // �Ĵܿ� ����
	{
		enqueue(val);
	}

	int deleteFront()
	{
		return dequeue();
	}

	int getFront()
	{
		return peek();
	}

	
	void addFront(int val) // ���ܿ� ����
	{
		if (isFull())
			error("���� ��ȭ�����Դϴ�");
		else
		{
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}

	int deleteRear()
	{
		if (isEmpty())
			error("���� �����Ͱ� �����ϴ�");
		else
		{
			int ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}

	int getRear()
	{
		if (isEmpty())
			error("���� �����Ͱ� �����ϴ�");
		else
			return data[rear];
	}

	void display()
	{
		printf("���� ���� : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

		for (int i = front + 1; i <= maxi; i++)
			printf("[%d] ", data[i%MAX_QUEUE_SIZE]);

		printf("\n");
	}
};