#pragma once

#include <cstdio>

class Node
{
private:
	Node * link;
	int _data;

public:
	Node(int data)
		:link(NULL), _data(data){}

	Node* getLink() { return link; }
	void setLink(Node* Link) { link = Link; }
	void display() { printf(" <%2d>", _data); }
	int getdate() { return _data; }

	void insertnext(Node* data)
	{
		//Node* next = data;

		if (data != NULL)
		{
			data->link = link;
			link = data;
		}
	}

	Node* deletenext()
	{
		Node* remove = link;

		if (remove != NULL)
		{
			link = remove->link;
		}

		return remove;
	}
};