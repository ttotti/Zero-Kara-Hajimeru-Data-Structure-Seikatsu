#pragma once

#include <cstdio>
#include "Student.h"

class Node :public Student
{
private:
	// ���� ��带 ����Ű�� ������ ����
	Node* link;

public:
	// ������
	Node(int i = 0, char* n = "", char* d = "")
		:Student(i, n, d) 
	{
		link = NULL;
	}

	// ������
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};