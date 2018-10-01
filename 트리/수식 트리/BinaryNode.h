#pragma once

#include <cstdio>

class BinaryNode
{
	int data;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode* link;

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r)
	{
		link = NULL;
	}

	void setdata(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getdata() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }

	void setlink(BinaryNode* n) { link = n; }
	BinaryNode* getlink() { return link; }
};