#pragma once

// ���� Ž�� Ʈ�� Ŭ����
#include "BinaryTree.h"

// ���� Ž�� Ʈ���� ����Ʈ���� �����̹Ƿ� ����Ʈ���� ����Ͽ� �����Ѵ�
class BinSrchTree :public BinaryTree
{
public:
	BinSrchTree(void){}
	~BinSrchTree(void){}

	// ���� Ž�� Ʈ���� Ž�� ����
	BinaryNode* search(int key)
	{
		BinaryNode* node = searchRecur(root, key);
		if (node != NULL)
			printf("Ž�� ����: Ű���� %d�� ��� = 0x%x\n", node->Getdata(), node);
		else
			printf("Ž�� ����: Ű���� %d�� ��� ����\n", key);

		return node;
	}

	// BinaryNode* search(BinaryNode* n,int key){}
	// Ű ������ ��带 Ž���ϴ� �Լ�(��ȯ���� ���)
	// �Ϲ� �Լ��� ���� ����, BinSrchTree�� ��� �Լ��� �־ ��
	BinaryNode* searchRecur(BinaryNode* n, int key)
	{
		// n�� NULL
		if (n == NULL)
			return NULL;

		// key == �������� data
		if (key == n->Getdata())
			return n;
		// key < �������� data
		else if (key < n->Getdata())
			return searchRecur(n->GetLeft(), key);
		// key > �������� data
		else
			return searchRecur(n->GetRight(), key);
	}

	// Ű ������ ��带 Ž���ϴ� �Լ�(�ݺ����� ���)
	// �Ϲ� �Լ��� ���� ����, BinSrchTree�� ��� �Լ��� �־ ��
	// n�� ��Ʈ�� �ϴ� ����Ʈ������ Ű ���� key�� ã�� ��ȯ�ϴ� �Լ�
	BinaryNode* searchIter(BinaryNode* n, int key)
	{
		while (n != NULL)
		{
			if (key == n->Getdata())
				return n;
			else if (key < n->Getdata())
				return n = n->GetLeft();
			else
				return n = n->GetRight();
		}

		// Ž���� ������ ��� NULL ��ȯ
		return NULL;
	}

	// ���� Ž�� Ʈ���� ���� ����
	void insert(BinaryNode* n)
	{
		if (n == NULL)
			return;
		// ���� Ʈ���� ��� ù��°�� ���Ե� �����Ͱ� ��Ʈ�� �ȴ�
		if (isEmpty())
			root = n;
		else insertRecur(root, n);
	}

	// void insert(BinaryNode* r,BinaryNode* n){}
	// ���� Ž�� Ʈ���� ���� �Լ�(��ȯ���� ���) // ���� ���굵 Ž�� ����� ���������� ��ȯ�� �ƴ� �ݺ��� �̿��Ͽ� ������ �����ϴ�
	// �Ϲ� �Լ��� ���� ���� , BinSrchTree�� ��� �Լ��� �־ ��

	// ���� Ž�� Ʈ���� ���Ҹ� �����ϱ� ���ؼ��� ���� Ž���� �Ͽ� ���� Ű ���� ���� ��尡 ������ Ȯ���Ͽ��� �ϰ�
	// Ž���� ������ ��ġ�� �ٷ� ���ο� ��带 �����ϴ� ��ġ�� �Ǳ� �����̴� 

	// ��� r�� ��Ʈ�� �ϴ� ����Ʈ���� ��� n�� �����ϴ� �Լ�
	void insertRecur(BinaryNode* r, BinaryNode* n)
	{
		// ��� n Ű�� ��Ʈ ����� r�� Ű ���� ������ �ߺ��� ��尡 �̹� Ʈ���� ������ // �� ��� �������� ����
		if (n->Getdata() == r->Getdata())
			return;
		// ��� nŰ�� ��Ʈ ����� r�� Ű ������ ���� ���
		else if (n->Getdata() < r->Getdata())
		{
			// ���� �ڽ� ��尡 ������ n�� r�� ���� �ڽ� ��尡 ��
			if (r->GetLeft() == NULL)
				r->SetLeft(n);
			// ���� �ڽ��� ������ insert�Լ��� ��ȯ������ ȣ��
			else
				insertRecur(r->GetLeft(), n);
		}
		// ��� nŰ�� ��Ʈ ����� r�� Ű ������ Ŭ ���
		else
		{
			// ������ �ڽ� ��尡 ������ n�� r�� ������ �ڽ� ��尡 ��
			if (r->GetRight() == NULL)
				r->SetRight(n);
			// ������ �ڽ��� ������ insert�Լ��� ��ȯ������ ȣ��
			else
				insertRecur(r->GetRight(), n);
		}
	}

	// ���� Ž�� Ʈ���� ���� ����
	void remove(int key)
	{
		if (isEmpty())
			return;

		BinaryNode* parent = NULL;
		BinaryNode* node = root;

		while (node != NULL && node->Getdata() != key)
		{
			parent = node;
			node = (key < node->Getdata()) ? node->GetLeft() : node->GetRight();
		}

		if (node == NULL)
		{
			printf(" Error: key is not in the tree\n");
			return;
		}
		else
			remove(parent, node);
	}
	void remove(BinaryNode* parent,BinaryNode* node)
	{
		// case 1: �����Ϸ��� ��尡 �ܸ� ����� ���
		if (node->isLeaf())
		{
			// node == root�ΰ�� => ������°� ��
			if (parent == NULL)
				root = NULL;
			// �ƴ� ��� => parent�� �ش� �ڽ��� NULL
			else
			{
				if (parent->GetLeft() == node)
					parent->SetLeft(NULL);
				else
					parent->SetRight(NULL);
			}
		}
		// case 2: �����Ϸ��� ��尡 �����̳� ������ �ڽĸ� ���� ���
		else if (node->GetLeft() == NULL || node->GetRight() == NULL)
		{
			// ������ ����� ������ �ڽ� ��� => child
			BinaryNode* child = (node->GetLeft() != NULL) ? node->GetLeft() : node->GetRight();

			// ������ ��尡 ��Ʈ�̸� => child�� ���ο� root�� ��
			if (node == root)
				root = child;
			// �ƴϸ� => �θ� ����� �ڽ����� �ڽ� ��� child�� ���� ����
			else
			{
				if (parent->GetLeft() == node)
					parent->SetLeft(child);
				else
					parent->SetRight(child);
			}
		}
		// case 3: �����Ϸ��� ��尡 �ΰ��� �ڽ��� ��� �ִ� ���
		else
		{
			// �����Ϸ��� ����� ������ ����Ʈ������ ���� ū ��带 Ž��
			// succp => �İ� ����� �θ� ���
			// succ => �İ� ���: ������ ����Ʈ������ ���� key�� ���� ���
			BinaryNode* succp = node;
			BinaryNode* succ = node->GetRight();

			// �İ� ��� Ž��
			while (succ->GetLeft() != NULL)
			{
				// �İ� ����� �θ� ���
				succp = succ;
				// �İ� ���
				succ = succ->GetLeft();
			}
			
			// �İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����
			if (succp->GetLeft() == succ)
				succp->SetLeft(succ->GetRight());
			// �İ� ��尡 ������ ����� �ٷ� ������ �ڽ��� ���
			else
				succp->SetRight(succ->GetRight());

			// �İ� ��� ������ ������ ��忡 ����
			node->Setdata(succ->Getdata());

			// ������ ��带 �İ� ���� ���� : �����δ� �İ� ��尡 ���ŵ�
			node = succ;
		}

		// �޸� ���� ����
		delete node;
	}
};