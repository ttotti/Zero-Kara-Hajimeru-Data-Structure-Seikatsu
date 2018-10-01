#pragma once
#include "Node.h"

class LinkedStack
{
private:
	// ��� ������
	Node* top;

public:
	// ������
	// �ݵ�� ��� ������ top�� NULL������ �ʱ�ȭ �ؾ��Ѵ�
	LinkedStack() { top = NULL; }

	// �Ҹ���
	// ������ ����Ʈ�� �������� �Ҵ��� ��尡 �ϳ��� ������ ��� �������� �����ؾ� ��
	// �̸� ���� ���� ���°� �ƴ� ������ pop �������� ��带 ������ delete �������� ������
	~LinkedStack()
	{
		while (!isEmpty())
		{
			delete pop();
		}
	}

	// ������´� top�� NULL�� ������
	bool isEmpty() { return top == NULL; }

	// ��� p�� �����ϴ� �Լ�
	// ��������̸� p�� top�� �Ǹ�
	// �׷��� ���� ���� ������ top�� p�������� �����ϰ� ������ top�� ���� ���� ����� p�� ����
	void push(Node* p)
	{
		if (isEmpty())
			top = p;
		else
		{
			p->setLink(top);
			top = p;
		}
	}

	// ���� �Լ�
	// ���� �����̸� NULL�� ��ȯ�ϰ�
	// �ƴϸ� ������ top�� p�� �����ϰ� top�� ���� ���� ������ ���� p�� ��ȯ��
	Node* pop()
	{
		if (isEmpty())
			return NULL;

		Node* p = top;
		top = top->getLink();

		return p;
	}

	// ������ top�� ��ȯ�ϸ� ��
	Node* peek() { return top; }

	// ����� ������ ��� ��� ������ ȭ�鿡 ����ϴ� �Լ�
	// ��� ��带 �� ���� �湮�ϱ� ���� ���� �ڵ忡 ������ ��
	void display()
	{
		printf("[LinkedStack]\n");

		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();

		printf("\n");
	}
};