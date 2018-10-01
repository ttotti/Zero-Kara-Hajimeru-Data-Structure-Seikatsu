#pragma once

#include "Record.h"

class Node :public Record
{
private:
	Node * link;

public:
	Node(const char* key, const char* val)
		:Record(key, val), link(NULL) {}

	Node* getLink() { return link; }

	void setLink(Node* next) { link = next; }
};