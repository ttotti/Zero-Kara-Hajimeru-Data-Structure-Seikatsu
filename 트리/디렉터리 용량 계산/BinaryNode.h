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

	void Setdata(int val) { data = val; }
	void SetLeft(BinaryNode* l) { left = l; }
	void SetRight(BinaryNode* r) { right = r; }

	int Getdata() { return data; }
	BinaryNode* GetLeft() { return left; }
	BinaryNode* GetRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }

	void SetLink(BinaryNode* l) { link = l; }
	BinaryNode* GetLink() { return link; }
};