#pragma once
#include "Node.h"

class LinkedStack
{
private:
	// 헤드 포인터
	Node* top;

public:
	// 생성자
	// 반드시 헤드 포인터 top을 NULL값으로 초기화 해야한다
	LinkedStack() { top = NULL; }

	// 소멸자
	// 현재의 리스트에 동적으로 할당한 노드가 하나라도 있으면 모두 동적으로 해제해야 함
	// 이를 위해 공백 상태가 아닐 때까지 pop 연산으로 노드를 꺼내고 delete 연산으로 삭제함
	~LinkedStack()
	{
		while (!isEmpty())
		{
			delete pop();
		}
	}

	// 공백상태는 top이 NULL인 상태임
	bool isEmpty() { return top == NULL; }

	// 노드 p를 삽입하는 함수
	// 공백상태이면 p가 top이 되며
	// 그렇지 않은 경우는 현재의 top을 p다음으로 연결하고 포인터 top을 새로 들어온 노드인 p로 변경
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

	// 삭제 함수
	// 공백 상태이면 NULL을 반환하고
	// 아니면 현재의 top을 p에 저장하고 top을 다음 노드로 수정한 다음 p를 반환함
	Node* pop()
	{
		if (isEmpty())
			return NULL;

		Node* p = top;
		top = top->getLink();

		return p;
	}

	// 현재의 top을 반환하면 됨
	Node* peek() { return top; }

	// 연결된 스택의 모든 노드 내용을 화면에 출력하는 함수
	// 모든 노드를 한 번씩 방문하기 위한 다음 코드에 유의할 것
	void display()
	{
		printf("[LinkedStack]\n");

		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();

		printf("\n");
	}
};