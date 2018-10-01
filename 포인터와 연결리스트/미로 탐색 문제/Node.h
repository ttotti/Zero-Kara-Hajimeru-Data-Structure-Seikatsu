#pragma once

#include <cstdio>
#include "Location2D.h"

class Node :public Location2D
{
private:
	// 다음 노드를 가리키는 포인터 변수
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