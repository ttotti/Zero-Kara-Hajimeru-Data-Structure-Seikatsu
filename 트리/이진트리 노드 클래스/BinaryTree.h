#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"

// ����Ʈ�� Ŭ���� ����
class BinaryTree
{
	// ������ ����δ� ��Ʈ ��忡 ���� �����͸� ������ ��
	BinaryNode* root;

public:
	// ������ // ���ο� Ʈ�� ���� �� ��Ʈ�� NULL�� �Ǿ�� ��
	BinaryTree()
		:root(NULL){}

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
			if (node->getLeft() != NULL)
				inorder(node->getLeft());

			// ���� ��� ó��
			printf("  [%c]  ", node->getData());

			// ������ ����Ʈ�� ��ȸ
			if (node->getRight() != NULL)
				inorder(node->getRight());
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
	void preorder(){ printf("\n    preorder: "); preorder(root); }
	void preorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			printf("  [%c]  ", node->getData());

			if (node->getLeft() != NULL) 
				preorder(node->getLeft());

			if (node->getRight() != NULL) 
				preorder(node->getRight());
		}
	}

	// ���� ��ȸ
	void postorder() { printf("\n   postorder: "), postorder(root); }
	void postorder(BinaryNode* node)
	{
		if (node != NULL)
		{
			if (node->getLeft() != NULL)
				postorder(node->getLeft());

			if (node->getRight() != NULL)
				postorder(node->getRight());

			printf("  [%c]  ", node->getData());
		}
	}

	// ���� ��ȸ�� ����Ͽ� �� �Ʒ������� ���ʷ� �����Ѵ�
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

	// ���� ��ȸ
	// ���� ��ȸ�� �� ��带 ���� ������ �˻��ϴ� ��ȸ ����̴�
	// ��Ʈ ����� ������ 1�̰� �Ʒ��� ���������� ������ �����Ѵ�
	// ������ ������ ��쿡�� �¿��� ��� �湮�Ѵ�

	// �տ����� �� ���� ǥ�� ��ȸ ����� ��ȯ(���ȣ��)�� ����ϹǷ� ���������� ������ ���Ǿ��ٰ� �� �� �ִ�
	// ���� ��ȸ�� ť�� ����Ѵ�
	void levelorder()
	{
		printf("\n  levelorder: ");

		if (!isEmpty())
		{
			// ť�� �����
			CircularQueue q;

			// Ʈ���� ��Ʈ�� ť�ȿ� �ִ´�
			q.enqueue(root);

			// ť�ȿ� �����Ͱ� ������ ���� �� ����
			while (!q.isEmpty())
			{
				// ť���� �� �տ��ִ� �����͸� ������
				BinaryNode* n = q.dequeue();

				// ���� �����Ͱ� NULL���� �ƴҰ��
				if (n != NULL)
				{
					// ����ϰ�
					printf("  [%c]  ", n->getData());
					// ���ʳ��� �����ʳ�带 �˻��Ͽ� ť�� �ִ´�
					if (n->getLeft() != NULL)
						q.enqueue(n->getLeft());
					if (n->getRight() != NULL)
						q.enqueue(n->getRight());
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
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
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
		if (node->isLeat())
			return 1;
		else
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// Ʈ���� ���� ���ϱ�
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	// Ʈ���� ���̴� ���� ����Ʈ���� ������ ����Ʈ�� �߿��� �� ���� Ʈ���� ���� ã�´�
	int getHeight(BinaryNode* node)
	{
		// ���� Ʈ���̸� 0�� ��ȯ�ϰ�
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());

		// hLeft�� hRight �߿��� ū ���� �����ϰ� 1�� ���� ���� ��ȯ�Ѵ�
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
};