#pragma once

#include "BinSrchTree.h"

// ���� ���� Ž�� Ʈ���ε� ������ �� �ִ�
// ���� Ž���� ���� Ž�� Ʈ���� �ٺ������� ���� ������ ���� Ž�� ������ Ž���� �ɸ��� �ð��� O(log2 n) �� �����ϴ�
// �� ���� ���̴� �ڷ��� ���԰� ������ ���Ǽ��� �ִ�

// ���� Ž������ �ڷ�� �迭�� ����Ǿ� �����Ƿ� ���԰� ������ ����� �����
// ��, �ʿ� �ڷḦ �����ϰų� ������ �� ���ʿ��� �׸���� ���� �̵��� �ʿ��ϴ�

// �ݸ鿡 ���� ���� Ž�� Ʈ���� �����ϸ� O(log2 n) �ð��� ���԰� ������ �����ϴ�
// ���� ���԰� ������ ����� �̷�����ٸ� �ݵ�� ���� Ž�� Ʈ���� ����Ͽ��� �Ѵ�

// ���� Ž�� Ʈ���� ���� ���� Ʈ���̸� O(log2 n)�� Ž�� ���� �ð� ���⵵�� ���´�
// �׷��� ���� Ʈ���� �ƴ� ��� Ʈ���� ��쿡�� Ž���� �ð� ���⵵�� O(n) ���� �������� �ȴ�

// ���� ���� Ž�� Ʈ�������� ������ �����ϴ� ���� �������� �߿��ϴ�
// ���⼭�� ���� Ž�� Ʈ���� ������ ������ �����ϵ��� �ϴ� ����� ���� ���캻��
// �̵��� ����� �����ϱ� ������ ��� ������ �ٷ����� �ʰ� AVL Ʈ���� ���ؼ��� �˾ƺ���

// AVL Ʈ����
// AVL Ʈ���� Adelson-Velskii �� Landis �� ���� ���ȵ� Ʈ����
// �� ��忡�� ���� ����Ʈ���� ���̿� ������ ����Ʈ���� ���� ���̰� 1 ������ ���� Ž�� Ʈ���� ���Ѵ�
// �� Ʈ���� Ʈ���� ����� ���·� �Ǹ� ������ ������ ���ġ�Ͽ� ���� ���·� �����
// AVL Ʈ���� �׻� ���� Ʈ���� �����ϱ� ������ O(log2 n) �� Ž�� �ð��� �����Ѵ�, ���԰� �������굵 O(log2 n) �ð��ȿ� �� �� �ִ�

// AVL Ʈ������ ������ ������ ���� ���� 4������ Ÿ���� �ִ�
// ���� ���Ե� ��� N�� ���� ���� �����鼭 ���� �μ��� +-2�� �� ���� ��带 A��� ����
/*
	1. LL Ÿ�� - N�� A�� ���� ����Ʈ���� ���� ����Ʈ���� ���Եȴ�
	2. LR Ÿ�� - N�� A�� ���� ����Ʈ���� ������ ����Ʈ���� ���Եȴ�
	3. RR Ÿ�� - N�� A�� ������ ����Ʈ���� ������ ����Ʈ���� ���Եȴ�
	3. RL Ÿ�� - N�� A�� ������ ����Ʈ���� ���� ����Ʈ���� ���Եȴ�
*/

// LL�� RR�� ��Ī�̰� ���� LR�� RL�� ��Ī�̴�
// ���� Ʈ���� �ٽ� ������Ų��, ������ ������ ��쿡 ���Ͽ� ���� Ʈ���� �ٽ� ����� ����̴�
/*
	1. LL ȸ�� - A���� N������ ��λ��� ������ ���������� ȸ����Ų��
	2. LR ȸ�� - A���� N������ ��λ��� ������ ���� - ���������� ȸ����Ų��
	3. RR ȸ�� - A���� N������ ��λ��� ������ �������� ȸ����Ų��
	4. RL ȸ�� - A���� N������ ��λ��� ������ ������ - �������� ȸ����Ų��
*/

// �ѹ��� ȸ����Ű�� ���� �ܼ� ȸ��(single rotation) �̶�� �ϴµ� LL ȸ��, RR ȸ���� ���⿡ ���Ѵ�
// �� ���, Ž�� ������ �����ϸ鼭 �θ�� �ڽ��� ��ġ�� ��ȯ�ϸ� �ȴ�

// �� ���� ȸ���� �ʿ��� ���� ���� ȸ��(double rotation) �̶�� �ϸ� LR ȸ��, RL ȸ���� ���⿡ ���Ѵ�
// ���������� LL ȸ���� RR ȸ���� ���⸸ �ݴ��̰� ��Ī�̸� LR ȸ���� RL ȸ���� ���������̴�

class AVLTree :public BinSrchTree
{
public:
	int getHeightDiff(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->GetLeft());
		int hRight = getHeight(node->GetRight());

		return hLeft - hRight;
	}

	// LL ȸ��
	BinaryNode* rotateLL(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetLeft();

		parent->SetLeft(child->GetRight());
		child->SetRight(parent);

		return child;
	}

	// RR ȸ��
	BinaryNode* rotateRR(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetRight();

		parent->SetRight(child->GetLeft());
		child->SetLeft(parent);

		return child;
	}

	// RL ȸ��
	BinaryNode* rotateRL(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetRight();

		parent->SetRight(rotateLL(child));

		return rotateRR(parent);
	}

	// LR ȸ��
	BinaryNode* rotateLR(BinaryNode* parent)
	{
		BinaryNode* child = parent->GetLeft();

		parent->SetLeft(rotateRR(child));

		return rotateLL(parent);
	}

	BinaryNode* reBalance(BinaryNode* parent)
	{
		int hDiff = getHeightDiff(parent);

		if (hDiff > 1)
		{
			if (getHeightDiff(parent->GetLeft()) > 0)
				parent = rotateLL(parent);
			else
				parent = rotateLR(parent);
		}
		else if (hDiff < -1)
		{
			if (getHeightDiff(parent->GetRight()) < 0)
				parent = rotateRR(parent);
			else
				parent = rotateRL(parent);
		}

		return parent;
	}

	// 
	BinaryNode* insertAVL(BinaryNode* parent, int data)
	{
		if (data < parent->Getdata())
		{
			if (parent->GetLeft() != NULL)
				parent->SetLeft(insertAVL(parent->GetLeft(), data));
			else
				parent->SetLeft(new BinaryNode(data));

			return reBalance(parent);
		}
		else if (data > parent->Getdata())
		{
			if (parent->GetRight() != NULL)
				parent->SetRight(insertAVL(parent->GetRight(), data));
			else
				parent->SetRight(new BinaryNode(data));

			return reBalance(parent);
		}
		else
		{
			printf("�ߺ��� Ű ����\n");
			return NULL;
		}
	}

	void insert(int data)
	{
		if (isEmpty())
			root = new BinaryNode(data);
		else
			root = insertAVL(root, data);
	}
};