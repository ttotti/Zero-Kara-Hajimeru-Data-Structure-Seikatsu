#pragma once
#include "Node.h"

class LinkedQueue
{
private:
	// ť ��� ����
	// ������ ���� front �� ������ ���� rear�� �ִ�
	Node* front;
	Node* rear;

public:
	// ������ front�� rear�� �׻� NULL������ �ʱ�ȭ�� ���־���Ѵ�
	LinkedQueue()
		:front(NULL), rear(NULL){}

	// �Ҹ��� ���� ���°� �ƴ� ������ dequeue()�� �ϳ��� ���� delete�������� �����Ѵ�
	~LinkedQueue()
	{
		while (!isEmpty())
		{
			delete dequeue();
		}
	}

	// front�� NULL�̸� ���������
	bool isEmpty() { return front == NULL; }

	// ���� : ����� ť�� �� �ڿ� ��� ����
	void enqueue(Node* p)
	{
		// ť �ȿ� �����Ͱ� �������(front�� NULL�� ����) front�� rear�� ���� ������ p�� ����Ű���� �Ѵ�
		if (isEmpty())
			front = rear = p;
		// ť �ȿ� �����Ͱ� �ϳ��̻� ������� ����rear�� ��ũ�ʵ尡 ���� ������ p�� ����Ű�� �ϰ� rear�� p�� ����Ű�� �Ѵ�
		else
		{
			rear->setLink(p);
			rear = p;
		}
	}

	// ���� : ����� ť�� �� �� ��带 ����
	Node* dequeue()
	{
		// ���� �����̸� NULL�� ��ȯ�ϰ�
		if (isEmpty())
			return NULL;

		// �� ���� �����͸� �ӽ÷� Node* p�� �����ϰ�
		Node* p = front;
		// front�� ���� ��带 ����Ű�� �Ѵ�
		front = front->getLink();

		// front�� NULL�̸�(�������) rear�� NULL�� �ʱ�ȭ �Ѵ�
		if (front == NULL)
			rear = NULL;

		// �ӽ÷� ������ �����͸� ��ȯ�Ѵ�
		return p;
	}

	Node* peek()
	{
		return front;
	}

	void display()
	{
		for (Node* p = front; p != NULL; p = p->getLink())
		{
			printf("[ť ����] : ");
			p->display();
		}
		printf("\n");
	}
};