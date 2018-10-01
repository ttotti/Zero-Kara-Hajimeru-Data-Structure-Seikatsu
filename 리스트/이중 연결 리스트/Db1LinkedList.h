#pragma once

#include "Node2.h"

class Db1LinkedList
{
	Node2 org; // 헤드노드

public:
	// 생성자
	Db1LinkedList()
		:org(0) {}
	// 소멸자
	~Db1LinkedList()
	{
		while (!isEmpty())
		{
			delete remove(0);
		}
	}

	// 모든 구성요소를 제거
	void clear()
	{
		while(!isEmpty())
		{
			delete remove(0);
		}
	}

	// 헤드노드의 다음요소를 반환
	// getHead()와 getEntry(0)은 헤드 노드의 다음 주소를 반환하므로 값이 같다
	Node2* getHead() { return org.getNext(); }
	// 해당 리스트가 비어있는지 확인
	bool isEmpty() { return getHead() == NULL; }

	// pos 번째 노드 반환
	// pos 번째 노드의 주소를 반환함
	// 이때 pos가 0인 노드가 리스트의 첫 번째 노드이므로 getEntry(0)와 getHead()는 동일한 값을 반환
	// getEntry(-1)이 의도적으로 NULL이 아니라 헤드 노드의 주소를 반환하도록 설계한 것에 유의할 것
	// 이는 몇몇 함수에서 코드를 단순하게 해주는 장점이 있음
	Node2* getEntry(int pos)
	{
		// 해드 노드의 주소를 가져와서 (헤드 노드는 포인터 변수가 아니다)
		Node2* n = &org;

		// getEntry(-1) 일때 즉 0번째를 지정하면 NULL이 아니라 헤드 노드의 주소를 반환한다
		// 그리고 pos가 0인 노드가 리스트의 첫 번째 노드이므로 getEntry(0)와 getHead()는 동일한 값을 반환한다
		for (int i = -1; i < pos; i++, n = n->getNext())
		{
			// 탐색 도중 NULL 값이 나올경우 루프를 나간다
			if (n == NULL) break;
		}

		return n;
	}

	// pos 위치에 노드 삽입
	void insert(int pos, Node2* n)
	{
		// pos위치에 삽입을 위해 pos-1의 주소를 읽는다
		Node2* prev = getEntry(pos - 1);

		// prev가 NULL값이 아니면 즉 값이 정상이면 삽입을 시작한다
		if (prev != NULL)
			prev->insertNext(n);
	}

	// pos 위치에 노드 삭제
	Node2* remove(int pos)
	{
		Node2* n = getEntry(pos);
		return n->remove();
	}

	// 값이 val인 노드 탐색
	Node2* find(int val)
	{
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
		{
			if (p->hasData(val))
				return p;
		}

		return NULL;
	}

	// pos 위치의 노드 교체
	void replace(int pos, Node2* n)
	{
		// pos-1위치를 탐색햐고
		Node2* prev = getEntry(pos - 1);

		// 그 값이 NULL 이 아니면
		if (prev != NULL)
		{
			// 그 위치의 후속 노드를 삭제
			delete prev->getNext()->remove();
			// 그 위치의 후속 노드에 삽입
			prev->insertNext(n);
		}
	}

	// 리스트의 전체 노드수 반환
	int size()
	{
		int count = 0;
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			count++;

		return count;
	}

	// 리스트를 화면에 보기 좋게 출력
	void display()
	{
		printf("[이중연결리스트 항목 수 = %2d] :", size());

		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			p->display();

		printf("\n");
	}
};