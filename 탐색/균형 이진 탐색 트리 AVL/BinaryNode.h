#pragma once

#include <cstdio>

class BinaryNode
{
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode* link;

public:
	BinaryNode()
		:data(0), left(NULL), right(NULL), link(NULL)
	{

	}

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

	// Ű ������ ��带 Ž���ϴ� �Լ�(��ȯ���� ���)
	// ��� Ŭ������ ����� ���� (�Ϲ� �Լ��� �ƴ�)

	// Ʈ���� �� ������ ��� �ڽ��� ��Ʈ�� ���� ����Ʈ���� ��ǥ�Ѵٰ� ������ �� �ִ�
	// ���� ��� Ŭ������ ���� �Լ��� �ۼ��ϴ� ���� �����ϴ�
	// �� ��� �Ű������� �ϳ� �پ��� �Ϳ� �����Ѵ�
	BinaryNode* search(int key)
	{
		// Ž�� ����
		if (key == data)
			return this;
		// key < �������� data
		// key�� �ڽ��� Ű ������ ������ ���� ����Ʈ�� Ž�� // �̶� ���� �ڽ� ��尡 �־�� ȣ���� �� �����Ƿ� �̸� �˻��Ѵ�
		else if (key < data&&left != NULL)
			return left->search(key);
		// key > �������� data
		// key�� �ڽ��� Ű ������ ũ�� ������ ����Ʈ�� Ž�� // �̶� ������ �ڽ� ��尡 �־�� ȣ�� �� �� �����Ƿ� �̸� �˻��Ѵ�
		else if (key > data&&right != NULL)
			return right->search(key);
		// ã�� ��� ����
		else
			return NULL;
	}
};