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

	// 중위 순회
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

	// 전위 순회
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

	// 후위 순회
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

	// 트리 노드 개수
	int GetCount() { isEmpty() ? 0 : GetCount(root); }
	int GetCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + GetCount(node->GetLeft()) + GetCount(node->GetRight());
	}

	// 단말 노드 개수
	int GetLeafCount() { return isEmpty() ? 0 : GetLeafCount(root); }
	int GetLeafCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		if (node->isLeaf())
			return 1;

		return GetLeafCount(node->GetLeft()) + GetLeafCount(node->GetRight());
	}

	// 레벨 순회
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

			printf("[해제] ");
			delete node;
		}
	}

	// 디렉터리 용량 계산 함수
	int calcSize() { return calcSize(root); }
	// 순환 호출에 의해 node를 루트로 하는 트릴의 전체 용량 계산 함수
	// 이진트리를 사용하므로 하나의 디텍터리 안에 다른 디렉터리가 2개를 초과하면 안 된다
	// 먼저 서브 디렉토리의 용량을 모두 계산한 다음에 루트 디렉트리의 용량을 계산하여야 한다
	// 따라서 후위 순회를 사용하여야 한다
	int calcSize(BinaryNode* node)
	{
		// 공백 노드이면 0을 반환
		if (node == NULL)
			return 0;

		// 왼쪽 서브트리와 오른쪽 서브트리의 용량을 각각 구해 더하고 여기에 현재 디렉터리의 용량을 더한 값을 반환한다
		return node->Getdata() + calcSize(node->GetLeft()) + calcSize(node->GetRight());
	}
};