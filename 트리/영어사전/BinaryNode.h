#pragma once

// ��� Ŭ������ Record�� ����ϹǷ� ������ ����δ� ��ũ �ʵ常 �߰��� �����ϴµ�
// �� �κ��� �����ϸ� �⺻���� ��� Ʋ�� �����ϴ�
// ��ũ �̿��� ������ �ʵ忡 ���� ó���� Record���� ����ϹǷ� �̵鿡 ���� ó�� �Լ����� �ʿ����
#include "Record.h"

class BinaryNode :public Record
{
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(const char* w = "", const char* m = "")
		:Record(w, m), left(NULL), right(NULL)
	{
	}

	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};