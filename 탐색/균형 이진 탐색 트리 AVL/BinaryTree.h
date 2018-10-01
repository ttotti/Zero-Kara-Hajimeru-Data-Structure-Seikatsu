#pragma once

#include "BinaryNode.h"
#include "Queue.h"

// ����Ʈ�� Ŭ���� ����
class BinaryTree
{
protected:
	// ������ ����δ� ��Ʈ ��忡 ���� �����͸� ������ ��
	BinaryNode* root;

public:
	// ������ // ���ο� Ʈ�� ���� �� ��Ʈ�� NULL�� �Ǿ�� ��
	BinaryTree()
		:root(NULL) {}

	~BinaryTree()
	{
		deleteNode(root);
	}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* GetRoot() { return root; }

	// root�� NULL�̸� ���� Ʈ����
	bool isEmpty() { return root == NULL; }

	// ����Ʈ���� ��ȸ ����� ���� �߰� ����

	// ���� ��ȸ
	void inorder() { printf("\n     inorder: "); inorder(root); }
	void inorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			// ���� ����Ʈ�� ó��
			if (node->GetLeft() != NULL)
				inorder(node->GetLeft());

			// ���� ��� ó��
			printf("  [%d]  ", node->Getdata());

			// ������ ����Ʈ�� ��ȸ
			if (node->GetRight() != NULL)
				inorder(node->GetRight());
		}
	}

	// ��� Ŭ������ ��ȸ �Լ��� ������ ��� Ʈ�� Ŭ�������� ��ȸ �Լ��� �ʿ�����Ƿ�
	// ������ ���� ��忡�� ��ȸ �Լ��� ȣ���ϵ��� �Ѵ�
	//void inorder()
	//{
	//	printf("\n     inorder: ");
	//	if (!isEmpty()) root->inorder();
	//}

	// ���� ��ȸ
	void preorder() { printf("\n    preorder: "); preorder(root); }
	void preorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			printf("  [%d]  ", node->Getdata());

			if (node->GetLeft() != NULL)
				preorder(node->GetLeft());

			if (node->GetRight() != NULL)
				preorder(node->GetRight());
		}
	}

	// ���� ��ȸ
	void postorder() { printf("\n   postorder: "), postorder(root); }
	void postorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->GetLeft() != NULL)
				postorder(node->GetLeft());

			if (node->GetRight() != NULL)
				postorder(node->GetRight());

			printf("  [%d]  ", node->Getdata());
		}
	}

	// ���� ��ȸ�� ����Ͽ� �� �Ʒ������� ���ʷ� �����Ѵ�
	void deleteNode(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->GetLeft() != NULL)
				deleteNode(node->GetLeft());

			if (node->GetRight() != NULL)
				deleteNode(node->GetRight());

			printf("[����] \n");
			delete node;
		}
	}

	void levelorder()
	{
		printf("\n  levelorder: ");

		if (!isEmpty())
		{
			Queue q;

			q.enqueue(root);

			while (!q.isEmpty())
			{
				BinaryNode* n = q.dequeue();
				n->SetLink(NULL);

				if (n != NULL)
				{
					printf("  [%d]  ", n->Getdata());

					if (n->GetLeft() != NULL)
						q.enqueue(n->GetLeft());

					if (n->GetRight() != NULL)
						q.enqueue(n->GetRight());
				}
			}
		}

		printf("\n");
	}

	// Ʈ���� ��� ���� ���ϱ�
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	// ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� ��� �� ��� �Լ�
	int getCount(BinaryNode* node)
	{
		// ���� Ʈ���̸� 0�� ��ȯ�ϰ�
		if (node == NULL)
			return 0;

		// �⺻������ ����� ������ ���� ���ؼ��� Ʈ�� ���� ������ ��ü������ ��ȸ�Ͽ��� �Ѵ�
		// Ʈ���� ����� ������ ���� ����Ʈ���� ��� ������ ������ ����Ʈ���� ��� ������ ��Ʈ ��带 ���ϸ� �ȴ�
		// ����Ʈ���� ��� ������ ��ȯ ȣ��� ����Ѵ�
		return 1 + getCount(node->GetLeft()) + getCount(node->GetRight());
	}

	// �ܸ� ��� ���� ���ϱ�
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	// ��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� �ܸ� ��� �� ��� �Լ�
	int getLeafCount(BinaryNode* node)
	{
		// ���� Ʈ���̸� 0�� ��ȯ�ϰ�
		if (node == NULL)
			return 0;
		// �ܸ� Ʈ���̸� 1�� ��ȯ��
		// isLeft() : ���� ��尡 �ܸ� ��������� �˻��ϴ� �Լ� (BinaryNode.h 38��)
		if (node->isLeaf())
			return 1;
		else
			return getLeafCount(node->GetLeft()) + getLeafCount(node->GetRight());
	}

	// Ʈ���� ���� ���ϱ�
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	// Ʈ���� ���̴� ���� ����Ʈ���� ������ ����Ʈ�� �߿��� �� ���� Ʈ���� ���� ã�´�
	int getHeight(BinaryNode* node)
	{
		// ���� Ʈ���̸� 0�� ��ȯ�ϰ�
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->GetLeft());
		int hRight = getHeight(node->GetRight());

		// hLeft�� hRight �߿��� ū ���� �����ϰ� 1�� ���� ���� ��ȯ�Ѵ�
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
};