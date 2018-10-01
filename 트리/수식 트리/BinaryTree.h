#pragma once

#include "BinaryNode.h"
#include "Queue.h"

class BinaryTree
{
	BinaryNode* root;

public:
	BinaryTree()
		:root(NULL) {}

	~BinaryTree()
	{
		deleteNode(root);
	}

	void setroot(BinaryNode* node) { root = node; }
	BinaryNode* getroot() { return root; }

	bool isEmpty() { return root == NULL; }

	// ���� ��ȸ
	void inorder() { printf("inorder : ");  inorder(root); }
	void inorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->getLeft() != NULL)
				inorder(node->getLeft());

			printf("inorder : ", node->getdata());

			if (node->getRight() != NULL)
				inorder(node->getRight());
		}
	}

	// ���� ��ȸ
	void preorder() { printf("preorder : "); preorder(root); }
	void preorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			printf("preorder : ", node->getdata());

			if (node->getLeft() != NULL)
				preorder(node->getLeft());

			if (node->getRight() != NULL)
				preorder(node->getRight());
		}
	}

	// ���� ��ȸ
	void postorder(){}
	void postorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->getLeft() != NULL)
				postorder(node->getLeft());

			if (node->getRight() != NULL)
				postorder(node->getRight());

			printf("postorder : ", node->getdata());
		}
	}

	// ��ü ����� ����
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	// �ܸ� ����� ����
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		if (node->isLeaf())
			return 1;

		return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// Ʈ���� ����
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());

		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}

	// ���� ��ȸ // ť�� ����Ѵ�
	void levelorder()
	{
		printf("levelorder : ");

		if (!isEmpty())
		{
			Queue q;

			q.enqueue(root);

			while(!q.isEmpty())
			{
				BinaryNode* n = q.dequeue();

				if (n != NULL)
				{
					printf("[%c]", n->getdata());

					if (n->getLeft() != NULL)
						q.enqueue(n->getLeft());

					if (n->getRight() != NULL)
						q.enqueue(n->getRight());
				}
			}
		}
	}

	void deleteNode(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->getLeft() != NULL)
				deleteNode(node->getLeft());

			if (node->getRight() != NULL)
				deleteNode(node->getRight());

			printf("[����] ");
			delete node;
		}
	}

	// ����Ʈ�� ��� �Լ�
	int evaluate() { return evaluate(root); }
	// ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ���� Ʈ���� ��� �Լ�
	int evaluate(BinaryNode* node)
	{
		// ���� Ʈ���� ��� 0�� ��ȯ�Ѵ�
		if (node == NULL)
			return 0;

		// �ܸ� ����̸� �ǿ������̰� ���� �� ����� ���� ��ȯ��
		if (node->isLeaf())
			return node->getdata();
		else
		{
			// ���� ����Ʈ���� ����Ͽ� ����� op1�� ���� �̶� ��ȯ ȣ���� ���
			int op1 = evaluate(node->getLeft());
			// ������ ����Ʈ���� ����Ͽ� ����� op2�� ���� �̶� ��ȯ ȣ���� ���
			int op2 = evaluate(node->getRight());

			// ���� ���(������)�� �����ڸ� �˻��Ῡ �׿� ���� ������ ó���Ͽ� ����� ��ȯ��
			switch (node->getdata())
			{
			case '+':
				return op1 + op2;
			case '-':
				return op1 - op2;
			case '*':
				return op1 * op2;
			case '/':
				return op1 / op2;
			}

			return 0;
		}
	}
};