#pragma once

#include "Line.h"

class Node :public Line
{
private:
	Node* link;

public:
	// 생성자 // 문자를 입력받고 그 문자를 Line 클래스에 초기화를 한다
	Node(const char *str = "")
		:Line(str), link(NULL){}

	// 접근자
	void setLine(Node* p) { link = p; }
	Node* getLink() { return link; }

	// 노드 연결
	void insertNext(Node* p)
	{
		if (p != NULL)
		{
			p->link = link;
			link = p;
		}
	}

	// 노드 삭제
	Node* removeNext()
	{
		Node* removed = link;

		if (removed != NULL)
		{
			link = removed->link;
		}
		return removed;
	}
};