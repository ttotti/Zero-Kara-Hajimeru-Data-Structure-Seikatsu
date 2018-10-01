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

	// 중위 순회
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

	// 전위 순회
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

	// 후위 순회
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

	// 전체 노드의 개수
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	// 단말 노드의 개수
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		if (node->isLeaf())
			return 1;

		return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// 트리의 높이
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());

		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}

	// 레벨 순회 // 큐를 사용한다
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

			printf("[해제] ");
			delete node;
		}
	}

	// 수식트리 계산 함수
	int evaluate() { return evaluate(root); }
	// 순환 호출에 의해 node를 루트로 하는 수식 트리의 계산 함수
	int evaluate(BinaryNode* node)
	{
		// 공백 트리일 경우 0을 반환한다
		if (node == NULL)
			return 0;

		// 단말 노드이면 피연산자이고 따라서 그 노드의 값을 반환함
		if (node->isLeaf())
			return node->getdata();
		else
		{
			// 왼쪽 서브트리를 계산하여 결과를 op1에 저장 이때 순환 호출을 사용
			int op1 = evaluate(node->getLeft());
			// 오른쪽 서브트리를 계산하여 결과를 op2에 저장 이때 순환 호출을 사용
			int op2 = evaluate(node->getRight());

			// 현재 노드(연산자)의 연산자를 검사햐여 그에 따른 연산을 처리하여 결과를 반환함
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