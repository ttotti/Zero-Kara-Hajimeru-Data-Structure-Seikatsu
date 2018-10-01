#pragma once

#include <cstdio>

// 이중 연결 리스트 노드를 나타내기 위한 클래스
class Node2
{
	Node2* prev; // 선행 노드를 가리키는 포인터 변수
	Node2* next; // 후속 노드를 가리키는 포인터 변수
	int data; // 데이터 필드

public:
	Node2(int val = 0)
		:data(val), prev(NULL), next(NULL) {}

	Node2* getPrev() { return prev; }
	Node2* getNext() { return next; }
	void setPrev(Node2* p) { prev = p; }
	void setNext(Node2* n) { next = n; }
	void display() { printf(" <%2d>", data); }

	bool hasData(int val) { return data == val; }

	// 자신의 다음에 새로운 노드 n을 삽입하는 함수
	// 어떤 노드(현재 노드) 다음에 새로운 노드 N을 추가하려고 한다 이를 위해 네 단계 처리가 필요하다(인터넷, 책 242p 그림 참고)
	void insertNext(Node2* n)
	{
		if (n != NULL)
		{
			// N의 선행 노드를 현재 노드로 설정
			n->prev = this;

			// N의 후속 노드를 현재 노드의 후속 노드 설정
			n->next = next;

			// 현재 노드의 후속 노드의 선행 노드를 N으로 설정 (현재 노드의 후속 노드와 연결되있는 주소가 있을 경우)
			if (next != NULL) 
				next->prev = n;

			// 현재 노드의 후속 노드를 N으로 설정
			next = n;
		}
	}
	
	// 현재 노드를 연결 리스트에서 제거하는 함수
	// 이중 연결 리스트의 모든 노드는 자신의 선행 노드를 알 수 있다
	// 따라서 삭제 함수를 removeNext()와 같이 할 필요가 없다
	// 자신(현재 노드) 자체를 리스트에서 삭제할 수 있기 때문이다
	// 따라서 함수의 이름은 remove()로 변경한다
	// (인터넷, 책243p 그림 참고)
	Node2* remove()
	{
		// 삭제할 노드의 선행노드를 삭제할 노드의 후속노드에 연결해준다
		if (prev != NULL) prev->next = next;
		// 삭제할 노드의 후속노드를 삭제할 노드의 선행노드에 연결해준다
		if (next != NULL) next->prev = prev;
		// 삭제하는 자기 주소 반환
		return this;
	}
};