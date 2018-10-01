#pragma once
#include "Node.h"

class LinkedQueue
{
private:
	// 큐 멤버 변수
	// 삭제를 위한 front 와 삽입을 위한 rear가 있다
	Node* front;
	Node* rear;

public:
	// 생성자 front와 rear는 항상 NULL값으로 초기화를 해주어야한다
	LinkedQueue()
		:front(NULL), rear(NULL){}

	// 소멸자 공백 상태가 아닐 때까지 dequeue()로 하나씩 빼서 delete연산으로 삭제한다
	~LinkedQueue()
	{
		while (!isEmpty())
		{
			delete dequeue();
		}
	}

	// front가 NULL이면 공백상태임
	bool isEmpty() { return front == NULL; }

	// 삽입 : 연결된 큐의 맨 뒤에 노드 삽입
	void enqueue(Node* p)
	{
		// 큐 안에 데이터가 없을경우(front가 NULL인 상태) front와 rear가 들어온 데이터 p를 가리키도록 한다
		if (isEmpty())
			front = rear = p;
		// 큐 안에 데이터가 하나이상 있을경우 현재rear의 링크필드가 들어온 데이터 p를 가리키게 하고 rear가 p를 가리키게 한다
		else
		{
			rear->setLink(p);
			rear = p;
		}
	}

	// 삭제 : 연결된 큐의 맨 앞 노드를 삭제
	Node* dequeue()
	{
		// 공백 상태이면 NULL을 반환하고
		if (isEmpty())
			return NULL;

		// 맨 앞의 데이터를 임시로 Node* p에 저장하고
		Node* p = front;
		// front가 다음 노드를 가리키게 한다
		front = front->getLink();

		// front가 NULL이면(공백상태) rear도 NULL로 초기화 한다
		if (front == NULL)
			rear = NULL;

		// 임시로 저장한 데이터를 반환한다
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
			printf("[큐 내용] : ");
			p->display();
		}
		printf("\n");
	}
};