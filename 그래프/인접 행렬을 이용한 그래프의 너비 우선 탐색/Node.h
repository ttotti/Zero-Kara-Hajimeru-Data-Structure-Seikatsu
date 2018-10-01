#pragma once

// 인접 리스트를 이용한 그래프를 위한 노드 클래스
#include <cstdio>

class Node
{
	// 클래스의 상속을 대비해 데이터 필드를 protected로 선언
protected:
	// 정점의 id, 인접 정점의 인덱스
	int id;
	// 다음 노드의 포인터, 다음 노드를 위한 포인터 변수
	Node* link;

public:
	// 생성자, 멤버 초기화 리스트 사용, 링크는 디폴트 매개변수 사용
	Node(int i, Node* l = NULL)
		:id(i), link(l) {}
	// 소멸자, 하나의 노드가 소멸될 때 연결된 모든 노드를 삭제하도록 설계함
	~Node()
	{
		if (link != NULL)
			delete link;
	}

	// 데이터 필드 접근 함수들
	int getId() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};