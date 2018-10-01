#pragma once
#include <cstdio>

// ������� Ŭ���� ����
class BinaryNode
{
	// ����� ����� ������ ������� protected�� ����
protected:
	// ��忡 ������ ������, �ܼ�ȭ�� ���� int�� �����ϵ��� �Ѵ� (���ø��� ����ϸ� �ڵ带 ������ �ʿ���� �پ��� Ÿ���� �����͸� ������ �� �ִ�)
	int data;
	// ���� �ڽİ� ������ �ڽĿ� ���� ������ ����
	BinaryNode* left;
	BinaryNode* right;

	// ť���� ����� ��带 �̾��� ��ũ
	BinaryNode* link;

public:
	// ������ // ����Ʈ �Ű������� ����Ͽ����� ��� �ʱ�ȭ ����Ʈ�� �̿��ؼ� ������ ����� �ʱ�ȭ�Ͽ���
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r)
	{
		link = NULL;
	}

	~BinaryNode()
	{

	}
	
	// ������ ����� �����ϴ� �Լ�
	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	// ������ ����� ��ȯ�ϴ� �Լ�
	int getData() { return data; }
	BinaryNode* getLeft() { return left;}
	BinaryNode* getRight() { return right; }

	// ���� ��尡 �ܸ� ��������� �˻��ϴ� �Լ�
	// �ܸ� ��尡 �Ǳ� ���ؼ��� ���� �ڽİ� ������ �ڽ��� ��� ����� ��
	bool isLeat() { return left == NULL && right == NULL; }

	// ���� ��带 ��Ʈ�� ���� ����Ʈ�������� ���� ��ȯ
	// ��ü�������� C++ ������ ��ü���� ��� �Լ��� ȣ���ϴ� ����� ����ϹǷ� ��ȸ �Լ��鵵 ��� Ŭ������ ��� �Լ��� ������ �� �ִ�
	// (�ܼ� ���� ����Ʈ�� ���԰� ���� ������ �߰��ϴ� �Ͱ� ������ ����)(å p318)
	// ������ ���� ��ȸ�� Ʈ�� Ŭ������ �ƴ� ��� Ŭ�������� ����ϵ��� ������ �ڵ��̴�
	// ��� Ŭ������ ��ȸ �Լ��� ������ ��� Ʈ�� Ŭ������ ������ ��ȸ�� �ʿ���� �ȴ�

	// �̿� ���� ��� Ŭ�������� ó���� �� �ִ� ������� ������ �̰��� ��� ��带 �� ��带 ��Ʈ�� �ϴ� �ϳ��� Ʈ���� ������ �� �ֱ� �����̴�
	void inorder()
	{
		if (left != NULL)
			left->inorder();

		printf("  [%c]  ", data);

		if (right != NULL)
			right->inorder();
	}

	// ť���� ����� ��ũ ������
	void setlink(BinaryNode* d) { link = d; }
	BinaryNode* getlink() { return link; }
};