#pragma once

#include <cstdio>
#include "Student.h"

class Node :public Student
{
private:
	// 다음 노드를 가리키는 포인터 변수
	Node* link;

public:
	// 생성자
	Node(int i = 0, char* n = "", char* d = "")
		:Student(i, n, d) 
	{
		link = NULL;
	}

	// 접근자
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};