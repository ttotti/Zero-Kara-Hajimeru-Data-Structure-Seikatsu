#pragma once

#include "Node.h"

// 단일 연결 리스트
// 첫 번째 노드에서부터 링크를 따라서 원하는 위치 또는 마지막 노드까지 가서 삽입, 삭제를 한다
// 선행 노드의 주소는 알지 못하고 오로지 후속 노드의 주소만 알 수 있다(마지막 노드의 후속 노드 주소는 NULL)
// 그래서 원하는 위치에 삽입, 삭제를 하고 싶으면 첫 번째 노드 부터 쭉 따라가 원하는 위치의 전 노드의 후속 노드 주소를 가져와야 한다

class LinkedList
{
private:
	// 데이터 멤버로 헤드 노드 선언(헤드 포인터가 아님)
	Node org;

public:
	// 생성자
	LinkedList()
		:org(0)
	{}
	// 소멸자
	~LinkedList() { clear(); }

	// 연결 리스트의 노드들은 동적으로 할당되므로 리스트 객체가 소멸될 때 남아 있는 모든 노드의 메모리를 해제해야 누수(leakage)가 발생하지 않음
	// 소멸자에서 clear()연산을 호출하고 여기서 리스트가 공백 상태가 될때까지 첫 번째 항목을 반복적으로 삭제함
	// 배열에서와 동일하게 첫 번째 항목의 인덱스는 0으로 처리함
	void clear()
	{
		while (!isEmpty())
		{
			delete remove(0);
		}
	}

	// 헤드 노드를 구하는 함수
	// org의 링크 값을 반환(첫 번째 주소)
	Node* getHead() { return org.getLink(); }
	// getHead() 가 NULL이면 리스트에 항목이 하나도 없는 공백 상태임
	bool isEmpty() { return getHead() == NULL; }

	// pos번째 항목을 반환함
	// pos 번째 노드의 주소를 반환함
	// 이때 pos가 0인 노드가 리스트의 첫 번째 노드이므로 getEntry(0)와 getHead()는 동일한 값을 반환
	// getEntry(-1)이 의도적으로 NULL이 아니라 헤드 노드의 주소를 반환하도록 설계한 것에 유의할 것
	// 이는 몇몇 함수에서 코드를 단순하게 해주는 장점이 있음
	Node* getEntry(int pos)
	{
		// 헤드 노드의 주소를 얻어온다
		Node* n = &org;

		// 헤드 노드의 주소부터 원하는 위치까지 하나씩 링크를 따라간다
		// 즉 첫 번째 노드에서부터 링크를 따라서 원하는 위치 또는 마지막 노드까지 가서 삽입, 삭제를 한다(단일 연결 리스트)
		for (int i = -1; i < pos; i++, n = n->getLink())
		{
			if (n == NULL)
				break;
		}

		return n;
	}

	// 리스트의 어떤 위치에 항목 삽입
	// pos 위치에 n을 삽입하는 연산
	// 먼저 pos-1 위치의 노드 prev를 찾고 이 노드의 삽입 함수를 prev->insertNext(n) 와 같이 호출하여
	// 실제의 삽입은 노드 클래스의 삽입 함수에서 이루어지도록 함
	// 이때 첫 번째 노드로 삽입하는 경우에도 특별한 처리를 않고도 잘 동작하는 것에 유의할 것
	// 이것은 getEntry(-1)이 NULL이 아니라 헤드 노드의 주소가 반환되도록 설계했기 때문임
	void insert(int pos, Node* n)
	{
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
			prev->insertNext(n);
	}

	// 리스트의 어떤 위치의 항목 삭제
	// pos 위치의 요소를 삭제하기 위해 먼저 pos-1 위치의 노드 prev를 찾고 이 노드에서 removeNext() 함수를 호출함
	// 이때 삽입에서와 같은 이유에 의해 첫 번째 노드를 삭제하는 경우도 코드의 변화 없이 잘 동작하는 것에 유의
	Node* remove(int pos)
	{
		Node* prev = getEntry(pos - 1);

		return prev->removeNext();
	}

	// 탐색 함수
	// 노드의 데이터 필드의 값이 val인 노드를 찾아 주소를 반환하는 탐색 연산
	// 모든 노드를 순서적으로 방문하는 다음 코드에 유의 할것
	Node* find(int val)
	{
		// 이 코드의 반복문에서 포인터 변수 p 는 헤드 노드로 초기화 되고
		// 이후 반복적으로 link 값을 따라 후속 노드로 진행하면서 방문하는데
		// NULL이 되면 더 이상 노드가 없으므로 방문을 종료하게 됨
		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			if (p->hasData(val))
				return p;
		}

		return NULL;
	}

	// pos 위치에 있는 노드를 n으로 바꾸는 함수
	// 후속 노드를 삭제 시 메모리 해제를 위한 다음 코드에 유의할 것
	void replace(int pos, Node* n)
	{
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
		{
			// 이 코드 유의할 것!
			// 반환 된 값을 해제
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	// 리스트 항목 개수를 반환
	int size()
	{
		int count = 0;

		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			count++;
		}

		return count;
	}

	// 화면에 보기 좋게 출력
	void display()
	{
		printf("[전체 항목 수 = %2d] : ", size());

		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();

		printf("\n");
	}
};