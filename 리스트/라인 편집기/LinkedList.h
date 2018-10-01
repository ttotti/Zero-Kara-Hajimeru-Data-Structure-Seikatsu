#pragma once

#include "Node.h"

class LinkedList
{
protected:
	Node org;

public:
	LinkedList()
		:org(""){}
	~LinkedList() { clear(); }

	// ��� ��� ����
	void clear()
	{
		while (!isEmpty())
		{
			delete remove(0);
		}
	}

	// ù ��° ��带 ��ȯ��
	Node* getHead() { return org.getLink(); }
	// ����Ʈ�� ��Ұ� �ִ��� ����
	bool isEmpty() { return getHead() == NULL; }

	// �ش� ��ġ Ž��
	Node* getEntry(int pos)
	{
		Node* n = &org;

		for (int i = -1; i < pos; i++, n = n->getLink())
		{
			if (n == NULL)
				break;
		}

		return n;
	}

	// pos ��ġ�� n ����
	void insert(int pos, Node* n)
	{
		// (pos - 1) �� �����ϱ�!
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos ��ġ ��� ����
	Node* remove(int pos)
	{
		// (pos - 1) �� �����ϱ�!
		Node* prev = getEntry(pos - 1);

		return prev->removeNext();
	}

	// ����Ʈ���� str ���ڿ��� Ž��
	Node* find(char* str)
	{
		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			if (p->hasData(str))
				return p;
		}

		return NULL;
	}

	// pos ��ġ�� n ���� ��ü
	void replace(int pos, Node* n)
	{
		// (pos - 1) �� �����ϱ�!
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
		{
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	// ����Ʈ�� ����� ����
	int size()
	{
		int count = 0;

		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			count++;
		}

		return count;
	}

};