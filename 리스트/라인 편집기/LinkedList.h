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

	// 모든 요소 삭제
	void clear()
	{
		while (!isEmpty())
		{
			delete remove(0);
		}
	}

	// 첫 번째 노드를 반환함
	Node* getHead() { return org.getLink(); }
	// 리스트에 요소가 있는지 조사
	bool isEmpty() { return getHead() == NULL; }

	// 해당 위치 탐색
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

	// pos 위치에 n 삽입
	void insert(int pos, Node* n)
	{
		// (pos - 1) 에 주의하기!
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos 위치 요소 삭제
	Node* remove(int pos)
	{
		// (pos - 1) 에 주의하기!
		Node* prev = getEntry(pos - 1);

		return prev->removeNext();
	}

	// 리스트에서 str 문자열을 탐색
	Node* find(char* str)
	{
		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			if (p->hasData(str))
				return p;
		}

		return NULL;
	}

	// pos 위치에 n 으로 교체
	void replace(int pos, Node* n)
	{
		// (pos - 1) 에 주의하기!
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
		{
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	// 리스트의 요소의 갯수
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