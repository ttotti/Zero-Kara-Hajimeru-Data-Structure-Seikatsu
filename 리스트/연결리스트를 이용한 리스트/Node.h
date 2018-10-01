#pragma once

#include <cstdio>

// 지금 까지 노드 클래스에 연산을 구현하지 않고
// 스택 클래스나 큐 클래스에 삽입, 삭제 연산을 구현했다면
// 지금은 리스트의 삽입, 삭제 연산을 리스트 클래스가 아닌 노드 클래스에 구현하고 있다
// 이유는 리스트에 구현해야할 기능이 많고 복잡해서 굳이 리스트에서 하지않아도 할 수 있는 기능은 따로 구현한다(물론 리스트에 전부 구현해도 된다)

// C++와 같은 객체지향 프로그래밍에서 아주 중요한 습관 중 하나는 작은 클래스에서 할 수 있는 가능한 한 많은 기능을 구현하는 것이다
// 어떤 노드에서 자신의 다음 노드를 삭제하거나 자신 노드 다음에 어떤 노드를 삽입하는 등의 작업은 전체 리스트 정보가 없이도 처리할 수 있다
// 따라서 이들은 Node 클래스에 멤버 함수로 구현해 주는 것이 좋다
class Node
{
	// 새로 이해한 지식 (만약 아니면 수정 바람)
	// Node 클래스 안에  Node* link가 있고 객체를 만들면 그 객체에는 주소가 2개가 있는 것이다
	// 예) Node* n 를 선언하면 n 의 주소 와 n->link 즉 link 의 주소 두개가 따로 존재한다
private:
	Node* link;
	int data;

public:
	// 생성자
	Node(int val = 0)
		:data(val),link(NULL)
	{}

	// 접근자 및 출력(스택의 노드 클래스와 동일)
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { printf("<%2d> ", data); }

	// 데이터 멤버 data가 val과 같은지를 검사하는 함수
	// 이것은 find() 연산에서 사용될 것이다
	bool hasData(int val) { return data == val; }

	// 자신의 다음에 새로운 노드 n을 삽입하는 함수
	// 현재 노드의 후속 노드로 새로운 노드 n을 삽입하는 함수 
	// n 이 NULL이 아닐 때만 처리하는 것에 유의
	void insertNext(Node* n)
	{
		if (n != NULL)
		{
			n->link = link;
			link = n;
		}
	}

	// 자신의 다음 노드를 리스트에서 삭제하는 함수
	// 현재 노드의 후속 노드를 연결 리스트에서 삭제하는 함수
	// 이 함수가 삭제된 노드의 주소를 반환하는 것에 유의할 것
	// 그렇지 않으면 삭제된 노드의 메모리가 해제되지 않고 위치를 잃어버리게 됨
	Node* removeNext()
	{
		Node* removed = link;

		if (removed != NULL)
			link = removed->link;

		return removed;
	}
};