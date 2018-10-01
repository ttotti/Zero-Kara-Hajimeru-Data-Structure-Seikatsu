#pragma once

#include "Node2.h"

class Db1LinkedList
{
	Node2 org; // �����

public:
	// ������
	Db1LinkedList()
		:org(0) {}
	// �Ҹ���
	~Db1LinkedList()
	{
		while (!isEmpty())
		{
			delete remove(0);
		}
	}

	// ��� ������Ҹ� ����
	void clear()
	{
		while(!isEmpty())
		{
			delete remove(0);
		}
	}

	// ������� ������Ҹ� ��ȯ
	// getHead()�� getEntry(0)�� ��� ����� ���� �ּҸ� ��ȯ�ϹǷ� ���� ����
	Node2* getHead() { return org.getNext(); }
	// �ش� ����Ʈ�� ����ִ��� Ȯ��
	bool isEmpty() { return getHead() == NULL; }

	// pos ��° ��� ��ȯ
	// pos ��° ����� �ּҸ� ��ȯ��
	// �̶� pos�� 0�� ��尡 ����Ʈ�� ù ��° ����̹Ƿ� getEntry(0)�� getHead()�� ������ ���� ��ȯ
	// getEntry(-1)�� �ǵ������� NULL�� �ƴ϶� ��� ����� �ּҸ� ��ȯ�ϵ��� ������ �Ϳ� ������ ��
	// �̴� ��� �Լ����� �ڵ带 �ܼ��ϰ� ���ִ� ������ ����
	Node2* getEntry(int pos)
	{
		// �ص� ����� �ּҸ� �����ͼ� (��� ���� ������ ������ �ƴϴ�)
		Node2* n = &org;

		// getEntry(-1) �϶� �� 0��°�� �����ϸ� NULL�� �ƴ϶� ��� ����� �ּҸ� ��ȯ�Ѵ�
		// �׸��� pos�� 0�� ��尡 ����Ʈ�� ù ��° ����̹Ƿ� getEntry(0)�� getHead()�� ������ ���� ��ȯ�Ѵ�
		for (int i = -1; i < pos; i++, n = n->getNext())
		{
			// Ž�� ���� NULL ���� ���ð�� ������ ������
			if (n == NULL) break;
		}

		return n;
	}

	// pos ��ġ�� ��� ����
	void insert(int pos, Node2* n)
	{
		// pos��ġ�� ������ ���� pos-1�� �ּҸ� �д´�
		Node2* prev = getEntry(pos - 1);

		// prev�� NULL���� �ƴϸ� �� ���� �����̸� ������ �����Ѵ�
		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos ��ġ�� ��� ����
	Node2* remove(int pos)
	{
		Node2* n = getEntry(pos);
		return n->remove();
	}

	// ���� val�� ��� Ž��
	Node2* find(int val)
	{
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
		{
			if (p->hasData(val))
				return p;
		}

		return NULL;
	}

	// pos ��ġ�� ��� ��ü
	void replace(int pos, Node2* n)
	{
		// pos-1��ġ�� Ž�����
		Node2* prev = getEntry(pos - 1);

		// �� ���� NULL �� �ƴϸ�
		if (prev != NULL)
		{
			// �� ��ġ�� �ļ� ��带 ����
			delete prev->getNext()->remove();
			// �� ��ġ�� �ļ� ��忡 ����
			prev->insertNext(n);
		}
	}

	// ����Ʈ�� ��ü ���� ��ȯ
	int size()
	{
		int count = 0;
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			count++;

		return count;
	}

	// ����Ʈ�� ȭ�鿡 ���� ���� ���
	void display()
	{
		printf("[���߿��Ḯ��Ʈ �׸� �� = %2d] :", size());

		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			p->display();

		printf("\n");
	}
};