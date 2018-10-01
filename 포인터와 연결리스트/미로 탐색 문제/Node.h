#pragma once

#include <cstdio>
#include "Location2D.h"

class Node :public Location2D
{
private:
	// ���� ��带 ����Ű�� ������ ����
	Node* link;

public:
	Node(int r, int c)
		:Location2D(r, c)
	{ 
		link = NULL; 
	}
	//Node(Location2D& d)
	//{
	//	link = NULL;
	//}
	~Node(){}

	void setLink(Node* p) { link = p; }
	Node* getLink() { return link; }

};