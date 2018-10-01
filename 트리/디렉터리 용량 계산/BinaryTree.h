#pragma once

#include "BinaryNode.h"
#include "Queue.h"

class BinaryTree
{
	BinaryNode* root;

public:
	BinaryTree()
		:root(NULL)
	{

	}

	~BinaryTree()
	{
		deleteNode(root);
	}

	void SetTree(BinaryNode* node) { root = node; }
	BinaryNode* GetTree() { return root; }

	bool isEmpty() { root == NULL; }

	// ���� ��ȸ
	void inorder() { printf("inorder : "); inorder(root); }
	void inorder(BinaryNode* node)
	{
		if (!isEmpty())
		{
			if (node->GetLeft() != NULL)
				inorder(node->GetLeft());

			printf("inorder : ", node->Getdata());

			if (node->GetRight() != NULL)
				inorder(node->GetRight());
		}
	}

	// ���� ��ȸ
	void preorder() { printf("preorder : "); preorder(root); }
	void preorder(BinaryNode* node)
	{
		if (!isEmpty())
		{
			printf("preorder : ", node->Getdata());

			if (node->GetLeft() != NULL)
				preorder(node->GetLeft());

			if (node->GetRight() != NULL)
				preorder(node->GetRight());
		}
	}

	// ���� ��ȸ
	void postorder(BinaryNode* node)
	{
		if (!isEmpty())
		{
			if (node->GetLeft() != NULL)
				postorder(node->GetLeft());

			if (node->GetRight() != NULL)
				postorder(node->GetRight());

			printf("postorder : ", node->Getdata());
		}
	}

	// Ʈ�� ��� ����
	int GetCount() { isEmpty() ? 0 : GetCount(root); }
	int GetCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + GetCount(node->GetLeft()) + GetCount(node->GetRight());
	}

	// �ܸ� ��� ����
	int GetLeafCount() { return isEmpty() ? 0 : GetLeafCount(root); }
	int GetLeafCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		if (node->isLeaf())
			return 1;

		return GetLeafCount(node->GetLeft()) + GetLeafCount(node->GetRight());
	}

	// ���� ��ȸ
	void levelorder() { printf("levelorder : "); levelorder(root); }
	void levelorder(BinaryNode* node)
	{
		printf("levelorder : ");

		if (!isEmpty())
		{
			Queue q;

			q.enqueue(node);

			while (!q.isEmpty())
			{
				BinaryNode* n = q.dequeue();

				if (n != NULL)
				{
					printf("[%c]", n->Getdata());

					if (n->GetLeft() != NULL)
						q.enqueue(n->GetLeft());

					if (n->GetRight() != NULL)
						q.enqueue(n->GetRight());
				}
			}
		}
	}

	void deleteNode(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->GetLeft() != NULL)
				deleteNode(node->GetLeft());

			if (node->GetRight() != NULL)
				deleteNode(node->GetRight());

			printf("[����] ");
			delete node;
		}
	}

	// ���͸� �뷮 ��� �Լ�
	int calcSize() { return calcSize(root); }
	// ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� Ʈ���� ��ü �뷮 ��� �Լ�
	// ����Ʈ���� ����ϹǷ� �ϳ��� �����͸� �ȿ� �ٸ� ���͸��� 2���� �ʰ��ϸ� �� �ȴ�
	// ���� ���� ���丮�� �뷮�� ��� ����� ������ ��Ʈ ��Ʈ���� �뷮�� ����Ͽ��� �Ѵ�
	// ���� ���� ��ȸ�� ����Ͽ��� �Ѵ�
	int calcSize(BinaryNode* node)
	{
		// ���� ����̸� 0�� ��ȯ
		if (node == NULL)
			return 0;

		// ���� ����Ʈ���� ������ ����Ʈ���� �뷮�� ���� ���� ���ϰ� ���⿡ ���� ���͸��� �뷮�� ���� ���� ��ȯ�Ѵ�
		return node->Getdata() + calcSize(node->GetLeft()) + calcSize(node->GetRight());
	}
};